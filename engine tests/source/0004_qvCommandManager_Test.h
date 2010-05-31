#ifndef __COMMAND_MANAGER_TEST_H_
#define __COMMAND_MANAGER_TEST_H_

#include "UnitTest++.h"

#include "qvCommandManager.h"

class TestAddCommand: public qv::AbstractCommand
{
public:
    TestAddCommand( const qv::c8* commandName, const qv::CT_COMMAND_TYPE& commandType)
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
        
//        TestAddCommand command(1,"add_test",CT_TEST_ADD);
        
        qv::CommandManager commandManager;
        
        commandManager.registerCommandType(CT_TEST_ADD);
        
        qv::AbstractCommand* command = commandManager.createCommand<TestAddCommand>("add_test",CT_TEST_ADD);
        
        TestAddCommand *testCommand = static_cast<TestAddCommand*>(command);
        
        qv::CommandArgs* args = commandManager.createCommandArgs<qv::CommandArgs>(CT_TEST_ADD);
        
        //count increment
        commandManager.executeCommand(args);

        CHECK(testCommand->getValue() == 2);
    }
}


#endif // __SHASHED_STRING_TEST_H_
