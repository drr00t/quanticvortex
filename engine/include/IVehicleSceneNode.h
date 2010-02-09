#ifndef __C_IVehicleSceneNode_H_INCLUDED__
#define __C_IVehicleSceneNode_H_INCLUDED__

#include <IrrSteer.h>

namespace irr{
namespace scene{
  static const int ESNT_VEHICLE_SCENE_NODE = MAKE_IRR_ID('v','h','c','l');
}} // end namespaces

namespace IrrSteer{
  typedef OpenSteer::AbstractProximityDatabase<OpenSteer::AbstractVehicle*> ProximityDatabase;
  typedef OpenSteer::AbstractTokenForProximityDatabase<OpenSteer::AbstractVehicle*> ProximityToken;

  //! NPC types
  enum E_NPC_TYPE{
    ENT_UNKNOWN = 0,  /*!< unknown npc-type (= test-npc in debug mode) */
    ENT_PLAYER,       /*!< player controlled vehicle */

    ENT_COUNT         /*!< count of npc types */
  };
  //! NPC movement states
  enum E_NPC_MOVEMENT_STATE{
    EMS_IDLE = 0,   /*!< npc standing at place */
    EMS_WANDER,       /*!< npc roaming around */
    EMS_WALK,       /*!< npc walking to target */
    EMS_RUN,       /*!< npc running to target */

    EMS_COUNT,         /*!< count of npc movement states */
    EMS_NOTHING         /*!< do nothing, for use with animation-end-callback when animation is looped */
  };

  //! Path follow modes
  /*! The npc goes to "idle" state when the last waypoint was reached.<br>
      so don't put start and end point too close together and don't make the waypoint-eadius too small... ;) */
  enum E_PATH_FOLLOW_TYPE{
    EPFT_EXACTPATH = 0,  /*!< follow exact path, direct waypoint steering (one by one) */
    EPFT_FOLLOWPATH,       /*!< follow path, using OpenSteer follow-path steering */
    EPFT_STAYONPATH,       /*!< stay on path, using OpenSteer stayon-path steering */

    EPFT_COUNT         /*!< count of path follow modes */
  };

#ifdef DEBUG
  //! Enumeration for debug drawing (can be combined binary)
  enum E__DEBUG_SHOW_TYPE{
    EDBS_SHOW_NOTHING               =    0, /*!< show nothing */
    EDBS_SHOW_VEHICLES_BODY         =    1, /*!< show vehicle bodies */
    EDBS_SHOW_VEHICLES_ACCELERATION =    2, /*!< show vehicle annotations */
    EDBS_SHOW_VEHICLES_TRAIL        =    4, /*!< show vehicle annotations */
    EDBS_SHOW_VEHICLES_PATH         =    8, /*!< show vehicle path */
    EDBS_SHOW_OBSTACLES             =   16, /*!< show obstacles */
    EDBS_SHOW_WAYPOINTS             =   32, /*!< show way points */
    EDBS_SHOW_PATHWAYS              =   64, /*!< show path ways for way points */
    EDBS_SHOW_TERRAIN               =  128, /*!< show terrain */

    EDBS_SHOW_ALL                  = 511  /*!< show everything (set all bits) */
  };
#endif // DEBUG

  class IVehicleSceneNode : public irr::scene::ISceneNode, public OpenSteer::SimpleVehicle{
    public:
      //! constructor
      IVehicleSceneNode(irr::scene::ISceneNode* parent, irr::scene::ISceneManager* mgr, ProximityDatabase& pdb):irr::scene::ISceneNode(parent, mgr){}
      // Irrlicht drawing stuff
      //! get the bounging box of the scene node
      virtual const irr::core::aabbox3d<f32>& getBoundingBox() const=0;
      //! get the material of the scene node
      virtual irr::video::SMaterial& getMaterial(irr::u32 num)=0;
      //! get the material count of the scene node
      virtual irr::u32 getMaterialCount() const=0;
      //! get the type of the scene node
      virtual irr::scene::ESCENE_NODE_TYPE getType() const=0;
      //! get the type of the vehicle
      virtual int getVecicleType()=0;

      //! Event Receiver
      virtual bool OnEvent(const SEvent& event)=0;

      //! set the scene node for the vehicle
      virtual void setSceneNode(irr::scene::IAnimatedMeshSceneNode* node)=0;

      //! set horizontal movement
      virtual void setMoveHorizontalOnly(bool onlyHorizontal)=0;
      //! get horizontal movement
      virtual bool getMoveHorizontalOnly()=0;

      //! set default waypoint radius
      virtual void setDefaultWaypointRadius(float r)=0;
      //! get default waypoint radius
      virtual float getDefaultWaypointRadius()=0;
      //! set path lead time
      virtual void setPathLeadTime(float lt)=0;
      //! get path lead time
      virtual float getPathLeadTime()=0;
      //! set close path cycle
      virtual void setClosePathCycle(bool c)=0;
      //! get close path cycle
      virtual bool getClosePathCycle()=0;
      //! set path direction
      virtual void setPathDirection(bool forward)=0;
      //! get path direction
      virtual bool getPathDirectionIsForward()=0;
      //! set path follow mode
      virtual void setPathFollowMode(E_PATH_FOLLOW_TYPE fm)=0;
      //! get path follow mode
      virtual E_PATH_FOLLOW_TYPE getPathFollowMode()=0;
      //! set time to collision
      virtual void setTimeToCollision(float t)=0;
      //! get time to collision
      virtual float getTimeToCollision()=0;
      //! set time to neighbor
      virtual void setTimeToNeighbor(float t)=0;
      //! get time to neighbor
      virtual float getTimeToNeighbor()=0;
      //! set vehicle mass
      virtual void setMass(float m)=0;
      //! get vehicle mass
      virtual float getMass()=0;
      //! set vehicle radius
      virtual void setRadius(float r)=0;
      //! get vehicle radius
      virtual float getRadius()=0;


      //! set calculation when invisible
      virtual void setCalculationWhenInvisible(bool c)=0;
      //! get calculation when invisible
      virtual bool getCalculationWhenInvisible()=0;

      //! set maximum speed and force for movement state
      virtual void setMovementMax(E_NPC_MOVEMENT_STATE state, float maxspeed, float maxforce)=0;
      //! set maximum speed for movement state
      virtual void setMaxSpeed(E_NPC_MOVEMENT_STATE state, float maxspeed)=0;
      //! set maximum force for movement state
      virtual void setMaxForce(E_NPC_MOVEMENT_STATE state, float maxforce)=0;
      //! get maximum speed for movement state
      virtual float getMaxSpeed(E_NPC_MOVEMENT_STATE state)=0;
      //! get maximum force for movement state
      virtual float getMaxForce(E_NPC_MOVEMENT_STATE state)=0;

      //! add an animation to movement state
      virtual void addAnimation(E_NPC_MOVEMENT_STATE state, int fStart, int fEnd, int aSpeed, bool aLoop = true, E_NPC_MOVEMENT_STATE dWhenFinished = EMS_NOTHING)=0;
      //! delete all animations from movement state
      virtual void clearAnimations(E_NPC_MOVEMENT_STATE state)=0;

      //! add a waypoint to the path
      virtual void addWaypoint(OpenSteer::Vec3 pos)=0;
      //! add a waypoint to the path
      virtual void addWaypoint(irr::core::vector3df pos)=0;
      //! clear waypoint path
      virtual void clearPath()=0;

      //! set current movement state
      virtual void setMovementState(E_NPC_MOVEMENT_STATE state)=0;
      //! get current movement state
      virtual E_NPC_MOVEMENT_STATE getMovementState()=0;
      //! get text for the current movement state
      virtual irr::core::stringc getMovementStateText()=0;

      //! reset vehicle
      virtual void reset()=0;
      //! set a new proximity database
      virtual void setProximityDB(ProximityDatabase& db)=0;
      //! called when simulatuon was updated (from Irrlicht)
      virtual void OnRegisterSceneNode()=0;
      //! update vehicle
      virtual void update(const float currentTime, const float elapsedTime)=0;
      //! render vehicle (called from Irrlicht)
      virtual void render()=0;
      //! we override setPosition to update the vehicle too
      virtual void setPosition(irr::core::vector3df p)=0;
      //! we override setRotation to update the vehicle too
      virtual void setRotation(irr::core::vector3df r)=0;

      //! set obstacle avoidance time
      virtual void setObstacleAvoidanceTime(float sec)=0;
      //! get obstacle avoidance time
      virtual float getObstacleAvoidanceTime()=0;

      // Irrlicht serialisazion
      //! serialize the scene node
      virtual void serializeAttributes(irr::io::IAttributes* out, irr::io::SAttributeReadWriteOptions* options=0) const=0;
      //! deserialize the scene node
      virtual void deserializeAttributes(irr::io::IAttributes* in, irr::io::SAttributeReadWriteOptions* options=0)=0;

  };

} // end namespaces

#endif // __C_IVehicleSceneNode_H_INCLUDED__
