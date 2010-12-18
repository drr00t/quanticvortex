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
CommandManager::CommandManager(qv::Game* game)
    : mActiveReadyCommandArgsQueue(0), mGame(game)
{

}
//-----------------------------------------------------------------------------------------
CommandManager::~CommandManager()
{
}
//-----------------------------------------------------------------------------------------
void CommandManager::addCommand(const qv::CT_COMMAND_TYPE& commandType)
{
	qv::AbstractCommand* command(0);
	
	if(validateCommandType(commandType))
	{
//		qv::CommandsMapRangeResult itrResult = mRegistredCommandsMap.equal_range(commandType.Hash);
//
//		for (CommandsMap::iterator itr = itrResult.first; itr != itrResult.second; itr++)
//		{
//			command = static_cast<qv::AbstractCommand*>(itr->second);
//			if( command->getType() == commandType)
//				return;
//		}
		
		command = findCommand(commandType);
		
		if(command)
			return;
		
		qv::CommandFactoriesMap::iterator itr = mRegistredCommandsFactoryMap.find(commandType.Hash);

		if (itr != mRegistredCommandsFactoryMap.end())
			command = itr->second->create(mGame);
	   
		mRegistredCommandsMap.insert(qv::CommandsMap::value_type( commandType.Hash, command));
	}
}
//-----------------------------------------------------------------------------------------
void CommandManager::removeCommand(const qv::CT_COMMAND_TYPE& commandType)
{

		qv::CommandsMap::iterator itr = mRegistredCommandsMap.find(commandType.Hash);

		if (itr != mRegistredCommandsMap.end())
		{
			delete itr->second;
			mRegistredCommandsMap.erase(itr);
		}
}
//-----------------------------------------------------------------------------------------
qv::AbstractCommand* CommandManager::findCommand(const qv::CT_COMMAND_TYPE& commandType)
{
	qv::CommandsMap::iterator itr = mRegistredCommandsMap.find(commandType.Hash);
	qv::AbstractCommand* command(0);
	
	if(itr != mRegistredCommandsMap.end())
		command = itr->second;
		
	return command;
}
//-----------------------------------------------------------------------------------------
void CommandManager::addCommandFactory(const qv::CT_COMMAND_TYPE& commandType, qv::AbstractCommandFactory* commandFactory)
{
	// i should rise an error here, or quietly return without add factory?
	if(!validateCommandType(commandType))
		return;
		
	qv::CommandFactoriesMap::iterator itr = mRegistredCommandsFactoryMap.find(commandType.Hash);
	
	if(itr == mRegistredCommandsFactoryMap.end())
		mRegistredCommandsFactoryMap.insert(qv::CommandFactoriesMap::value_type(commandType.Hash,commandFactory));
}
//-----------------------------------------------------------------------------------------
void CommandManager::removeCommandFactory(const qv::CT_COMMAND_TYPE& commandType)
{
	qv::CommandFactoriesMap::iterator itr = mRegistredCommandsFactoryMap.find(commandType.Hash);
	
	if(itr != mRegistredCommandsFactoryMap.end())
	{
		delete itr->second;
		mRegistredCommandsFactoryMap.erase(itr);
	}
}
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
        if(commandType == mValidCommandTypes.at(i))
            return true;
    return false;
}
//-----------------------------------------------------------------------------------------
//bool EventManager::abortEvent( u32 eventHashType)
//{
//    return true;
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
//        qv::CommandsMapRangeResult itrResult = 
//            mRegistredCommandsMap.equal_range(mReadyCommandArgs[processReadyCommandArgsQueue][i]->getType().Hash);

//        for (CommandsMap::iterator itr = itrResult.first; itr != itrResult.second; ++itr)
//        {
//            itr->second->executeCommand(mReadyCommandArgs[processReadyCommandArgsQueue][i]);
//            eventHandled = true;
//        }

		qv::AbstractCommand* command = findCommand(mReadyCommandArgs[processReadyCommandArgsQueue][i]->getType());
		
		if(command)
		{
			command->executeCommand(mReadyCommandArgs[processReadyCommandArgsQueue][i]);
			eventHandled = true;
		}
        
        mCommandArgsFactory.dispose(mReadyCommandArgs[processReadyCommandArgsQueue][i]);
    }
    
    mReadyCommandArgs[QueueCommandArgsLenght].clear();
    
    return eventHandled;
}
////-----------------------------------------------------------------------------------------
bool CommandManager::executeCommand(const qv::CommandArgs* args)
{
    bool eventHandled = false;
//    qv::CommandsMapRangeResult itrResult = mRegistredCommandsMap.equal_range(args->getType().Hash);
//
//    for (CommandsMap::iterator itr = itrResult.first; itr != itrResult.second; ++itr)
//    {
//        itr->second->executeCommand(args);
//        eventHandled = true;
//    }
	qv::AbstractCommand* command = findCommand(args->getType());
	
	if(command)
	{
        command->executeCommand(args);
        eventHandled = true;		
	}

    mCommandArgsFactory.dispose(args);
   
    return eventHandled;
}
////-----------------------------------------------------------------------------------------

}
