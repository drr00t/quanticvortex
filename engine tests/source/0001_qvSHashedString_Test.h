#ifndef __SHASHED_STRING_TEST_H_
#define __SHASHED_STRING_TEST_H_

#include "UnitTest++.h"

#include "qvSHashedString.h"

TEST(TestSHashedString)
{
    qv::SHashedString hashString("testtype");
    
    CHECK((hashString.Hash != 0) && (hashString.Text == irr::core::stringc("testtype")));
}


#endif // __SHASHED_STRING_TEST_H_
