
#ifndef __PHYSICSMANAGER_H_
#define __PHYSICSMANAGER_H_

#include "qvPrerequisites.h"
//#include "qvSharedPtr.h"

#include "btBulletDynamicsCommon.h"
#include "btBulletCollisionCommon.h"


using namespace qv;


namespace qv
{
    namespace physics    
	{
        inline void vector3dfToBtVector3( vector3df& vec3In, btVector3& btVec3Out)
        {
            btVec3Out.setValue(vec3In.X, vec3In.Y, vec3In.Z );
        };
        
        inline void btVector3ToVector3df( btVector3& btVec3In, vector3df& vec3Out)
        {
            vec3Out.set(btVec3In.x(), btVec3In.y(), btVec3In.z());
        };

        inline void matrix4ToBtTransform( matrix4& matx4In, btTransform& btTransformOut)
        {
	        // convert from Mat4x4 (GameCode) to btTransform (Bullet)
	        btMatrix3x3 bulletRotation;
	        btVector3 bulletPosition;
        	
	        // copy rotation matrix
	        for ( int row=0; row<3; ++row )
		        for ( int column=0; column<3; ++column )
                    bulletRotation[row][column] = matx4In( row, column); // note the reversed indexing (row/column vs. column/row)
			                                                          //  this is because Mat4x4s are row-major matrices and
			                                                          //  btMatrix3x3 are column-major.  This reversed indexing
			                                                          //  implicitly transposes (flips along the diagonal) 
			                                                          //  the matrix when it is copied.
            btTransformOut.setBasis( bulletRotation);

	        // copy position
	        for ( int column=0; column<3; ++column )
		        bulletPosition[column] = matx4In(3, column);
        		
            btTransformOut.setOrigin( bulletPosition );

        };

        inline void btTransformToMatrix4( btTransform& btTransformIn, matrix4& matx4Out )
        {
            matx4Out.makeIdentity();

	        // convert from btTransform (Bullet) to Mat4x4 (GameCode)
	        btMatrix3x3 const & bulletRotation = btTransformIn.getBasis();
	        btVector3 const & bulletPosition = btTransformIn.getOrigin();
        	
	        // copy rotation matrix
	        for ( int row=0; row<3; ++row )
		        for ( int column=0; column<3; ++column )
                    matx4Out(row, column) = bulletRotation[column][row]; 
			                  // note the reversed indexing (row/column vs. column/row)
			                  //  this is because Mat4x4s are row-major matrices and
			                  //  btMatrix3x3 are column-major.  This reversed indexing
			                  //  implicitly transposes (flips along the diagonal) 
			                  //  the matrix when it is copied.
        	
	        // copy position
	        for ( int column=0; column<3; ++column )
		        matx4Out(3, column) = bulletPosition[column];
        };

 

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

        class PhysicsManager: public irr::IReferenceCounted
        {
		private:
            btDynamicsWorld* mBulletDynamicsWorld;
            btBroadphaseInterface* mBulletBroadphaseInterface;
            btCollisionDispatcher* mBulletCollisionDispatcher;
            btDefaultCollisionConfiguration* mBulletDefaultCollisionConfiguration;
            btConstraintSolver* mBulletConstraintSolver;


			f32 mTimeUpdate;
			//PhysicsActorMap mPhysicsActors;
            
            static void internalTickCallback( btDynamicsWorld* const world, btScalar const timeStep);

        public:
			PhysicsManager(IrrlichtDevice* device);
			~PhysicsManager();

			void update( u32 elapsedTimeMs);

            bool initialize();

			//// Initialization of Physics Objects
			//virtual void VAddSphere(float radius, IActor *actor, float specificGravity, enum PhysicsMaterial mat)=0;
			//virtual void VAddBox(const Vec3& dimensions, IActor *gameActor, float specificGravity, enum PhysicsMaterial mat) = 0;
			//virtual void VAddPointCloud(Vec3 *verts, int numPoints, IActor *gameActor, float specificGravity, enum PhysicsMaterial mat)=0;
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
        };

        //typedef SharedPtr<IActor> ActorPtr;
    }
}
#endif

