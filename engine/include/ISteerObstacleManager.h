#ifndef I_STEER_OBSTACLE_MANAGER_H
#define I_STEER_OBSTACLE_MANAGER_H

#include <IrrSteer.h>

namespace IrrSteer{
  class ISteerDevice;
  class ISteerVehicleManager;
  class ISteerWaypointManager;
  class ISteerObstacleManager;
  class IVehicleSceneNode;
  class ISteerWaypoint;

  //! obstacle manager
  class ISteerObstacleManager{
    public:
      ISteerObstacleManager(){}
      //! get the steering device
      virtual ISteerDevice* getSteerDevice()=0;

      //! add an obstace to the scene
      virtual OpenSteer::SphereObstacle* addObstacleSphere(irr::core::vector3df pos, float radius, OpenSteer::Obstacle::seenFromState seenfrom = OpenSteer::Obstacle::outside)=0;
      //! add an obstace to the scene
      virtual OpenSteer::BoxObstacle* addObstacleBox(irr::core::vector3df pos, irr::core::vector3df rot, irr::core::vector3df size, OpenSteer::Obstacle::seenFromState seenfrom = OpenSteer::Obstacle::outside)=0;
      //! delete all obstacles
      virtual void clearObstacles()=0;

      //! get obstacle group
      virtual OpenSteer::ObstacleGroup* getObstacleGroup()=0;

#ifdef DEBUG
      virtual void render(irr::video::IVideoDriver* driver)=0;
#endif

  };

} // namespace

#endif // I_STEER_OBSTACLE_MANAGER_H
