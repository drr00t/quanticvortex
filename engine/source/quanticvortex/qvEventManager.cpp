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

//#include "qvIEventArgs.h"
//#include "qvICommandEvent.h"

//default event args factories
#include "qvDefaultEventArgsFactory.h"
//#include "qvChangeStateEventArgs.h"
#include "qvCameraActorAddedEventArgs.h"

namespace qv
{
    namespace events
    {
		//-----------------------------------------------------------------------------------------
		EventManager::EventManager()
			:mActiveReadyEventList(0)
		{
//			setDebugName("EventManager");

			DefaultEventArgsFactory* factory = new DefaultEventArgsFactory();
			registerEventArgsFactory(factory);
			factory->drop();
		}
		//-----------------------------------------------------------------------------------------
		EventManager::~EventManager()
		{
//			mRegistredCommandsMap.clear();
			//EventToCommandEventMap::ParentLastIterator itrCommandsMap =
			//	mRegistredCommandsMap.getParentLastIterator();

			//while(!itrCommandsMap.atEnd())
			//{
			//	CommandEventList::Iterator itrCommands =
			//		(*itrCommandsMap.getNode()).getValue().begin();

			//	for(;itrCommands != (*itrCommandsMap.getNode()).getValue().end();++itrCommands)
			//		(*itrCommands)->drop();

			//	(*itrCommandsMap.getNode()).getValue().clear();
			//	mRegistredCommandsMap.remove((*itrCommandsMap.getNode()).getKey());
			//}

			EventArgsFactoryList::Iterator itrFactories = mEventArgsFactories.begin();
			for(;itrFactories != mEventArgsFactories.end(); ++itrFactories)
				(*itrFactories)->drop();

            mValidEventTypes.clear();
//			EventTypesList::Iterator itrEvents = mValidEventTypes.begin();
//			for(;itrEvents != mValidEventTypes.end(); ++itrEvents)
//				(*itrEvents)->drop();
		}
		//-----------------------------------------------------------------------------------------
		void EventManager::registerEventType(  const ET_EVENT_TYPE & type)
		{
			if( type.Hash <= 0)
				return;

			if(!validateType(type))
				mValidEventTypes.push_back(type.Hash);
		}
		//-----------------------------------------------------------------------------------------
		void EventManager::unregisterEventType( const ET_EVENT_TYPE & type)
		{

		}
		//-----------------------------------------------------------------------------------------
		void EventManager::registerEventArgsFactory(IEventArgsFactory* factory)
		{
			factory->grab();
			mEventArgsFactories.push_back(factory);
		}
		//-----------------------------------------------------------------------------------------
		IEventArgsSharedPtr EventManager::createEmptyEventArgs(const qv::events::ET_EVENT_TYPE & type)
		{
			EventArgsFactoryList::Iterator itr = mEventArgsFactories.begin();
			IEventArgsSharedPtr args;
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
		ICameraActorAddedEventArgs* EventManager::createCameraActorAddedEventArgs(const c8* actorName)
		{
			ICameraActorAddedEventArgs* args(0); // = new CameraActorAddedEventArgs(ET_CAMERA_ACTOR_ADDED,
												//				new gaming::AI_ACTOR_ID(actorName));
			//EventArgsFactoryList::Iterator itr = mEventArgsFactories.begin();
			//IEventArgs* args = 0;
			//for(; itr != mEventArgsFactories.end(); ++itr)
			//{
			//	if((*itr)->getCreateableEventArgsType(ET_CAMERA_ACTOR_ADDED))
			//	{
			//		args = (*itr)->addca(type);
			//		break;
			//	}
			//}

			return args;
		}
		//-----------------------------------------------------------------------------------------
//		IChangeStateEventArgs* EventManager::createChangeStateEventArgs(const qv::S_STATE *state)
//		{
//			//EventArgsFactoryList::Iterator itr = mEventArgsFactories.begin();
////			IChangeStateEventArgs* args = 0;
//			//for(; itr != mEventArgsFactories.end(); ++itr)
//			//{
//			//	if((*itr)->getCreateableEventArgsType(type))
//			//	{
////			args = new ChangeStateEventArgs(ET_GAME_STATE_CHANGE, state);
//			//		break;
//			//	}
//			//}
//
//			return 0;
//		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::abortEvent(const ET_EVENT_TYPE& type, bool all)
		{
			return true;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::registerCommandEvent(IEventCommandSharedPtr command)
		{
			const EventTypesList& commandEvents = command->listenEventTypes();

			//add listner in all event that it desire listen
//			for(u32 i = 0; i < commandEvents.size(); ++i)
            EventTypesList::ConstIterator itr = commandEvents.begin();
            for(;itr != commandEvents.end(); ++itr)
			{
				if(validateType((*itr)))
				{
					EventToCommandEventMap::Node* nodeListeners =
						mRegistredCommandsMap.find((*itr));

					//if event already existe, check if listener already exist
					if(nodeListeners)
					{
						const EventCommandArray& arrEventCommands = nodeListeners->getValue();

						for( s32 j = 0; j < arrEventCommands.size(); ++j)
							if(arrEventCommands[j]->getHashId() ==  command->getHashId())
								return false;

						nodeListeners->getValue().push_back(command);

						break;
					}
					else
					{
						EventCommandArray commands;
						commands.push_back(command);
						mRegistredCommandsMap[(*itr)] = commands;

						break;
					}
				}
			}

			return true;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::unregisterCommandEvent(IEventCommandSharedPtr command)
		{
			const EventTypesList& events = command->listenEventTypes();
			EventTypesList::ConstIterator itrEvents = events.begin();

			for(; itrEvents != events.end(); ++itrEvents)
			{
				EventToCommandEventMap::Node* nodeListenerMap =
					mRegistredCommandsMap.find((*itrEvents));

				EventCommandArray eventCommands = nodeListenerMap->getValue();

				for( u32 j = 0 ; j < eventCommands.size(); ++j)
				{
					if(eventCommands[j]->getHashId() == command->getHashId())
                    {
    				    eventCommands.erase(j);
						break;
					}
				}
			}

			return true;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::enqueueEvent(IEventArgs *args)
		{
			if(!validateType(args->getHashType()))
				return false;

            //check for a command listening this event
			EventToCommandEventMap::Node* nodeCommandsMap =
				mRegistredCommandsMap.find(args->getHashType());

			if(!nodeCommandsMap)
				return false;

//			mReadyEvents[mActiveReadyEventList].push_back(args);

			return true;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::enqueueEvent(IEventArgsSharedPtr args)
		{
			if(!validateType(args->getHashType()))
				return false;

            //check for a command listening this event
			EventToCommandEventMap::Node* nodeCommandsMap =
				mRegistredCommandsMap.find(args->getHashType());

			if(!nodeCommandsMap)
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
//			IEventArgs* realtimeEvent(0);
//			while (!mRealtimeReadyEvents.empty() && mRealtimeReadyEvents.try_pop(realtimeEvent))
//				enqueueEvent(realtimeEvent);
			//------------------------------------------------------------

			if(mActiveReadyEventList == 1)
				--mActiveReadyEventList;

			++mActiveReadyEventList; //back to first one

//			EventList::Iterator itrEventArgs = mReadyEvents[processReadyEventList].begin();

//			for(;itrEventArgs != mReadyEvents[processReadyEventList].end(); ++itrEventArgs)
//			{
            for(s32 i = 0; i < mReadyEvents[processReadyEventList].size(); ++i)
			    trigger(mReadyEvents[processReadyEventList][i]);
//				EventToCommandEventMap::Node* nodeCommandsMap =
//					mRegistredCommandsMap.find((*itrEventArgs)->getTypeID());
//
//				if(!nodeCommandsMap)
//					continue;
//
//				CommandEventList::Iterator itrCommands = nodeCommandsMap->getValue().begin();
//
//				for(;itrCommands != nodeCommandsMap->getValue().end();++itrCommands)
//				{
//					const IEventArgs* args = const_cast<IEventArgs*>(*itrEventArgs);
//					(*itrCommands)->executeCommand(args);
//				}
//
//				//delete fired event args from queue
//				(*itrEventArgs)->drop();
//			}

			mReadyEvents[processReadyEventList].clear();

			return eventHandled;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::trigger(IEventArgs *args)
		{
			if(!args || !validateType(args->getHashType()))
				return false;

			//iterate throw generic event listener, like a monitor to all events registred

			EventToCommandEventMap::Node* nodeListenerMap =
				mRegistredCommandsMap.find(args->getHashType());

			if(!nodeListenerMap)
				return false;

			bool eventHandled = false;

			const EventCommandArray& commands = nodeListenerMap->getValue();

			for(s32 i = 0; i < commands.size(); ++i)
			{
//				commands[i]->executeCommand(args);
				eventHandled = true;
			}

			return eventHandled;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::trigger(IEventArgsSharedPtr args)
		{
			if(!args || !validateType(args->getHashType()))
				return false;

			//iterate throw generic event listener, like a monitor to all events registred

			EventToCommandEventMap::Node* nodeListenerMap =
				mRegistredCommandsMap.find(args->getHashType());

			if(!nodeListenerMap)
				return false;

			bool eventHandled = false;

			const EventCommandArray& commands = nodeListenerMap->getValue();

			for(s32 i = 0; i < commands.size(); ++i)
			{
				commands[i]->executeCommand(args);
				eventHandled = true;
			}

			return eventHandled;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::validateType( const ET_EVENT_TYPE & type)
		{
			if (type.Hash <= 0)
				return false;

			EventTypesList::ConstIterator itr;
			for(itr = mValidEventTypes.begin(); itr != mValidEventTypes.end(); ++itr)
				if((*itr) == type.Hash)
					return false;

			return true;
		}
		//-----------------------------------------------------------------------------------------
		bool EventManager::validateType( u32 eventHashType)
		{
			if(eventHashType <= 0)
				return false;

			EventTypesList::Iterator itr;
			for(itr = mValidEventTypes.begin(); itr != mValidEventTypes.end(); ++itr)
				if((*itr) == eventHashType)
					return true;

			return false;
		}
		//-----------------------------------------------------------------------------------------
	}
}

