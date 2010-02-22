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

//#include "tbb/concurrent_queue.h"


namespace qv
{
    namespace events
    {
		class ICommandEvent;
		class ICameraActorAddedEventArgs;
		class IDynamicActorAddedEventArgs;
		class IStaticActorAddedEventArgs;

		class EventManager: public IEventManager
		{
		private:

			static const s32 QueueEventsLenght = 2;

			typedef list<const ET_EVENT_TYPE*> EventTypeList;
			typedef list<IEventArgs*> EventList;
			typedef list<IEventArgsFactory*> EventArgsFactoryList;
			typedef list<ICommandEvent*> CommandEventList;
			typedef map<s32, CommandEventList> EventToCommandEventMap;
//			typedef tbb::concurrent_bounded_queue<IEventArgs*> ConcurrentEventList;

		public:
    		EventManager();
			virtual ~EventManager();

			virtual bool registerCommandEvent ( ICommandEvent* command);
			virtual bool unregisterCommandEvent ( ICommandEvent* command);
			//virtual bool unregisterCommandEvent ( const CT_COMMAND_TYPE& commandType);

			virtual IEventArgs* createEmptyEventArgs(const ET_EVENT_TYPE* type);
			virtual IChangeStateEventArgs* createChangeStateEventArgs(const S_STATE* state);
			
			virtual ICameraActorAddedEventArgs* createCameraActorAddedEventArgs(const c8* actorName);
			virtual IStaticActorAddedEventArgs* createStaticActorAddedEventArgs(const c8* name){return 0;}
			virtual IDynamicActorAddedEventArgs* createDynamicActorAddedEventArgs(const c8* name){return 0;}

			virtual void registerEventArgsFactory(IEventArgsFactory* factory);

			virtual void registerEventType(const ET_EVENT_TYPE* type);
			virtual void unregisterEventType(const ET_EVENT_TYPE* type);

			virtual bool abortEvent ( const ET_EVENT_TYPE* type, bool all = false );
			virtual bool enqueueEvent (IEventArgs* args);
			virtual bool process ( f32 processingTime);
			virtual bool trigger ( IEventArgs *args );
			virtual bool validateType(const ET_EVENT_TYPE* type);

		private:
			EventTypeList mValidEventTypes;
			EventToCommandEventMap mRegistredCommandsMap;
			EventList mReadyEvents[QueueEventsLenght]; //to event lists to double buffering
//			ConcurrentEventList mRealtimeReadyEvents; //this get high priority than mRadyEvents;
			EventArgsFactoryList mEventArgsFactories;
			mutable s32 mActiveReadyEventList;
		};
	}
}
#endif

