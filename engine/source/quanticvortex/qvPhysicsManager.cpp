
#include "qvPhysicsManager.h"

namespace qv
{
    namespace physics
    {
        //-----------------------------------------------------------------------------------------
		PhysicsManager::PhysicsManager(IrrlichtDevice* device)
            :mBulletDynamicsWorld(0),mBulletBroadphaseInterface(0),
            mBulletCollisionDispatcher(0),mBulletConstraintSolver(0),
            mBulletDefaultCollisionConfiguration(0)
        {

        }
        //-----------------------------------------------------------------------------------------
		PhysicsManager::~PhysicsManager()
        {
            delete mBulletDynamicsWorld;
        }
        //-----------------------------------------------------------------------------------------
        bool PhysicsManager::initialize()
        {
            mBulletDefaultCollisionConfiguration = new btDefaultCollisionConfiguration();
            mBulletCollisionDispatcher = 
                new btCollisionDispatcher(mBulletDefaultCollisionConfiguration);

            mBulletBroadphaseInterface = new btDbvtBroadphase();

            mBulletConstraintSolver = new btSequentialImpulseConstraintSolver();

            mBulletDynamicsWorld = new btDiscreteDynamicsWorld(mBulletCollisionDispatcher,
                mBulletBroadphaseInterface,mBulletConstraintSolver,
                mBulletDefaultCollisionConfiguration);

            mBulletDynamicsWorld->setInternalTickCallback(internalTickCallback,this);

            return true;
        }

        void PhysicsManager::internalTickCallback(btDynamicsWorld* const world, btScalar const timeStep)
        {
	        //assert( world );
        	
	        //assert( world->getWorldUserInfo() );
	        //BulletPhysics * const bulletPhysics = static_cast<BulletPhysics*>( world->getWorldUserInfo() );
        	
	        //CollisionPairs currentTickCollisionPairs;
        	
	        // look at all existing contacts
	        //btDispatcher * const dispatcher = world->getDispatcher();
	        //for ( int manifoldIdx=0; manifoldIdx<dispatcher->getNumManifolds(); ++manifoldIdx )
	        //{
		       // // get the "manifold", which is the set of data corresponding to a contact point
		       // //   between two physics objects
		       // btPersistentManifold const * const manifold = dispatcher->getManifoldByIndexInternal( manifoldIdx );
		       // assert( manifold );
        	//	
		       // // get the two bodies used in the manifold.  Bullet stores them as void*, so we must cast
		       // //  them back to btRigidBody*s.  Manipulating void* pointers is usually a bad
		       // //  idea, but we have to work with the environment that we're given.  We know this
		       // //  is safe because we only ever add btRigidBodys to the simulation
		       // btRigidBody const * const body0 = static_cast<btRigidBody const *>(manifold->getBody0());
		       // btRigidBody const * const body1 = static_cast<btRigidBody const *>(manifold->getBody1());
        	//	
		       // // always create the pair in a predictable order
		       // bool const swapped = body0 > body1;
        	//	
		       // btRigidBody const * const sortedBodyA = swapped ? body1 : body0;
		       // btRigidBody const * const sortedBodyB = swapped ? body0 : body1;
        	//	
		       // CollisionPair const thisPair = std::make_pair( sortedBodyA, sortedBodyB );
		       // currentTickCollisionPairs.insert( thisPair );
        	//	
		       // if ( bulletPhysics->m_previousTickCollisionPairs.find( thisPair ) == bulletPhysics->m_previousTickCollisionPairs.end() )
		       // {
			      //  // this is a new contact, which wasn't in our list before.  send an event to the game.
			      //  bulletPhysics->SendCollisionPairAddEvent( manifold, body0, body1 );
		       // }
	        //}
        	
	        //CollisionPairs removedCollisionPairs;
        	//
	        //// use the STL set difference function to find collision pairs that existed during the previous tick but not any more
	        //std::set_difference( bulletPhysics->m_previousTickCollisionPairs.begin(), bulletPhysics->m_previousTickCollisionPairs.end(),
	        //                     currentTickCollisionPairs.begin(), currentTickCollisionPairs.end(),
	        //                     std::inserter( removedCollisionPairs, removedCollisionPairs.begin() ) );
        	//
	        //for ( CollisionPairs::const_iterator it = removedCollisionPairs.begin(), 
         //        end = removedCollisionPairs.end(); it != end; ++it )
	        //{
		       // btRigidBody const * const body0 = it->first;
		       // btRigidBody const * const body1 = it->second;
        	//	
		       // bulletPhysics->SendCollisionPairRemoveEvent( body0, body1 );
	        //}
        	
	        // the current tick becomes the previous tick.  this is the way of all things.
	        //bulletPhysics->m_previousTickCollisionPairs = currentTickCollisionPairs;
        	
	        //// handle actors that want to turn manually
	        //for ( ActorIDToBulletActorMap::const_iterator it = bulletPhysics->m_actorBodies.begin();
	        //      it != bulletPhysics->m_actorBodies.end();
	        //      ++it )
	        //{
		       // if ( it->second->m_desiredDeltaYAngleTime > 0 )
		       // {
			      //  float const amountOfTimeToConsume = std::min( timeStep, it->second->m_desiredDeltaYAngleTime );
			      //  float const deltaAngle = (amountOfTimeToConsume / it->second->m_desiredDeltaYAngleTime) * it->second->m_desiredDeltaYAngle;
        	//	
			      //  // create a transform to represent the additional turning this frame
			      //  btTransform angleTransform;
			      //  angleTransform.setIdentity();
			      //  angleTransform.getBasis().setEulerYPR( 0, deltaAngle, 0 ); // rotation about body Y-axis
        	//		
			      //  btRigidBody * const body = it->second->m_pRigidBody;
        	//		
			      //  // concatenate the transform onto the body's transform
			      //  body->setCenterOfMassTransform( body->getCenterOfMassTransform() * angleTransform );
        	//		
			      //  // tick down the parameters
			      //  it->second->m_desiredDeltaYAngle -= deltaAngle;
			      //  it->second->m_desiredDeltaYAngleTime -= amountOfTimeToConsume;
		       // }
	        //}
        }

        //-----------------------------------------------------------------------------------------
		void PhysicsManager::update( u32 elapsedTimeMs)
        {
			btScalar elapsedTimeS(elapsedTimeMs/1000.0f); 

            mBulletDynamicsWorld->stepSimulation(elapsedTimeS, 2); //just twos sub steps);
        }
        //-----------------------------------------------------------------------------------------
    }
}

