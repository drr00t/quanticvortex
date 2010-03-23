#include "UnitTest++.h"
#include "TestReporterStdout.h"

TEST( HelloUnitTestPP )
{

   CHECK( true );

}

int main(int, char const *[])
{
    return UnitTest::RunAllTests();
}
