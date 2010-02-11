
#include "sdcQuitCommand.h"

#include "qvIEngineManager.h"


namespace sdc
{
    namespace controller
    {
		QuitCommand::QuitCommand(qv::IEngineManager *engine)
			:ICommandEvent(qv::CI_COMMAND_GAME_QUIT), mEngine(engine)
		{
			mEventTypes.push_back(qv::events::ET_GAME_QUIT);
		}

		QuitCommand::~QuitCommand()
		{
			mEventTypes.set_free_when_destroyed(false);
			mEventTypes.clear();
		}

		void QuitCommand::executeCommand(const qv::events::IEventArgs *args)
		{
			mEngine->setQuit(true);
			mEngine->getDevice()->getLogger()->log("quit event generated");
		}
		//-----------------------------------------------------------------------------
    }
}
