
#ifndef __PHYSICSMANAGER_H_
#define __PHYSICSMANAGER_H_

#include "qvActorTypes.h"
#include "qvIPhysicsManager.h"

#include "btBulletDynamicsCommon.h"
#include "btBulletCollisionCommon.h"


namespace
{
	void quaternionToEuler(const btQuaternion &TQuat, btVector3 &TEuler) 
	{
		btScalar W = TQuat.getW();
		btScalar X = TQuat.getX();
		btScalar Y = TQuat.getY();
		btScalar Z = TQuat.getZ();

		float WSquared = W * W;
		float XSquared = X * X;
		float YSquared = Y * Y;
		float ZSquared = Z * Z;

		TEuler.setX(atan2f(2.0f * (Y * Z + X * W), -XSquared - YSquared + ZSquared + WSquared));
		TEuler.setY(asinf(-2.0f * (X * Z - Y * W)));
		TEuler.setZ(atan2f(2.0f * (X * Y + Z * W), XSquared - YSquared - ZSquared + WSquared));
		
		TEuler *= core::RADTODEG;
	}
}

namespace qv
{
	class IEngineManager;

	namespace gaming
	{
		class IActor;
	}

    namespace physics    
	{
		//void quaternionToEuler(const btQuaternion &TQuat, btVector3 &TEuler) 
		//{
		//	btScalar W = TQuat.getW();
		//	btScalar X = TQuat.getX();
		//	btScalar Y = TQuat.getY();
		//	btScalar Z = TQuat.getZ();

		//	float WSquared = W * W;
		//	float XSquared = X * X;
		//	float YSquared = Y * Y;
		//	float ZSquared = Z * Z;

		//	TEuler.setX(atan2f(2.0f * (Y * Z + X * W), -XSquared - YSquared + ZSquared + WSquared));
		//	TEuler.setY(asinf(-2.0f * (X * Z - Y * W)));
		//	TEuler.setZ(atan2f(2.0f * (X * Y + Z * W), XSquared - YSquared - ZSquared + WSquared));
		//	
		//	TEuler *= core::RADTODEG;
		//}

        //void vector3dfToBtVector3( vector3df& vec3In, btVector3& btVec3Out)
        //{
        //    btVec3Out.setValue(vec3In.X, vec3In.Y, vec3In.Z );
        //}
        //
        //void btVector3ToVector3df( btVector3& btVec3In, vector3df& vec3Out)
        //{
        //    vec3Out.set(btVec3In.x(), btVec3In.y(), btVec3In.z());
        //}

        //void matrix4ToBtTransform( matrix4& matx4In, btTransform& btTransformOut)
        //{
	       // // convert from Mat4x4 (GameCode) to btTransform (Bullet)
	       // btMatrix3x3 bulletRotation;
	       // btVector3 bulletPosition;
        //	
	       // // copy rotation matrix
	       // for ( int row=0; row<3; ++row )
		      //  for ( int column=0; column<3; ++column )
        //            bulletRotation[row][column] = matx4In( row, column); // note the reversed indexing (row/column vs. column/row)
			     //                                                     //  this is because Mat4x4s are row-major matrices and
			     //                                                     //  btMatrix3x3 are column-major.  This reversed indexing
			     //                                                     //  implicitly transposes (flips along the diagonal) 
			     //                                                     //  the matrix when it is copied.
        //    btTransformOut.setBasis( bulletRotation);

	       // // copy position
	       // for ( int column=0; column<3; ++column )
		      //  bulletPosition[column] = matx4In(3, column);
        //		
        //    btTransformOut.setOrigin( bulletPosition );

        //}

        //void btTransformToMatrix4( btTransform& btTransformIn, matrix4& matx4Out )
        //{
        //    matx4Out.makeIdentity();

	       // // convert from btTransform (Bullet) to Mat4x4 (GameCode)
	       // btMatrix3x3 const & bulletRotation = btTransformIn.getBasis();
	       // btVector3 const & bulletPosition = btTransformIn.getOrigin();
        //	
	       // // copy rotation matrix
	       // for ( int row=0; row<3; ++row )
		      //  for ( int column=0; column<3; ++column )
        //            matx4Out(row, column) = bulletRotation[column][row]; 
			     //             // note the reversed indexing (row/column vs. column/row)
			     //             //  this is because Mat4x4s are row-major matrices and
			     //             //  btMatrix3x3 are column-major.  This reversed indexing
			     //             //  implicitly transposes (flips along the diagonal) 
			     //             //  the matrix when it is copied.
        //	
	       // // copy position
	       // for ( int column=0; column<3; ++column )
		      //  matx4Out(3, column) = bulletPosition[column];
        //}

 

        //class _QUANTICVORTEX_API PhysicsObject: public IReferenceCounted
        //{
        //private:
        //    btRigidBody* mBody;

        //public:
        //    PhysicsObject();
        //    virtual ~PhysicsObject();
        //};

        //typedef SharedPtr<PhysicsObject> PhysicsObjectPtr;
		//typedef std::map< u32, PhysicsObjectPtr> PhysicsActorMap;

		///This class sychronizes the world transform between Bullet rigid bodies and their accompanying Irrlicht nodes
		struct ActorMotionState : public btDefaultMotionState
		{

			const gaming::AI_ACTOR_ID* mActorID;
			vector3df mPosition;
			vector3df mRotation;

			ActorMotionState(const gaming::AI_ACTOR_ID* actorID)
				:mActorID(actorID)
			{
			}
			///synchronizes world transform from user to physics
			virtual void getWorldTransform(btTransform& centerOfMassWorldTrans ) const 
			{
				centerOfMassWorldTrans = m_graphicsWorldTrans;
			}

			///synchronizes world transform from physics to user
			///Bullet only calls the update of worldtransform for active objects
			virtual void setWorldTransform(const btTransform& centerOfMassWorldTrans)
			{
				//numUpdatedBodies++;
				m_startWorldTrans = centerOfMassWorldTrans;
				m_graphicsWorldTrans = centerOfMassWorldTrans;

				const btVector3& Point = centerOfMassWorldTrans.getOrigin();
				//mPosition = vector3df((f32)Point[0], (f32)Point[1], (f32)Point[2])/physicsWorldScaling);

				// Set rotation
				btVector3 EulerRotation;
				::quaternionToEuler(centerOfMassWorldTrans.getRotation(), EulerRotation);
				mRotation = vector3df(EulerRotation[0], EulerRotation[1], EulerRotation[2]);
			}
		};

		class PhysicsManager: public IPhysicsManager
        {
        public:

			PhysicsManager(IEngineManager* engineManager);
			~PhysicsManager();

            virtual bool initialize();

			virtual bool finalize();

			virtual void update( u32 elapsedTimeMs);

			//// Initialization of Physics Objects
			virtual void addShape(f32 radius, gaming::IActor *actor, f32 specificGravity);

			//virtual void VAddSphere(float radius, IActor *actor, float specificGravity, enum PhysicsMaterial mat)=0;
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


			f32 mTimeUpdate;
			//PhysicsActorMap mPhysicsActors;
            
            //static void internalTickCallback( btDynamicsWorld* const world, btScalar const timeStep);

		};

        //typedef SharedPtr<IActor> ActorPtr;
    }
}

#endif

