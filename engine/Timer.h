#ifndef TIMER_H
#define TIMER_H

#include <irrlicht.h>

class Timer
{
public:
	Timer(irr::ITimer * irrlichtTimer_, bool startRunning_=false);	// startRunning_ decides if timer is running or stopped after creation
	virtual ~Timer();

    // in milliseconds
	virtual irr::u32 GetTime();
	virtual void SetTime(irr::u32 time_);

	virtual irr::u32 GetLastTickInMs();
	virtual irr::f32 GetLastTickInSeconds();

    // unlike irr::ITimer there's no reference counting for start/stop!
	virtual void Stop();
	virtual void Start();
	virtual bool IsStopped();

	virtual irr::u32 GetLastStartTime();

	virtual void SetSpeed(irr::f32 speed_ = 1.0f);
	virtual irr::f32 GetSpeed();

	// Must be called regularly.
	virtual void Tick();

private:
    irr::ITimer  *  mIrrlichtTimer;

    irr::u32    mTime;
    irr::f32    mTimeRest;
    irr::u32    mLastRealTime;
    irr::u32    mLastStartTime;
    irr::f32    mSpeed;
    irr::u32    mLastTick;
    int         mIsRunning;
};

#endif // TIMER_H
