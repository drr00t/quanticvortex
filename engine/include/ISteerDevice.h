#ifndef I_STEER_DEVICE_H
#define I_STEER_DEVICE_H

#include <IrrSteer.h>

namespace IrrSteer{
  class ISteerDevice;
  class ISteerVehicleManager;
  class ISteerWaypointManager;
  class ISteerObstacleManager;
  class IVehicleSceneNode;
  class ISteerWaypoint;

  //! IrrSteer device.
  class ISteerDevice{
    public:
      //! Constructor
      ISteerDevice(IrrlichtDevice* dev){}
      //! drop the steer device, call it when the device is no longer needed
      virtual void drop()=0;

      //! update the simulation
      virtual void update()=0;
      //! debug render
      virtual void render()=0;

      //! set frame rate presets
      virtual void setFrameRatePresets(int fixedframerate, bool usefixedframerate, bool useanimationmode)=0;
      //! set fixed frame rate
      virtual void setFixedFrameRate(int fixedframerate)=0;
      //! use fixed frame rate
      virtual void useFixedFrameRate(bool usefixedframerate)=0;
      //! use animation mode
      virtual void useAnimationMode(bool useanimationmode)=0;

      //! get the waypoint manager
      virtual ISteerWaypointManager* getWaypointManager()=0;
      //! get the vehicle manager
      virtual ISteerVehicleManager* getVehicleManager()=0;
      //! get the obstacle manager
      virtual ISteerObstacleManager* getObstacleManager()=0;
      //! get the scene manager
      virtual irr::scene::ISceneManager* getSceneManager()=0;
      //! get the video driver
      virtual irr::video::IVideoDriver* getVideoDriver()=0;
      //! get the graphics device
      virtual irr::IrrlichtDevice* getGraphicsDevice()=0;

  };

} // namespace

#endif // I_STEER_DEVICE_H
