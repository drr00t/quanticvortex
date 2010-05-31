
//#include "sdcSylfurDCGame.h"
#include "LinearMath/btQuickprof.h"  // bullet timer

#include "qvAbstractCommand.h"

#include <algorithm>
#include <vector>
#include <tr1/unordered_map>
#include <iostream>

static const qv::CT_COMMAND_TYPE CT_TEST_01("CT_TEST_01");
static const qv::CT_COMMAND_TYPE CT_TEST_02("CT_TEST_02");
static const qv::CT_COMMAND_TYPE CT_TEST_03("CT_TEST_03");
static const qv::CT_COMMAND_TYPE CT_TEST_04("CT_TEST_04");
static const qv::CT_COMMAND_TYPE CT_TEST_05("CT_TEST_05");

class Test : public qv::AbstractCommand
{
public:
    Test(int num, const qv::c8* name, const qv::CT_COMMAND_TYPE& type)
    :qv::AbstractCommand(name, type), 
    mNum(num)
    {}
    
    ~Test()
    {}

    void executeCommand( const qv::CommandArgs* args)
    {
        mNum++;
    }
    
    int mNum;
};

struct eqstr
{
  bool operator()(const qv::u32* a, const qv::u32* b) const
  {
    return (a == b);
  }
};

typedef std::pair<qv::u32, Test*> TestNode;
typedef std::tr1::unordered_multimap<qv::u32, Test*> TestMultimap;


bool CompararTest( TestNode* a, TestNode* b )
{
    return ((*a->second).getType().Hash > (*b->second).getType().Hash) ||
            (((*a->second).getType().Hash == (*b->second).getType().Hash) &&
                ((*a->second).getId().Hash > (*b->second).getId().Hash));
};




int main(int argc, char* argv[])
{
//    sdc::SylfurDCGame game;
//
//    return game.run(argc, argv);
// 
    btClock clock;
    
    typedef std::vector<TestNode*> TestArray;
    TestArray arrTest;
    TestMultimap multmapTest;
    

    multmapTest.insert(TestMultimap::value_type( CT_TEST_01.Hash, new Test(1,"teste_id_1", CT_TEST_01)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_02.Hash, new Test(10,"teste_id_10", CT_TEST_02)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_03.Hash, new Test(2,"teste_id_2", CT_TEST_03)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_04.Hash, new Test(20,"teste_id_20", CT_TEST_04)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_05.Hash, new Test(3,"teste_id_3", CT_TEST_05)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_01.Hash, new Test(30,"teste_id_30", CT_TEST_01)));
    
    multmapTest.insert(TestMultimap::value_type( CT_TEST_01.Hash, new Test(1,"teste_id_100", CT_TEST_01)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_02.Hash, new Test(10,"teste_id_1000", CT_TEST_02)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_03.Hash, new Test(2,"teste_id_200", CT_TEST_03)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_04.Hash, new Test(20,"teste_id_2000", CT_TEST_04)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_05.Hash, new Test(3,"teste_id_300", CT_TEST_05)));
    multmapTest.insert(TestMultimap::value_type( CT_TEST_01.Hash, new Test(30,"teste_id_3000", CT_TEST_01)));    
    
    clock.getTimeMilliseconds();

    std::cout 
            << "count: " << multmapTest.count(CT_TEST_01.Hash);

    std::cout << std::endl <<  "finding: " << clock.getTimeMilliseconds() << std::endl;
    std::pair<TestMultimap::iterator,TestMultimap::iterator> itrResult = multmapTest.equal_range(CT_TEST_01.Hash);
    

    std::cout << std::endl <<  "finded: " << clock.getTimeMilliseconds()  << std::endl;

    std::cout << std::endl <<  "start: " << clock.getTimeMilliseconds()  << std::endl;
 
    for (TestMultimap::iterator it = itrResult.first; it != itrResult.second; it++)
    {
        it->second->executeCommand(NULL);
        std::cout 
                << "type: " << it->first 
                << "  <==>  Id: " << it->second->getId().Hash
                << "  data: " << it->second->mNum
                << "      [Time: " << clock.getTimeMilliseconds() << "]" << std::endl;
    }
}



