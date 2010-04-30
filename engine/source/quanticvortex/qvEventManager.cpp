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

//#include "qvEventArgs.h"

//default event args factories
#include "qvEventArgsFactory.h"
//#include "qvChangeStateEventArgs.h"

namespace qv
{
namespace events
{
//-----------------------------------------------------------------------------------------
EventManager::EventManager()
    :mActiveReadyEventList(0)
{

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

//			EventArgsFactoryVector::Iterator itrFactories = mEventArgsFactories.begin();
//			for(;itrFactories != mEventArgsFactories.end(); ++itrFactories)
//				(*itrFactories)->drop();

    mValidEventTypes.clear();
//			EventTypesList::Iterator itrEvents = mValidEventTypes.begin();
//			for(;itrEvents != mValidEventTypes.end(); ++itrEvents)
//				(*itrEvents)->drop();
}
//-----------------------------------------------------------------------------------------
template<class T> T* EventManager::createEventArgs( u32 eventArgsHashType)
{
    qv::events::EventArgs* eventArgs(0);

    if(validateType(eventArgsHashType))
        eventArgs = mEventArgs.keep(new T( eventArgsHashType));

    return static_cast<T*>(eventArgs);
}
//-----------------------------------------------------------------------------------------
void EventManager::registerEventType( u32 eventHashType)
{
    if( eventHashType <= 0)
        return;

    if(!validateType(eventHashType))
        mValidEventTypes.push_back(eventHashType);
}
//-----------------------------------------------------------------------------------------
void EventManager::unregisterEventType( u32 eventHashType)
{
//    if(validateType(eventHashType))
//        mValidEventTypes.erase(eventHashType);
}
////-----------------------------------------------------------------------------------------
//void EventManager::registerEventArgsFactory(IEventArgsFactory* factory)
//{
//			factory->grab();
//    mEventArgsFactories.push_back(factory);
//}
//-----------------------------------------------------------------------------------------
bool EventManager::abortEvent( u32 eventHashType)
{
//    for(u32 i = 0; i < mReadyEvents[mActiveReadyEventList].size(); ++i)
//        if(mReadyEvents[mActiveReadyEventList][i].getEvenHashType() == eventHashType)
    return true;
}
//-----------------------------------------------------------------------------------------
bool EventManager::addCommand(qv::ICommand* command)
{
    if(validateType(command->getHashType()))
        return false;
        
    qv::CommandMap::Node* eventsCommandsNode = 
            mRegistredCommandsMap.find(command->getHashType());
            
    if(eventsCommandsNode)
    {
        qv::CommandArray eventCommands = eventsCommandsNode->getValue();
        qv::ICommand* comm = static_cast<qv::ICommand*>(command);
        
        for(u32 i = 0; i < eventCommands.size(); ++i)
        {
            qv::ICommand* commTest = static_cast<qv::ICommand*>(eventCommands[i]);
            if((commTest->getHashId() == comm->getHashId()) &&
            (commTest->getHashType() == comm->getHashType()))
            {                
                return true;
            }
        }
        
        eventCommands.push_back(command);
    }
    else
    {
        qv::CommandArray commandsArray;
        commandsArray.push_back(command);
        mRegistredCommandsMap.insert(command->getHashType(), commandsArray);
    }

    return true;
}
//-----------------------------------------------------------------------------------------
bool EventManager::removeCommand(qv::ICommand* command)
{
        if(validateType(command->getHashType()))
        return false;
        
    qv::CommandMap::Node* eventsCommandsNode = 
            mRegistredCommandsMap.find(command->getHashType());
            
        if(eventsCommandsNode)
    {
        qv::CommandArray commandsArray = eventsCommandsNode->getValue();
        
        for(u32 i = 0; i < commandsArray.size(); ++i)
        {
            qv::ICommand* c = static_cast<qv::ICommand*>(commandsArray[i]);
            if((c->getHashId() == command->getHashId()) && (c->getHashType() == command->getHashType()))
            {   
                commandsArray.erase(i);
                return true;
            }
        }
    }

    return false;
}
//-----------------------------------------------------------------------------------------
bool EventManager::enqueueEvent(qv::events::EventArgs* args)
{
    if(!validateType(args->getHashType()))
        return false;

    //check for a command listening this event
    qv::CommandMap::Node* nodeCommandsMap =
        mRegistredCommandsMap.find(args->getHashType());

    if(!nodeCommandsMap)
        return false;

    mReadyEvents[mActiveReadyEventList].push_back(args);

    return true;
}
//-----------------------------------------------------------------------------------------
bool EventManager::processReadyEvents()
{
    bool eventHandled = false;
    s32 processReadyEventList = mActiveReadyEventList;

    //------------------------------------------------------------
    //put all realtime generated events to our central event queue
    //IEventArgs* realtimeEvent(0);
    //while (!mRealtimeReadyEvents.empty() && mRealtimeReadyEvents.try_pop(realtimeEvent))
    //      enqueueEvent(realtimeEvent);
    //------------------------------------------------------------

    if(mActiveReadyEventList == 1)
        --mActiveReadyEventList;

    ++mActiveReadyEventList; //back to first one

    for(u32 i = 0; i < mReadyEvents[processReadyEventList].size(); ++i)
        eventHandled = trigger(mReadyEvents[processReadyEventList][i]);

    for(u32 i = 0; i < mReadyEvents[processReadyEventList].size(); ++i)
        mReadyEvents[processReadyEventList].pop_back();
    
    mReadyEvents[processReadyEventList].clear();
    
    return eventHandled;
}
//-----------------------------------------------------------------------------------------
bool EventManager::trigger(qv::events::EventArgs* args)
{
    if(!args || !validateType(args->getHashType()))
        return false;

    //iterate throw generic event listener, like a monitor to all events registred

    qv::CommandMap::Node* eventCommandNode =
        mRegistredCommandsMap.find(args->getHashType());

    if(!eventCommandNode)
        return false;

    bool eventHandled = false;

    const qv::CommandArray& commands = eventCommandNode->getValue();

    for(u32 i = 0; i < commands.size(); ++i)
    {
        ICommand* com = static_cast<qv::ICommand*>(commands[i]);
        com->executeCommand(args);
        eventHandled = true;
    }

    return eventHandled;
}
//-----------------------------------------------------------------------------------------
bool EventManager::validateType( u32 eventHashType)
{
    if(eventHashType <= 0)
        return false;

    qv::events::EventHashTypesArray::iterator itr;
    for(itr = mValidEventTypes.begin(); itr != mValidEventTypes.end(); ++itr)
        if((*itr) == eventHashType)
            return true;

    return false;
}
//-----------------------------------------------------------------------------------------

}

}

