
#include "sdcInitializatingCommand.h"
#include "qvEventArgs.h"
#include "qvEventManager.h"
#include "qvEventTypes.h"



namespace sdc
{
namespace controller
{
    
InitializatingCommand::InitializatingCommand(qv::events::EventManager* eventManager)
:mCommandHashId(sdc::controller::CI_INITIALIZATING.Hash),
mCommandHashType(qv::events::EET_GAME_LOGIC_INITIALIZATING.Hash),
mEventManager(eventManager)
{
    
}

InitializatingCommand::~InitializatingCommand()
{

}

void InitializatingCommand::executeCommand(const qv::events::EventArgs *args)
{
    
    // mEventManager->trigger()
}
    //-----------------------------------------------------------------------------
}
}
