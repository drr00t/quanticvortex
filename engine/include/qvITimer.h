

#ifndef __I_TIMER_H_
#define __I_TIMER_H_

#include "qvPrerequisites.h"

namespace qv
{
	class ITimer
	{
	private:
		irr::ITimer  *  mIrrlichtTimer;

		u32    mTime;
		f32    mTimeRest;
		u32    mLastRealTime;
		u32    mLastStartTime;
		f32    mSpeed;
		u32    mLastTick;

		int         mIsRunning;

	public:
		Timer(irr::ITimer * irrlichtTimer_, bool startRunning_=false);	// startRunning_ decides if timer is running or stopped after creation
		virtual ~Timer();

		// in milliseconds
		virtual u32 getTime()=0;
		virtual void setTime(u32 time_)=0;

		virtual u32 getLastTickInMs()=0;
		virtual f32 getLastTickInSeconds()=0;

		// unlike irr::ITimer there's no reference counting for start/stop!
		virtual void stop()=0;
		virtual void start()=0;
		virtual bool isStopped()=0;

		virtual u32 getLastStartTime()=0;

		virtual void setSpeed(f32 speed_ = 1.0f)=0;
		virtual f32 getSpeed()=0;

		// Must be called regularly.
		virtual void tick()=0;
	};
}

#endif // TIMER_H
