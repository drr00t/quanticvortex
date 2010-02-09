
#ifndef __SYLFUR_DC_GAME_H_
#define __SYLFUR_DC_GAME_H_

#include "qvQuanticVortex.h"


namespace sdc
{
	class SylfurDCGame //: public Game
    {
	private:
		qv::IEngineManager* mEngine;

    public:
	    SylfurDCGame();
		virtual ~SylfurDCGame();

		bool initialize();

		s32 run();

        //virtual bool loadGame();
        //virtual void createGameAndView();
    };
}

#endif

