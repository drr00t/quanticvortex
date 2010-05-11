
#ifndef __PHYSICS_MANAGER_H_
#define __PHYSICS_MANAGER_H_

// engine headers
#include "qvCompileConfig.h"
#include "qvActor.h"
#include "qvActorTypes.h"
#include "qvTypes.h"




//#include "LinearMath/btQuaternion.h"
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "BulletCollision/CollisionDispatch/btGhostObject.h"
#include "BulletCollision/BroadphaseCollision/btOverlappingPairCallback.h"

#include "qvActorTransformationChangedEventArgs.h"


namespace qv
{
namespace events
{
    class EventManager;
}

}

namespace qv
{
namespace physics
{

typedef btAlignedObjectArray<btCollisionObject*> CollisionObjectsList;
/// aligned container for collision objects

typedef btAlignedObjectArray<btCollisionShape*> CollisionShapes;
/// aligned container to collision shape added to physics manager
  

class _QUANTICVORTEX_API_ PhysicsManager
    /// physics manager object, it will be responsable by all game physics
{
    public:

class ActorMotionState: public btMotionState
    /// actor motion state, is object make transition of render view
    /// game objects and physics simulation
{
public:
    ActorMotionState(qv::events::EventManager* eventManager, u32 actorHashId)
    :mGameActor(gameActor), mEventManager(eventManager)
    {
    }

    virtual void getWorldTransform(btTransform& centerOfMassWorldTrans) const 
    {
        centerOfMassWorldTrans = mActorTransform;
    }

    virtual void setWorldTransform(const btTransform& centerOfMassWorldTrans) 
    {
        mActorTransform = centerOfMassWorldTrans;

//        mEventManager->enqueue(new ActorTransformationChangedEventArgs(actorHashId, centerOfMassWorldTrans))
        
//		const btVector3& position = centerOfMassWorldTrans.getOrigin();
//		mGameActor->setPosition(irr::core::vector3df((irr::f32)position[0], (irr::f32)position[1], (irr::f32)position[2]));
//
//		// Set rotation
//		btVector3 eulerRotation;
//		quaternionToEuler(centerOfMassWorldTrans.getRotation(), eulerRotation);
//		mGameActor->setRotation(core::vector3df(eulerRotation[0], eulerRotation[1], eulerRotation[2]));
    }

    protected:
        btTransform mActorTransform;
        qv::events::EventManager* mEventManager;

};

    PhysicsManager(qv::events::EventManager* eventManager);
    ~PhysicsManager();

    void initialize();
    /// physics manager initialization

    void finalize();
    /// physics manager cleanup

    void update( qv::u32 elapsedTimeMs);
    /// physics tick update with game time

    void addSphere(qv::real radius, qv::gaming::Actor *actor, qv::real specificGravity);
    /// add a sphere as physics body of an actor

    void addBox(const btVector3& dimensions, qv::gaming::Actor *actor, qv::real specificGravity);
    /// add box as physics body of an actor

    void addConvexHull( btVector3 *verts, qv::s32 numPoints, qv::gaming::Actor *actor, qv::real specificGravity);
    /// add triangle mesh physics body of an actor

    void removeActorBody( qv::u32 actorHashId);
    /// remove a physics body of the actor


    // FIXME: this all will be commands registred by physics manager
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

    void addShape(qv::real radius, qv::gaming::Actor *actor, qv::real specificGravity);
    /// generic shape configuration, to be used all add shape methods.
    


    btDynamicsWorld* mBulletDynamicsWorld;
    btBroadphaseInterface* mBulletBroadphaseInterface;
    btCollisionDispatcher* mBulletCollisionDispatcher;
    btDefaultCollisionConfiguration* mBulletDefaultCollisionConfiguration;
    btConstraintSolver* mBulletConstraintSolver;
    CollisionShapes mCollisionObjectsList;
    qv::events::EventManager* mEventManager;
    real mTimeUpdate;
};

}


}

// inlines
inline void quaternionToEuler(const btQuaternion &TQuat, btVector3 &TEuler)
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

    TEuler *= irr::core::RADTODEG;
}
    
#endif

