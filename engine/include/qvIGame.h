
#ifndef __I_GAME_H_
#define __I_GAME_H_

#include "qvIEngineManager.h"


namespace qv
{
	class IGame: public IReferenceCounted
    {

	public:

		virtual ~IGame()
		{
			mEngine->drop();
		}

		virtual void loadConfiguration(){}
		virtual s32 run(s32 argc, c8* argv[])=0;

	protected:
		void createEngine()
		{
			//mParams.Bits = 32;
			//mParams.Fullscreen = false;
			//mParams.Title = "Sylfur D.C. - Dimencional Chronical";
			//mParams.Vsync = false;
			//mParams.WindowSize.Width = 1280;
			//mParams.WindowSize.Height = 800;

			//mEngine = qv::createEngineManagerEx(mParams);
		}

		void configureEvents(){}
		void configureCommands(){}
		void configureInputTranslator(){}
		void configureGameStates(){}

		qv::SGameParams mParams;
		IEngineManager* mEngine;
    };
}
#endif

