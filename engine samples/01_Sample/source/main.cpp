
//#include "game/Game.h"
#include "sdcSylfurDCGame.h"

s32 main(s32 argc, c8 *argv[])
{
    sdc::SylfurDCGame game;
    
	if(game.initialize())
		return game.run( argc, argv); //game.main(argc,argv);
	return -1;
}



