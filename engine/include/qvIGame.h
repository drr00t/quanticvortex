
#ifndef __I_GAME_H_
#define __I_GAME_H_

#include "qvIEngineManager.h"


namespace qv
{
	class IGame: public IReferenceCounted
    {

	public:
		IGame()
		{
		}
		virtual ~IGame()
		{
		}

		void loadConfiguration()=0;
		void run(s32 argc, c8* argv[])=0;

	protected:
		void configureEvents()=0;
		void configureCommands()=0;
		void configureInputTranslator()=0;
		void configureGameStates()=0;


		IEngineManager* mEngine;
    };
}
#endif

