
#include "sdcInitializatingCommand.h"
#include "qvEventArgs.h"
#include "qvEventTypes.h"



namespace sdc
{
namespace controller
{
    
InitializatingCommand::InitializatingCommand()
:mCommandHashId(sdc::controller::CI_INITIALIZATING.Hash),
mCommandHashType(qv::events::EET_GAME_LOGIC_INITIALIZATING.Hash)
{
    
}

InitializatingCommand::~InitializatingCommand()
{

}

void InitializatingCommand::executeCommand(const qv::events::EventArgs *args)
{
//    mEngine->setQuit(true);
//    mEngine->getDevice()->getLogger()->log("quit event generated");
}
    //-----------------------------------------------------------------------------
}
}
