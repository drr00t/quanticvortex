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


#include "qvEventManager.h"

#include "qvIEventArgs.h"
#include "qvICommandEvent.h"

//default event args factories
#include "qvDefaultEventArgsFactory.h"

namespace qv
{
    namespace events
    {   
		//-----------------------------------------------------------------------------------------
		EventManager::EventManager()
			:mActiveReadyEventList(0)
		{
			setDebugName("EventManager");

			DefaultEventArgsFactory* factory = new DefaultEventArgsFactory();
			mEventArgsFactories.push_back(factory);
			factory->drop();
		}
		//-----------------------------------------------------------------------------------------
		EventManager::~EventManager()
		{
		}
		//-----------------------------------------------------------------------------------------
		void EventManager::registerEventType(  const ET_EVENT_TYPE* type)
		{
			if(!type || ( type->HashedText <= 0))
				return;

			if(!validateType(type))
				mValidEventTypes.push_back(type);
		}
		//-----------------------------------------------------------------------------------------
		void EventManager::unregisterEventType( const ET_EVENT_TYPE* type)
		{
			
		}
		//-----------------------------------------------------------------------------------------
		void EventManager::registerEventArgsFactory(IEventArgsFactory* factory)
		{
			factory->grab();
			mEventArgsFactories.push_back(factory);
		}
		//-----------------------------------------------------------------------------------------
		IEventArgs* EventManager::getEventArgs(const qv::events::ET_EVENT_TYPE *type)
		{
			EventArgsFactoryList::Iterator itr = mEventArgsFactories.begin();
			IEventArgs* args = 0;
			for(; itr != mEventArgsFactories.end(); ++itr)
			{
				if((*itr)->getCreateableEventArgsType(type))
				{
					args = (*itr)->addEmptyEventArgs(type);
					break;
				}
			}

			return args;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::abortEvent(const ET_EVENT_TYPE* type, bool all)
		{
			return true;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::registerCommandEvent(ICommandEvent* command)
		{
			const array<ET_EVENT_TYPE*>& commandEvents = command->listenEventTypes();

			//add listner in all event that it desire listen
			for(u32 i = 0; i < commandEvents.size(); ++i)
			{
				if(validateType(commandEvents[i]))
				{
					EventToCommandEventMap::Node* nodeListeners =
						mRegistredCommandsMap.find(commandEvents[i]->HashedText);

					//if event already existe, check if listener already exist
					if(nodeListeners)
					{
						CommandEventList::Iterator itrCommandEvent = nodeListeners->getValue().begin();

						for(;itrCommandEvent != nodeListeners->getValue().end();++itrCommandEvent)
						{
							if((*itrCommandEvent)->getID() ==  command->getID())
								return false;
						}

						nodeListeners->getValue().push_back(command);

						break;
					}
					else
					{
						CommandEventList commands;
						commands.push_back(command);
						mRegistredCommandsMap[commandEvents[i]->HashedText] = commands;

						break;
					}
				}
			}

			return true;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::unregisterCommandEvent(ICommandEvent* command)
		{
			const array<ET_EVENT_TYPE*>& events = command->listenEventTypes();

			for(u32 i = 0; i < events.size(); ++i)
			{
				EventToCommandEventMap::Node* nodeListenerMap = 
					mRegistredCommandsMap.find(events[i]->HashedText);

				CommandEventList::Iterator itrCommand = 
					nodeListenerMap->getValue().begin();

				for(;itrCommand != nodeListenerMap->getValue().end(); ++itrCommand)
				{
					if((*itrCommand)->getID() == command->getID())
					{
						nodeListenerMap->getValue().erase(itrCommand);
						break;
					}
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
				mRegistredCommandsMap.find(args->getTypeID());

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
					mRegistredCommandsMap.find((*itrProcessEvent)->getTypeID());

				if(!nodeListenerMap)
					continue;

				CommandEventList::Iterator itrCommands = nodeListenerMap->getValue().begin();
	                             
				for(;itrCommands != nodeListenerMap->getValue().end();++itrCommands)
				{
					const IEventArgs* args = const_cast<IEventArgs*>(*itrProcessEvent);
					(*itrCommands)->executeCommand(args);
				}

				//delete fired event from queue
				(*itrProcessEvent)->drop();
			}
			mReadyEvents[processReadyEventList].clear();

			return eventHandled;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::trigger(IEventArgs *args)
		{
			if(!args || !validateType(args->getEventType()))
				return false;

			//iterate throw generic event listener, like a monitor to all events registred

			EventToCommandEventMap::Node* nodeListenerMap = 
				mRegistredCommandsMap.find(args->getTypeID());

			if(!nodeListenerMap)
				return false;
	        
			bool eventHandled = false; 

			for(CommandEventList::Iterator itrListener = nodeListenerMap->getValue().begin();
				itrListener != nodeListenerMap->getValue().end(); 
				++itrListener)
			{
				(*itrListener)->executeCommand(args);
				eventHandled = true;
			}
	        
			return eventHandled;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::validateType( const ET_EVENT_TYPE* type)
		{
			if((type->Text.size() <= 0) || (type->HashedText <= 0))
				return false;

			EventTypeList::Iterator itr;
			for(itr = mValidEventTypes.begin(); itr != mValidEventTypes.end(); ++itr)
				if((*itr)->HashedText == type->HashedText)
					return false;

			return true;
		}
		//-----------------------------------------------------------------------------------------
	}
}

