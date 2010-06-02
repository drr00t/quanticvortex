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


#include "qvCommandManager.h"


namespace qv
{
//-----------------------------------------------------------------------------------------
CommandManager::CommandManager()
    : mActiveReadyCommandArgsQueue(0)
{

}
//-----------------------------------------------------------------------------------------
CommandManager::~CommandManager()
{
}
//-----------------------------------------------------------------------------------------
//bool CommandManager::addCommand(qv::AbstractCommand* command)
//{
//    if(!validateCommandType(command->getType()))
//        return false;
//    
//    qv::CommandsMapRangeResult itrResult = mRegistredCommandsMap.equal_range(command->getType().Hash);
//
//    for (CommandsMap::iterator itr = itrResult.first; itr != itrResult.second; itr++)
//        if( itr->second->getId().Hash == command->getId().Hash)
//            return false;
//    
//    mRegistredCommandsMap.insert(CommandsMap::value_type( command->getType().Hash, command));
    
//    return true;    
//}
//-----------------------------------------------------------------------------------------
void CommandManager::registerCommandType(const qv::CT_COMMAND_TYPE& commandType)
{

#ifdef _DEBUG
    if((commandType.Hash <= 0) || (commandType.Text.size() == 0))
        return;
#else
    if(commandType.Hash <= 0)
        return;
#endif

    if(!validateCommandType(commandType))
        mValidCommandTypes.push_back(commandType);
}
//-----------------------------------------------------------------------------------------
bool CommandManager::validateCommandType(const qv::CT_COMMAND_TYPE& commandType)
{
    for(u32 i = 0;i < mValidCommandTypes.size(); i++)
        if(commandType == mValidCommandTypes[i])
            return true;
    return false;
}
//////-----------------------------------------------------------------------------------------
////void EventManager::registerEventArgsFactory(IEventArgsFactory* factory)
////{
////}
////-----------------------------------------------------------------------------------------
//bool EventManager::abortEvent( u32 eventHashType)
//{
//    return true;
//}
////-----------------------------------------------------------------------------------------
//bool EventManager::removeCommand(qv::ICommand* command)
//{
//    return false;
//}
////-----------------------------------------------------------------------------------------
bool CommandManager::enqueueCommandArgs(qv::CommandArgs* args)
{
    if(!validateCommandType(args->getType()))
        return false;

    //check for a command listening this event
    qv::CommandsMap::iterator itr =
        mRegistredCommandsMap.find(args->getType().Hash);

    if(itr == mRegistredCommandsMap.end())
        return false;

    mReadyCommandArgs[mActiveReadyCommandArgsQueue].push_back(args);

    return true;
}
////-----------------------------------------------------------------------------------------
bool CommandManager::executeCommands()
{
    bool eventHandled = false;
    s32 processReadyCommandArgsQueue = mActiveReadyCommandArgsQueue;

    //------------------------------------------------------------
    //put all realtime generated events to our central event queue
    //IEventArgs* realtimeEvent(0);
    //while (!mRealtimeReadyEvents.empty() && mRealtimeReadyEvents.try_pop(realtimeEvent))
    //      enqueueEvent(realtimeEvent);
    //------------------------------------------------------------

    if(mActiveReadyCommandArgsQueue == 1)
        --mActiveReadyCommandArgsQueue;

    ++mActiveReadyCommandArgsQueue; //back to first one
    
    for (qv::u32 i = 0; i < mReadyCommandArgs[processReadyCommandArgsQueue].size(); i++)
    {
        qv::CommandsMapRangeResult itrResult = 
            mRegistredCommandsMap.equal_range(mReadyCommandArgs[processReadyCommandArgsQueue][i]->getType().Hash);

        for (CommandsMap::iterator itr = itrResult.first; itr != itrResult.second; itr++)
        {
            itr->second->executeCommand(mReadyCommandArgs[processReadyCommandArgsQueue][i]);
            eventHandled = true;
        }
    }
    
    mReadyCommandArgs[QueueCommandArgsLenght].clear();
    
    return eventHandled;
}
////-----------------------------------------------------------------------------------------
bool CommandManager::executeCommand(const qv::CommandArgs* args)
{
    bool eventHandled = false;
    qv::CommandsMapRangeResult itrResult = mRegistredCommandsMap.equal_range(args->getType().Hash);

    for (CommandsMap::iterator itr = itrResult.first; itr != itrResult.second; itr++)
    {
        itr->second->executeCommand(args);
        eventHandled = true;
    }

    mCommandArgsFactory.dispose(args);
   
    return eventHandled;
}
////-----------------------------------------------------------------------------------------

}
