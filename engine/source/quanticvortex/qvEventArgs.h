
#ifndef __EVENTARGS_H_
#define __EVENTARGS_H_

#include "events/qvIEventArgs.h"

namespace qv
{
    namespace events
    {
        class _QUANTICVORTEX_API EventArgs: public IEventArgs
        {
		private:
			static const EventType mEventType;

        public:
            EventArgs();
			virtual ~EventArgs();


			const EventType& EventArgs::getEventType() const
			{
				return mEventType;
			}
	        //virtual void serialize(std::ostrstream &out) const;

	        //virtual IEventData copy() const = 0;
        };
    }
}

#endif

