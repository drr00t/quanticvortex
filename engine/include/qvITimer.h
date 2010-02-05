

#ifndef __I_TIMER_H_
#define __I_TIMER_H_

#include "qvPrerequisites.h"

class Timer
{
private:
    irr::ITimer  *  mIrrlichtTimer;

    irr::u32    mTime;
    irr::f32    mTimeRest;
    irr::u32    mLastRealTime;
    irr::u32    mLastStartTime;
    irr::f32    mSpeed;
    irr::u32    mLastTick;
    int         mIsRunning;

public:
	Timer(irr::ITimer * irrlichtTimer_, bool startRunning_=false);	// startRunning_ decides if timer is running or stopped after creation
	virtual ~Timer();

    // in milliseconds
	virtual irr::u32 getTime()=0;
	virtual void setTime(irr::u32 time_)=0;

	virtual irr::u32 getLastTickInMs()=0;
	virtual irr::f32 getLastTickInSeconds()=0;

    // unlike irr::ITimer there's no reference counting for start/stop!
	virtual void stop()=0;
	virtual void start()=0;
	virtual bool isStopped()=0;

	virtual irr::u32 getLastStartTime()=0;

	virtual void setSpeed(irr::f32 speed_ = 1.0f)=0;
	virtual irr::f32 getSpeed()=0;

	// Must be called regularly.
	virtual void tick()=0;
};

#endif // TIMER_H
