#ifndef __COMMAND_ARGS_TEST_H_
#define __COMMAND_ARGS_TEST_H_

#include "UnitTest++.h"

#include "qvCommandArgs.h"


// Commandargs test should stay here
SUITE(TestCommandArgs)
{
    //basic check type of CommandArgs
    TEST(TestCommandArgsType)
    {
        static const qv::CT_COMMAND_TYPE CT_TEST("TEST");

        qv::CommandArgs args(CT_TEST);

        CHECK(args.getType() == CT_TEST);
    }

    // derivation checking type of CommandArgs
    TEST(TestCommandArgsDerivationType)
    {
        class DeviredCommandArgs: public qv::CommandArgs
        {
        public:
            DeviredCommandArgs( const qv::CT_COMMAND_TYPE& commandType)
                    : qv::CommandArgs(commandType)
            {

            }
        };

        static const qv::CT_COMMAND_TYPE CT_DERIVED_TEST("DERIVED_TEST");

        DeviredCommandArgs derivedArgs(CT_DERIVED_TEST);

        CHECK(derivedArgs.getType() == CT_DERIVED_TEST);
    }

    // derivation and get value of CommandArgs
    TEST(TestCommandArgsDerivationValue)
    {
        class DerivedValueCommandArgs: public qv::CommandArgs
        {
        public:
            DerivedValueCommandArgs( qv::s32 value, const qv::CT_COMMAND_TYPE& commandType)
                    : qv::CommandArgs(commandType), mValue(value)
            {

            }
            
            ~DerivedValueCommandArgs()
            {
            }
            
            qv::s32 getValue()
            {
                return mValue;
            }
        
        private:
            qv::s32 mValue;

        };

        static const qv::CT_COMMAND_TYPE DERIVED_VALUE_TEST("DERIVED_VALUE_TEST");

        DerivedValueCommandArgs derivedValuArgs(2, DERIVED_VALUE_TEST);

        CHECK(derivedValuArgs.getValue() == 2);
    }
}


#endif // __SHASHED_STRING_TEST_H_
