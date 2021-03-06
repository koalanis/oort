#pragma once

#include <btBulletDynamicsCommon.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include <OgreWindowEventUtilities.h>
#include <OgreRenderTargetListener.h>
#include <deque>

class GameObject;

class Simulator { 
protected: 
       btDefaultCollisionConfiguration* collisionConfiguration; 
       btCollisionDispatcher* dispatcher; 
       btBroadphaseInterface* overlappingPairCache; 
       btSequentialImpulseConstraintSolver* solver;
       btDiscreteDynamicsWorld* dynamicsWorld;
       btAlignedObjectArray<btCollisionShape*> collisionShapes;
       std::deque<GameObject*> objList; 
public: 
       Simulator(); 
       ~Simulator(); 

       void addObject(GameObject* o); 
       bool removeObject(GameObject* o); 
       void stepSimulation(const Ogre::Real elapsedTime, int maxSubSteps = 1, const Ogre::Real fixedTimestep = 1.0f/60.0f); 
};
