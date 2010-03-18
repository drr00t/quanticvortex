
//#include "game/Game.h"
#include "sdcSylfurDCGame.h"

typedef struct teste
{
    int ind;
    char c;
}STeste;

s32 main(s32 argc, c8 *argv[])
{
    STeste* t = new STeste();

    t->c = 'e';
    t->ind = 10;

    sdc::SylfurDCGame game;

	if(game.initialize())
		return game.run( argc, argv); //game.main(argc,argv);

    delete t;
}



