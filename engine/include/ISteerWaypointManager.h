#ifndef I_STEER_WAYPOINT_MANAGER_H
#define I_STEER_WAYPOINT_MANAGER_H

#include <IrrSteer.h>

namespace IrrSteer{
  class ISteerDevice;
  class ISteerVehicleManager;
  class ISteerWaypointManager;
  class ISteerObstacleManager;
  class IVehicleSceneNode;
  class ISteerWaypoint;

  //! Waypoint manager.
  class ISteerWaypointManager{
    public:
      ISteerWaypointManager(){}
      //! get the steer device
      virtual ISteerDevice* getSteerDevice()=0;

      //! delete all waypoints
      virtual void clearWaypoints()=0;
      //! add a waypoint
      virtual ISteerWaypoint* addWaypoint(char* name, irr::core::vector3df pos, float r)=0;
      //! remove a waypoint by name
      virtual void removeWaypoint(char* name)=0;
      //! remove a waypoint
      virtual void removeWaypoint(ISteerWaypoint* wp)=0;
      //! update all waypoints and it's targets
      virtual void updateWaypoints()=0;

      //! set a default waypoint radius
      virtual void setWaypointRadius(float r)=0;
      //! get the default waypoint radius
      virtual float getWaypointRadius()=0;

      //! get a waypoint by name
      virtual ISteerWaypoint* getWaypoint(irr::core::stringc name)=0;
      //! get the closest waypoint to a vector
      virtual ISteerWaypoint* getClosestWaypoint(irr::core::vector3df pos)=0;

      //! generates a path through the waypoint system (not implemented, yet)
      virtual bool generatePathForVehicle(IVehicleSceneNode* vcl, irr::core::vector3df p1, irr::core::vector3df p2, bool startWalking = true)=0;

#ifdef DEBUG
      virtual void render(irr::video::IVideoDriver* driver)=0;
#endif

  };

} // namespace

#endif // I_STEER_WAYPOINT_MANAGER_H
