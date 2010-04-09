/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009-2010 QuanticMinds Software Ltda.
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

**************************************************************************************************/


#ifndef __EVENT_MANAGER_H_
#define __EVENT_MANAGER_H_

#include "qvIEventManager.h"
#include "qvIEventCommand.h"
#include "qvIEventArgsFactory.h"

//#include "tbb/concurrent_queue.h"

#include "Poco/AtomicCounter.h"

namespace qv
{
    namespace events
    {

		class EventManager: public IEventManager
		{
		public:
    		EventManager();
			virtual ~EventManager();

			virtual bool registerCommandEvent ( IEventCommandSharedPtr command);

			virtual bool unregisterCommandEvent ( IEventCommandSharedPtr command);
			//virtual bool unregisterCommandEvent ( const CT_COMMAND_TYPE& commandType);

			virtual IEventArgsSharedPtr createEmptyEventArgs( u32 eventArgsHashtype);

//			virtual IEventArgsSharedPtr createEmptyEventArgs( u32 eventHashType);
//			virtual IChangeStateEventArgs* createChangeStateEventArgs(const S_STATE* state);

//			virtual IStaticActorAddedEventArgs* createStaticActorAddedEventArgs(const c8* name){return 0;}
//			virtual IDynamicActorAddedEventArgs* createDynamicActorAddedEventArgs(const c8* name){return 0;}

			virtual void registerEventArgsFactory(IEventArgsFactory * factory);

			virtual void registerEventType( u32 eventHashType);

			virtual void unregisterEventType( u32 eventHashType);

			virtual bool abortEvent ( u32 eventHashType, bool all = false );

			virtual bool enqueueEvent (IEventArgsSharedPtr args);

			virtual bool process ( real processingTime);

			virtual bool trigger ( IEventArgsSharedPtr args );

			virtual bool validateType(u32 eventHashType);

		private:
			static const s32 QueueEventsLenght = 2;
			EventHashTypesVector mValidEventTypes;
			EventArgsEventCommandVector mRegistredCommandsMap;
			EventArgsVector mReadyEvents[QueueEventsLenght]; //to event lists to double buffering
//			ConcurrentEventList mRealtimeReadyEvents; //this get high priority than mRadyEvents;
			EventArgsFactoryVector mEventArgsFactories;
			Poco::AtomicCounter mActiveReadyEventList;
		};
	}
}
#endif

