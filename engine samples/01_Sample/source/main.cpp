
#include "qvTypes.h"
#include "sdcSylfurDCGame.h"


qv::s32 main(s32 argc, qv::c8 *argv[])
{
    sdc::SylfurDCGame game;

	if(game.initialize())
		return game.run( argc, argv); //game.main(argc,argv);
}



