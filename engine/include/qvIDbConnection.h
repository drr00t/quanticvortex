
#ifndef __I_GAME_H_
#define __I_GAME_H_

#include "qvIEngineManager.h"

namespace qv
{
	class IGame: public IReferenceCounted
    {

	public:
		void loadConfiguration()=0;
		void run(s32 argc, c8* argv[])=0;

	protected:
		bool addEvent()=0;
		void addCommand()=0;
		void addInputTranslator()=0;
		void addState()=0;
    };
}
#endif

