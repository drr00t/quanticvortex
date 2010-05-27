#ifndef __COMMAND_ARGS_TEST_H_
#define __COMMAND_ARGS_TEST_H_

#include "UnitTest++.h"

#include "qvCommandArgs.h"

TEST(TestCommandArgs)
{
    static const qv::CT_COMMAND_TYPE CT_TEST("TEST");
    
    qv::CommandArgs args(CT_TEST);
    
    CHECK(args.getType() == CT_TEST);
}


#endif // __SHASHED_STRING_TEST_H_
