
#include "sdcRunningCommand.h"
#include "qvEventArgs.h"

namespace sdc
{
    namespace controller
    {
        
		RunningCommand::RunningCommand()
		{
		}
		//-----------------------------------------------------------------------------
		RunningCommand::~RunningCommand()
		{
		}
		//-----------------------------------------------------------------------------
		void RunningCommand::executeCommand(const qv::events::EventArgs *args)
		{
//			mEngine->setQuit(true);
//			mEngine->getDevice()->getLogger()->log("quit event generated");
		}
		//-----------------------------------------------------------------------------
    }
}
