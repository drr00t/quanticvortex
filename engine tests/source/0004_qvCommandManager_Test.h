#ifndef __COMMAND_MANAGER_TEST_H_
#define __COMMAND_MANAGER_TEST_H_

#include "UnitTest++.h"

#include "qvCommandManager.h"

class TestAddCommand: public qv::AbstractCommand
{
public:
    TestAddCommand( const qv::c8* commandName, const qv::CT_COMMAND_TYPE& commandType, qv::s32* startCount)
            : qv::AbstractCommand(commandName, commandType), mCount(1)
    {

    }

    virtual void executeCommand(const qv::CommandArgs* args)
    {
        mCount++;
    }
    
    qv::s32 getValue() const
    {
        return mCount;
    }

private:
    qv::s32 mCount;

};

class TestAddCommandSub: public qv::AbstractCommand
{
public:
    TestAddCommandSub( const qv::c8* commandName, const qv::CT_COMMAND_TYPE& commandType, qv::s32* startCount)
            : qv::AbstractCommand(commandName, commandType), mCount(1)
    {

    }

    virtual void executeCommand(const qv::CommandArgs* args)
    {
        mCount--;
    }
    
    qv::s32 getValue() const
    {
        return mCount;
    }

private:
    qv::s32 mCount;

};

// Commandargs test should stay here
SUITE(TestsCommandManager)
{
    //basic definition of CommandArgs
    TEST(TestCommandManagerCreateCommandArgs)
    {
        static const qv::CT_COMMAND_TYPE CT_TEST_ADD("CT_TEST_ADD");
                
        qv::CommandManager commandManager;
        
        commandManager.registerCommandType(CT_TEST_ADD);
        
        qv::CommandArgs* args = commandManager.createCommandArgs<qv::CommandArgs>(CT_TEST_ADD);

        CHECK(args->getType() == CT_TEST_ADD);
    }
    
    //basic definition of CommandArgs
    TEST(TestCommandManagerCommandArgsRegisterAndValidate)
    {
        static const qv::CT_COMMAND_TYPE CT_TEST("TEST");
       
        qv::CommandManager commandManager;
        
        commandManager.registerCommandType(CT_TEST);

        CHECK(commandManager.validateCommandType(CT_TEST));
    }
    
    //basic definition of CommandArgs
    TEST(TestCommandManagerAddCommandAndExecute)
    {
        static const qv::CT_COMMAND_TYPE CT_TEST_ADD("CT_TEST_ADD");
        
        qv::CommandManager commandManager;
        
        commandManager.registerCommandType(CT_TEST_ADD);
        
        qv::s32* param = new qv::s32(1);
        qv::s32* result = new qv::s32(2);
        
        qv::AbstractCommand* command = commandManager.createCommand<TestAddCommand, qv::s32>("add_test",CT_TEST_ADD, param);
        
        TestAddCommand *testCommand = static_cast<TestAddCommand*>(command);
        
        qv::CommandArgs* args = commandManager.createCommandArgs<qv::CommandArgs>(CT_TEST_ADD);
        
        //count increment
        commandManager.executeCommand(args);

        CHECK(testCommand->getValue() == *result);
        
        delete param;
        delete result;
    }
    
    //basic definition of CommandArgs
    TEST(TestCommandManagerEnqueueCommandAndExecuteAll)
    {
        static const qv::CT_COMMAND_TYPE CT_TEST_ADD("CT_TEST_ADD");
        static const qv::CT_COMMAND_TYPE CT_TEST_SUB("CT_TEST_SUB");
        
        qv::CommandManager commandManager;
        
        commandManager.registerCommandType(CT_TEST_ADD);
        commandManager.registerCommandType(CT_TEST_SUB);
        
        qv::s32* paramAdd = new qv::s32(1);
        qv::s32* paramSub = new qv::s32(1);
        qv::s32* resultAdd = new qv::s32(2);
        qv::s32* resultSub = new qv::s32(0);
        
        qv::AbstractCommand* commandAdd = commandManager.createCommand<TestAddCommand, qv::s32>( "add_test", CT_TEST_ADD, paramAdd);
        qv::AbstractCommand* commandSub = commandManager.createCommand<TestAddCommandSub, qv::s32>( "sub_test", CT_TEST_SUB, paramSub);
        
        qv::CommandArgs* argsAdd = commandManager.createCommandArgs<qv::CommandArgs>(CT_TEST_ADD);
        qv::CommandArgs* argsSub = commandManager.createCommandArgs<qv::CommandArgs>(CT_TEST_SUB);
               
        commandManager.enqueueCommandArgs(argsAdd);
        commandManager.enqueueCommandArgs(argsSub);
        
        commandManager.executeCommands();
        
        TestAddCommand* testCommandAdd = static_cast<TestAddCommand*>(commandAdd);
        TestAddCommandSub* testCommandSub = static_cast<TestAddCommandSub*>(commandSub);
        
        CHECK((testCommandAdd->getValue() == *resultAdd) && (testCommandSub->getValue() == *resultSub));
        
        delete paramAdd;
        delete paramSub;
        delete resultAdd;
        delete resultSub;
    }
    
        //basic definition of CommandArgs
    TEST(TestCommandManagerDeleteCommand)
    {
        static const qv::CT_COMMAND_TYPE CT_TEST_ADD("CT_TEST_ADD");
        
        qv::CommandManager commandManager;
        
        commandManager.registerCommandType(CT_TEST_ADD);
        
        qv::s32* param = new qv::s32(1);
        qv::s32* result = new qv::s32(2);
        
        qv::AbstractCommand* command = commandManager.createCommand<TestAddCommand, qv::s32>("add_test",CT_TEST_ADD, param);
        
        TestAddCommand *testCommand = static_cast<TestAddCommand*>(command);
        
        qv::CommandArgs* args = commandManager.createCommandArgs<qv::CommandArgs>(CT_TEST_ADD);
        
        //count increment
        commandManager.executeCommand(args);
               

        CHECK(commandManager.deleteCommand(command));
        
        delete param;
        delete result;
    }
}


#endif // __SHASHED_STRING_TEST_H_
