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


#ifndef __COMMAND_MANAGER_H_
#define __COMMAND_MANAGER_H_

#include "qvCompileConfig.h"
#include "qvAbstractCommand.h"

#include "qvRAIIFactoryImp.h"


namespace qv
{

class _QUANTICVORTEX_API_ CommandManager
            /// event manager class class to raised event and execute all
            /// command associated to each one. EventCommand are listeners
{
public:
    CommandManager();
    virtual ~CommandManager();

    bool deleteCommand ( qv::AbstractCommand* command) const
    /// remove a command from listeners command type map
    {
        
//        mRegistredCommandsMap.erase(command->getType().Hash);
        {
//            mCommandsFactory.dispose(command);
            
            return true;
        }
        
        return false;
    }
    
    template <typename TCommand, typename TArgs> qv::AbstractCommand* createCommand( const qv::c8* commandName, const qv::CT_COMMAND_TYPE& commandType, TArgs* args)
        /// create command of TCommand type and get TArgs in your ctor to be used.
    {
         qv::AbstractCommand* command(0);

        if(validateCommandType(commandType))
        {
            qv::CommandsMapRangeResult itrResult = mRegistredCommandsMap.equal_range(commandType.Hash);

            for (CommandsMap::iterator itr = itrResult.first; itr != itrResult.second; itr++)
                if( itr->second->getId().Hash == qv::CI_COMMAND_ID(commandName).Hash)
                    return command;
            
            command = mCommandsFactory.keep(new TCommand(commandName, commandType, args));
           
            mRegistredCommandsMap.insert(CommandsMap::value_type( command->getType().Hash, command));
        }
        
        return command;
    }
    
    template <typename T> qv::CommandArgs* createCommandArgs( const qv::CT_COMMAND_TYPE& commandType)
        /// create command args for all registred command types.
    {
         qv::CommandArgs* args(0);

        if(validateCommandType(commandType))
            args = mCommandArgsFactory.keep(new T(commandType));

        return args;
    }
    
    /// create an EventArgs of specific type if this type
    /// is registred on event args factory.

    void registerCommandType( const qv::CT_COMMAND_TYPE& commandType);
    /// register a new event type to valid event types list
    
   
    bool validateCommandType(const qv::CT_COMMAND_TYPE& commandType);
    /// check this event if it is valid

//    void unregisterCommandType( const qv::CT_COMMAND_TYPE& commandType);
    /// remove an event type from event type list

    bool enqueueCommandArgs (qv::CommandArgs* args);
    /// post the event args to the raise queue

    bool executeCommands();
    /// raise all queued command args are executed

    bool executeCommand ( const qv::CommandArgs* args );
    /// execute all command listen this command args



private:

    CommandManager( const CommandManager&);
    CommandManager operator = ( const CommandManager&);

    static const s32 QueueCommandArgsLenght = 2; // double buffer queue
    qv::CommandTypesArray mValidCommandTypes; // registred valid event types
    qv::CommandsMap mRegistredCommandsMap; //
    qv::CommandArgsArray mReadyCommandArgs[QueueCommandArgsLenght]; //to event lists to double buffering
//    //	ConcurrentEventList mRealtimeReadyEvents; //this get high priority than mRadyEvents;
    RaiiFactoryImp<qv::AbstractCommand> mCommandsFactory;
    RaiiFactoryImp<qv::CommandArgs> mCommandArgsFactory; // create and control life cicle of command args
    qv::u32 mActiveReadyCommandArgsQueue;
    
};

}

#endif
