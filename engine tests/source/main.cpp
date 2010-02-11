#include "UnitTest++.h"
#include "TestReporterStdout.h"

TEST( HelloUnitTestPP )
{

   CHECK( false );

}

int main(int, char const *[])
{
    return UnitTest::RunAllTests();
}
