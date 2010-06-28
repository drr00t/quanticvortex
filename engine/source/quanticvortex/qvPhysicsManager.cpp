
#include "qvPhysicsManager.h"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "BulletCollision/CollisionDispatch/btGhostObject.h"
#include "BulletCollision/BroadphaseCollision/btOverlappingPairCallback.h"


namespace qv
{
namespace physics
{
//-----------------------------------------------------------------------------------------
PhysicsManager::PhysicsManager(qv::CommandManager* commandManager)
    : mBulletDynamicsWorld(0), mBulletBroadphaseInterface(0),
      mBulletCollisionDispatcher(0), mBulletConstraintSolver(0),
      mBulletDefaultCollisionConfiguration(0), mCommandManager(commandManager)
{
    initialize();
}
//-----------------------------------------------------------------------------------------
PhysicsManager::~PhysicsManager()
{
    finalize();
}
//-----------------------------------------------------------------------------------------
void PhysicsManager::initialize()
{
    mBulletDefaultCollisionConfiguration = new btDefaultCollisionConfiguration();
    mBulletCollisionDispatcher = new btCollisionDispatcher(mBulletDefaultCollisionConfiguration);

    mBulletBroadphaseInterface = new btDbvtBroadphase();

    mBulletConstraintSolver = new btSequentialImpulseConstraintSolver();

    mBulletDynamicsWorld = new btDiscreteDynamicsWorld(mBulletCollisionDispatcher,
            mBulletBroadphaseInterface,
            mBulletConstraintSolver,
            mBulletDefaultCollisionConfiguration);

    mBulletDynamicsWorld->setGravity(btVector3(0, -0.98, 0));

    ///register an additional callback for characters/ghost objects
    btOverlappingPairCallback* ghostPairCallback = new btGhostPairCallback();
    mBulletDynamicsWorld->getBroadphase()->getOverlappingPairCache()->setInternalGhostPairCallback(ghostPairCallback);
}
//-----------------------------------------------------------------------------------------
void PhysicsManager::finalize()
{
    delete mBulletDynamicsWorld;
    delete mBulletConstraintSolver;
    delete mBulletBroadphaseInterface;
    delete mBulletCollisionDispatcher;
    delete mBulletDefaultCollisionConfiguration;
}
//-----------------------------------------------------------------------------------------
void PhysicsManager::update( qv::u32 elapsedTimeMs)
{
    mBulletDynamicsWorld->stepSimulation(btScalar(elapsedTimeMs / 1000.0f), 2); //just twos sub steps, is enough???);
}
//-----------------------------------------------------------------------------------------
void PhysicsManager::addShape(qv::real radius, qv::gaming::Actor *actor, qv::real specificGravity)
{

}
//-----------------------------------------------------------------------------------------
void PhysicsManager::addBox(const btVector3 &dimensions, qv::gaming::Actor *actor, qv::real specificGravity)
{

}
//-----------------------------------------------------------------------------------------
void PhysicsManager::addConvexHull( btVector3 *verts, qv::s32 numPoints, qv::gaming::Actor *actor, qv::real specificGravity)
{
}
//-----------------------------------------------------------------------------------------
void PhysicsManager::addSphere( qv::real radius, qv::gaming::Actor *actor, qv::real specificGravity)
{
//			btSphereShape* sphereShape = new btSphereShape(btScalar(radius));
}
//-----------------------------------------------------------------------------------------
//        void _addPhysicsObject(irr::scene::ISceneNode* node, irr::io::IAttributes* userData)
//        {
//            struct PhysicsAttributes attr;
//            scene::IMesh* mesh=0;
//
//            switch(node->getType())
//            {
//            case scene::ESNT_ANIMATED_MESH:
//                mesh =  static_cast<scene::IAnimatedMeshSceneNode*>(node)->getMesh();
//                break;
//            case scene::ESNT_MESH:
//                mesh =  static_cast<scene::IMeshSceneNode*>(node)->getMesh();
//                break;
//            }
//            if(!mesh)
//            {
//                printf("Error creating physics object - Mesh is NULL for %s\n", node->getName());
//                return;
//            }
//
//            // convert .irr node "UserData" to PhysicsAttributes structure for
//            // easier access.
//            _setPhysicsAttributes(userData, attr);
//
//            node->OnRegisterSceneNode();
//            node->updateAbsolutePosition();
//            core::aabbox3d<f32> aabb = node->getBoundingBox();
//            core::vector3df iExtent = aabb.getExtent();
//            core::vector3df iHalfExtent = iExtent / 2.f;
//
//            btCollisionShape* shape=0;
//            btVector3 halfExtents(iHalfExtent.X, iHalfExtent.Y, iHalfExtent.Z);
//
//            // create collision shape based on PhysicsAttributes shape
//            switch(attr.Shapetype)
//            {
//            case stBox:
//                {
//                    shape = new btBoxShape(halfExtents);
//                }
//                break;
//            case stPlane:
//                {
//                }
//                break;
//            case stSphere:
//                {
//                    shape = new btSphereShape(halfExtents.x());
//                }
//                break;
//            case stCone:
//                {
//                    shape = new btConeShape(halfExtents.x(), halfExtents.y());
//                }
//                break;
//            case stCylinder:
//                {
//                    shape = new btCylinderShape(halfExtents);
//                }
//                break;
//            case stConvexMesh:
//                {
//                    btTriangleMesh* triMesh = _extractTriangles(mesh, true);
//                    //if(attr.BodyType == btStatic)
//                   // {
//                        //shape = new btBvhTriangleMeshShape(triMesh, true, true);
//                        const unsigned char *verts;
//                        const unsigned char *indexes;
//                        PHY_ScalarType vtype, itype;
//                        int numverts, numfaces, vstride,istride;
//
//                        triMesh->getLockedReadOnlyVertexIndexBase(&verts, numverts, vtype, vstride, &indexes, istride, numfaces, itype);
//                        shape = new btConvexHullShape((const btScalar*)verts, numverts, vstride);
//                        triMesh->unLockReadOnlyVertexBase(0);
//                    //}
//                    //else
//                    //{
//                    //    btConvexShape* tmpConvexShape = new btConvexTriangleMeshShape(triMesh);
//                    //    shape = tmpConvexShape;
//                   // }
//                }
//                break;
//            case stConcaveMesh:
//                {
//                    btTriangleMesh* triMesh = _extractTriangles(mesh, true);
//                    if(attr.BodyType == btStatic)
//                    {
//                        btBvhTriangleMeshShape* bShape = new btBvhTriangleMeshShape(triMesh, true, true);
//                        shape = bShape;
//
//                        btTriangleInfoMap* triangleInfoMap = new btTriangleInfoMap();
//
//
//                        btGenerateInternalEdgeInfo(bShape,triangleInfoMap);
//                    }
//                    else
//                    {
//                        // generate convex hull
//                        btConvexShape* tmpConvexShape = new btConvexTriangleMeshShape(triMesh);
//
//                        btShapeHull* hull = new btShapeHull(tmpConvexShape);
//                        btScalar margin = tmpConvexShape->getMargin();
//                        hull->buildHull(margin);
//                        tmpConvexShape->setUserPointer(hull);
//
//
//                        printf("  hull vert count: %d\n", hull->numVertices());
//                        printf("  hull  tri count: %d\n", hull->numTriangles());
//
//                        btConvexHullShape* chShape = new btConvexHullShape();
//
//                        const btVector3* vp = hull->getVertexPointer();
//                        const unsigned int* ip = hull->getIndexPointer();
//                        for (int i=0;i<hull->numTriangles();i++)
//                        {
//                            chShape->addPoint(vp[ip[i*3]]);
//                            chShape->addPoint(vp[ip[i*3+1]]);
//                            chShape->addPoint(vp[ip[i*3+2]]);
//                        }
//
//                        shape = chShape;
//                        delete hull;
//                        delete tmpConvexShape;
//                    }
//                }
//                break;
//            }
//
//            if(!shape)
//            {
//                printf("undefined shape for: %s\n", node->getName());
//                return;
//            }
//
//            // calculate local intertia for dynamic objects
//            btVector3 localInertia(0,0,0);
//            if (attr.mass != 0.f && attr.BodyType == btDynamic)
//                shape->calculateLocalInertia(attr.mass,localInertia);
//
//            btRigidBody* rigidBody = new btRigidBody(attr.mass, new MotionState(node),
//                shape, localInertia);
//            rigidBody->setUserPointer(node);
//
//            rigidBody->getMotionState()->setWorldTransform(rigidBody->getWorldTransform());
//
//            int cflags = rigidBody->getCollisionFlags();
//            rigidBody->setCollisionFlags(0);
//            if(attr.BodyType == btStatic)
//                rigidBody->setCollisionFlags(btCollisionObject::CF_STATIC_OBJECT);
//            else if(attr.BodyType == btKinematic)
//                rigidBody->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT);
//
//            if(attr.Shapetype == stConcaveMesh && attr.BodyType == btStatic)
//                rigidBody->setCollisionFlags(rigidBody->getCollisionFlags()  | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
//
//            if(attr.sensor)
//            {
//                // collision with no response
//                rigidBody->setCollisionFlags(rigidBody->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
//                //rigidBody->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
//                m_sensors.push_back(rigidBody);
//            }
//
//            m_bulletWorld->addRigidBody(rigidBody);
//
//            // collision only ?
//            if(!attr.visible)
//            {
//                // turn off visibility
//                node->setVisible(false);
//            }
//        }
}
}
