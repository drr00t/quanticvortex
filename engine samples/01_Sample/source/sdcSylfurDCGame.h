
#ifndef __SYLFUR_DC_GAME_H_
#define __SYLFUR_DC_GAME_H_

#include "qvQuanticVortex.h"


namespace sdc
{
	class SylfurDCGame //: public qv::IGame
    {
	private:
		qv::IEngineManager* mEngine;

    public:
	    SylfurDCGame();
		virtual ~SylfurDCGame();

		bool initialize();

		s32 run(s32 argc, c8* argv[]);
    };
}

#endif

