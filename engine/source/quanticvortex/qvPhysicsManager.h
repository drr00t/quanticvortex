
#ifndef __PHYSICS_MANAGER_H_
#define __PHYSICS_MANAGER_H_

#include "qvActorTypes.h"
#include "qvIPhysicsManager.h"


class btBroadphaseInterface;
class btCollisionDispatcher;
class btCollisionObject;
class btConstraintSolver;
class btDefaultCollisionConfiguration;
class btDynamicsWorld;



namespace qv
{
	class IEngineManager;

	namespace gaming
	{
		class IActor;
	}

    namespace physics    
	{
        //typedef SharedPtr<PhysicsObject> PhysicsObjectPtr;
		//typedef std::map< u32, PhysicsObjectPtr> PhysicsActorMap;
        typedef list<btCollisionObject*> CollisionObjectsList;

		class PhysicsManager: public IPhysicsManager
        {
        public:

			PhysicsManager(IEngineManager* engineManager);
			~PhysicsManager();

            virtual bool initialize();

			virtual bool finalize();

			virtual void update( u32 elapsedTimeMs);

			//// Initialization of Physics Objects
            //virtual void addShape(f32 radius, gaming::AI_ACTOR_ID *actorId, scene::ISceneNode* sceneNode, f32 specificGravity);
            virtual void addShape(f32 radius, gaming::IActor *actor, f32 specificGravity);
			//virtual void VAddSphere(float radius, IActor *actor, float specificGravity, enum PhysicsMaterial mat)=0;
			//virtual void addSphere(f32 radius, gaming::AI_ACTOR_ID *actorId, f32 specificGravity);
            virtual void addSphere(f32 radius, gaming::IActor *actor, f32 specificGravity);
			
			//virtual void VAddBox(const Vec3& dimensions, IActor *gameActor, float specificGravity, enum PhysicsMaterial mat) = 0;
			virtual void addBox(const vector3df& dimensions, gaming::IActor *actor, f32 specificGravity);
			
			//virtual void VAddPointCloud(Vec3 *verts, int numPoints, IActor *gameActor, float specificGravity, enum PhysicsMaterial mat)=0;
			virtual void addConvexHull(vector3df *verts, s32 numPoints, gaming::IActor *actor, f32 specificGravity);


			//virtual void VRemoveActor(ActorId id)=0;

			//// Debugging
			//virtual void VRenderDiagnostics() = 0;

			//// Physics world modifiers
			//virtual void VCreateTrigger(const Vec3 &pos, const float dim, int triggerID)=0;
			//virtual void VApplyForce(const Vec3 &dir, float newtons, ActorId aid)=0;
			//virtual void VApplyTorque(const Vec3 &dir, float newtons, ActorId aid)=0;
			//virtual bool VKinematicMove(const Mat4x4 &mat, ActorId aid)=0;
			//
			//// Physics actor states
			//virtual void VRotateY(ActorId actorId, float angleRadians, float time) = 0;
			//virtual float VGetOrientationY(ActorId actorId) = 0;
			//virtual void VStopActor(ActorId actorId) = 0;
			//virtual void VSetVelocity(ActorId actorId, const Vec3& vel) = 0;
			//virtual void VTranslate(ActorId actorId, const Vec3& vec) = 0;
		private:
			IEngineManager* mEngineManager;
            btDynamicsWorld* mBulletDynamicsWorld;
            btBroadphaseInterface* mBulletBroadphaseInterface;
            btCollisionDispatcher* mBulletCollisionDispatcher;
            btDefaultCollisionConfiguration* mBulletDefaultCollisionConfiguration;
            btConstraintSolver* mBulletConstraintSolver;
            CollisionObjectsList mCollisionObjectsList;

			f32 mTimeUpdate;
			//PhysicsActorMap mPhysicsActors;
            
            //static void internalTickCallback( btDynamicsWorld* const world, btScalar const timeStep);

		};

        //typedef SharedPtr<IActor> ActorPtr;
    }
}

#endif

