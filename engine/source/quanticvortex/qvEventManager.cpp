/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009 QuanticMinds Software Ltda.
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


#include "qvEventManager.h"

namespace qv
{
    namespace gaming
    {
        //-----------------------------------------------------------------------------------------
        EventManager::EventManager()
            :mActiveReadyEventList(0)
        {
			setDebugName("EventManager");
        }
        //-----------------------------------------------------------------------------------------
        EventManager::~EventManager()
        {
        }
        //-----------------------------------------------------------------------------------------
        void EventManager::registerEventType(const ET_EVENT_TYPE& type)
        {
            if(type.ID <= 0)
                return;

            if(!validateType(type))
                mRegistredEvents[type.ID] = type;
        }
        //-----------------------------------------------------------------------------------------
        void EventManager::unregisterEventType(const ET_EVENT_TYPE& type)
        {
			mRegistredEvents.remove(type.ID);
        }
        //-----------------------------------------------------------------------------------------
		bool EventManager::abortEvent(const ET_EVENT_TYPE& type, bool all)
        {
            return true;
        }
        //-----------------------------------------------------------------------------------------
        bool EventManager::registerCommandEvent(ICommandEvent* command)
        {
            array<ET_EVENT_TYPE> commandEvents = command->listenEventTypes();

            //add listner in all event that it desire listen
			for(u32 i = 0; i < commandEvents.size(); ++i)
            {
                if(validateType(commandEvents[i]))
                {
                    EventToCommandEventMap::Node* nodeListeners =
						mRegistredCommandsMap.find(commandEvents[i].ID);

                    //if event already existe, check if listener already exist
                    if(nodeListeners)
                    {
                        CommandEventList::Iterator itrCommandEvent = nodeListeners->getValue().begin();

                        while(itrCommandEvent != nodeListeners->getValue().end())
                        {
                            if((*itrCommandEvent)->getType().ID ==  command->getType().ID)
                                return false;

                            ++itrCommandEvent;
                        }

                        nodeListeners->getValue().push_back(command);
						//mRegistredListenersMap[(*itrCommandEvent)->.ID] = nodeListeners->getValue();

                        break;
                    }
                    else
                    {
						CommandEventList listeners;
						listeners.push_back(command);
						mRegistredCommandsMap[commandEvents[i].ID] = listeners;
                        break;
                    }
                }
            }
            return true;
        }
        //-----------------------------------------------------------------------------------------
		bool EventManager::unregisterCommandEvent(ICommandEvent* command)
        {
			array<ET_EVENT_TYPE> events = command->listenEventTypes();

			for(u32 i = 0; i < events.size(); ++i)
            {
				EventToCommandEventMap::Node* nodeListenerMap = 
					mRegistredCommandsMap.find(events[i].ID);

				CommandEventList::Iterator itrListener = 
					nodeListenerMap->getValue().begin();

                while(itrListener != nodeListenerMap->getValue().end())
                {
					if((*itrListener)->getType() == command->getType())
                    {
                        nodeListenerMap->getValue().erase(itrListener);
                        break;
                    }
                    ++itrListener;
                }
            }            
            
            return true;
        }
        //-----------------------------------------------------------------------------------------
		bool EventManager::enqueueEvent(IEventArgs *args)
        {
            if(!validateType(args->getEventType()))
                return false;

			EventToCommandEventMap::Node* nodeListenerMap = 
				mRegistredCommandsMap.find(args->getEventType().ID);

            if(!nodeListenerMap)
                return false;

            mReadyEvents[mActiveReadyEventList].push_back(args);

            return true;
        }
        //-----------------------------------------------------------------------------------------
        bool EventManager::process(f32 processingTime)
        {
            bool eventHandled = false;
            s32 processReadyEventList = mActiveReadyEventList;

			//------------------------------------------------------------
			//put all realtime generated events to our central event queue
			IEventArgs* realtimeEvent(0);
			while (!mRealtimeReadyEvents.empty() && mRealtimeReadyEvents.try_pop(realtimeEvent))
				enqueueEvent(realtimeEvent);
			//------------------------------------------------------------

			if(mActiveReadyEventList == 0)
				++mActiveReadyEventList;
			else
				mActiveReadyEventList = 0;

            EventList::Iterator itrProcessEvent = mReadyEvents[processReadyEventList].begin();
            

            while(itrProcessEvent != mReadyEvents[processReadyEventList].end())
            {
				EventToCommandEventMap::Node* nodeListenerMap = 
					mRegistredCommandsMap.find((*itrProcessEvent)->getEventType().ID);

                if(!nodeListenerMap)
                    continue;

                CommandEventList::Iterator itrListener = nodeListenerMap->getValue().begin();
                                 
				while(itrListener != nodeListenerMap->getValue().end())
                {
					(*itrListener)->executeCommand(*itrProcessEvent);
                    ++itrListener;
                }

				//delete fired event from queue
				//mReadyEvents[processReadyEventList].erase(itrProcessEvent);
				(*itrProcessEvent)->drop();
            }
			mReadyEvents[processReadyEventList].clear();

            return eventHandled;
        }
        //-----------------------------------------------------------------------------------------
		bool EventManager::trigger(IEventArgs *args)
        {
            if(!validateType(args->getEventType()))
                return false;

            //iterate throw generic event listener, like a monitor to all events registred

			EventToCommandEventMap::Node* nodeListenerMap = 
				mRegistredCommandsMap.find(args->getEventType().ID);

            if(!nodeListenerMap)
                return false;

			CommandEventList::Iterator itrListener = nodeListenerMap->getValue().begin();
            
            bool eventHandled = false; 
			while(itrListener != nodeListenerMap->getValue().end())
            {
                (*itrListener)->executeCommand(args);
                ++itrListener;
            }
            
            return eventHandled;
        }
        //-----------------------------------------------------------------------------------------
        bool EventManager::validateType(const ET_EVENT_TYPE& type)
        {
            if(type.ID <= 0)
                return false;

            //EventTypeList::iterator itr = mRegistredEvents.begin();
            EventTypeMap::Node* node = mRegistredEvents.find(type.ID);

            if(!node)
                return false;

            return true;
        }
        //-----------------------------------------------------------------------------------------
    }
}

