#ifndef I_STEER_VEHICLE_MANAGER_H
#define I_STEER_VEHICLE_MANAGER_H

#include <IrrSteer.h>

namespace IrrSteer{
  typedef OpenSteer::AbstractProximityDatabase<OpenSteer::AbstractVehicle*> ProximityDatabase;
  typedef OpenSteer::AbstractTokenForProximityDatabase<OpenSteer::AbstractVehicle*> ProximityToken;
  class ISteerDevice;
  class ISteerVehicleManager;
  class ISteerWaypointManager;
  class ISteerObstacleManager;
  class IVehicleSceneNode;
  class ISteerWaypoint;

  //! vehicle manager.
  class ISteerVehicleManager{
    public:
      ISteerVehicleManager(){}

      //! get the steer device
      virtual ISteerDevice* getSteerDevice()=0;
      //! get the waypoint manager
      virtual ISteerWaypointManager* getWaypointManager()=0;
      //! get the obstacle manager
      virtual ISteerObstacleManager* getObstacleManager()=0;

      //! get the current proximity database
      virtual ProximityDatabase* getProximityDB()=0;
      //! create a new proximity database (bruteforce)
      virtual ProximityDatabase* makeNewProximityDB()=0;
      //! create a new proximity database (LQ)
      virtual ProximityDatabase* makeNewProximityDB(OpenSteer::Vec3 size, OpenSteer::Vec3 divisions = OpenSteer::Vec3(20, 1, 20), OpenSteer::Vec3 center = OpenSteer::Vec3(0,0,0))=0;

      //! add a Vehicle to the scene
      virtual IVehicleSceneNode* addVehicle(irr::scene::IAnimatedMeshSceneNode* meshnode=0)=0;

#ifdef DEBUG
      virtual void render(irr::video::IVideoDriver* driver)=0;
#endif

  };

} // namespace

#endif // I_STEER_VEHICLE_MANAGER_H
