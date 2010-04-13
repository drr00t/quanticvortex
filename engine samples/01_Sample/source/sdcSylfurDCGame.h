
#ifndef __SYLFUR_DC_GAME_H_
#define __SYLFUR_DC_GAME_H_

#include "qvQuanticVortex.h"


namespace sdc
{
	class SylfurDCGame
    {
    public:
	    SylfurDCGame();
		virtual ~SylfurDCGame();

		bool initialize();

		qv::s32 run(qv::s32 argc, qv::c8* argv[]);
        
	private:
		qv::IEngineManager* mEngine;
};
}

#endif

