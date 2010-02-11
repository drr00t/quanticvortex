#ifndef I_STEER_WAYPOINT_H
#define I_STEER_WAYPOINT_H

#include <IrrSteer.h>

namespace IrrSteer{

  //! a Waypoint.
  class ISteerWaypoint{
    public:
      ISteerWaypoint(){}

      //! get name of waypoint
      virtual irr::core::stringc getName()=0;
      //! set name of waypoint (must be unique !!!)
      virtual void setName(irr::core::stringc name)=0;
      //! check if waypoint has this name
      virtual bool hasName(irr::core::stringc name)=0;

      //! get position of waypoint
      virtual irr::core::vector3df getPosition()=0;
      //! set position of waypoint
      virtual void setPosition(irr::core::vector3df pos)=0;

      //! get radius of waypoint
      virtual float getRadius()=0;
      //! set radius of waypoint
      virtual void setRadius(float r)=0;

      //! add target waypoint
      virtual void addTargetWaypoint(ISteerWaypoint* wp)=0;
      //! add target waypoint
      virtual void addTargetWaypoint(char* name)=0;
      //! remove target waypoint
      virtual void removeTargetWaypoint(ISteerWaypoint* wp)=0;
      //! check if waypoint is one of the target waypoints
      virtual bool isTargetWaypoint(ISteerWaypoint* wp)=0;

      //! check if a point is inside the waypoint
      virtual bool isInWaypoint(irr::core::vector3df pos)=0;
      //! get the distance to a point
      virtual float getDistanceTo(core::vector3df pos)=0;
      //! update all target waypoints
      virtual void updateTargetWaypoints()=0;

      //! get waypoint manager
      virtual ISteerWaypointManager* getWaypointManager()=0;
      //! delete this waypoint
      virtual void remove()=0;

#ifdef DEBUG
      virtual void render(irr::video::IVideoDriver* driver)=0;
#endif

  };

} // namespace

#endif // I_STEER_WAYPOINT_MANAGER_H
