
#include "qvTypes.h"
//#include "sdcSylfurDCGame.h"

#include <windows.h>
#include <list>
#include <iostream>

qv::s32 main(qv::s32 argc, qv::c8 *argv[])
{
    //sdc::SylfurDCGame game;

    std::list<int*> ints;

    for(int i = 0; i < 5; i++)
    {
        int* in = new int();
        in = &i;
        ints.push_back(in);
        std::cout << *in << std::endl;
    }
    for(int i = 0; i < ints.size(); i++)
    {
        int* um = ints.back();

        ints.pop_back();

        std::cout << *um << std::endl;
    }

//    system("pause");

    return 0;//game.run( argc, argv);
}



