#ifndef __ABSTRACT_COMMAND_TEST_H_
#define __ABSTRACT_COMMAND_TEST_H_

#include "UnitTest++.h"
#include "qvAbstractCommand.h"



// Commandargs test should stay here
SUITE(TestsAbstractCommand)
{
    //basic definition of CommandArgs
    TEST(TestAbstractCommandId)
    {
        class TestIdCommand: public qv::AbstractCommand
        {
        public:
            TestIdCommand(const qv::c8* commandName, const qv::CT_COMMAND_TYPE& commandType)
                    : qv::AbstractCommand(commandName, commandType)
            {

            }

            virtual void executeCommand(const qv::CommandArgs* args){}

        };

        static const qv::CT_COMMAND_TYPE CT_TEST_ID("CT_TEST_ID");
        static const qv::CI_COMMAND_ID CI_TEST_ID_01("test_command_01");

        qv::AbstractCommand* command = new TestIdCommand( "test_command_01", CT_TEST_ID);

        CHECK(command->getId() == CI_TEST_ID_01);
    }
    
    //basic definition of CommandArgs
    TEST(TestAbstractCommandType)
    {
        class TestTypeCommand: public qv::AbstractCommand
        {
        public:
            TestTypeCommand(const qv::c8* commandName, const qv::CT_COMMAND_TYPE& commandType)
                    : qv::AbstractCommand(commandName, commandType)
            {

            }

            virtual void executeCommand(const qv::CommandArgs* args){}

        };

        static const qv::CT_COMMAND_TYPE CT_TEST_TYPE("TEST_TYPE");
        static const qv::CI_COMMAND_ID CI_TEST_TYPE_01("test_command_01");

        qv::AbstractCommand* command = new TestTypeCommand( "test_command_01", CT_TEST_TYPE);

        CHECK(command->getType() == CT_TEST_TYPE);
    }

    TEST(TestAbstractCommandExecuteCommand)
    {
        class TestExecuteCommand: public qv::AbstractCommand
        {
        public:
            TestExecuteCommand(qv::s32 startCount, const qv::c8* commandName, const qv::CT_COMMAND_TYPE& commandType)
                    : qv::AbstractCommand(commandName, commandType), mCurrentCount(startCount)
            {

            }

            qv::s32 getCurrentCount() const
            {
                return mCurrentCount;
            }
            
            virtual void executeCommand(const qv::CommandArgs* args)
            {
                mCurrentCount++;
            }

        private:
            qv::s32 mCurrentCount;

        };

        static const qv::CT_COMMAND_TYPE CT_TEST_EXECUTE("CT_TEST_EXECUTE");
        static const qv::CI_COMMAND_ID CI_TEST_EXECUTE("test_execute_command_01");

        TestExecuteCommand* command = new TestExecuteCommand( 1, "test_execute_command_01", CT_TEST_EXECUTE);
        
        const qv::CommandArgs* args = new qv::CommandArgs(CT_TEST_EXECUTE);
        command->executeCommand(args);
        
        CHECK(command->getCurrentCount() == 2);
    }
}


#endif // __SHASHED_STRING_TEST_H_
