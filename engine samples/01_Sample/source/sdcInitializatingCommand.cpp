
#include "sdcInitializatingCommand.h"
#include "qvEventArgs.h"
#include "qvEngineManager.h"
#include "qvEventTypes.h"



namespace sdc
{
namespace controller
{
    
InitializatingCommand::InitializatingCommand(qv::EngineManager* engineManager)
:mCommandHashId(sdc::controller::CI_INITIALIZATING.Hash),
mCommandHashType(qv::events::EET_GAME_LOGIC_INITIALIZATING.Hash),
mEngineManager(engineManager)
{
    
}

InitializatingCommand::~InitializatingCommand()
{

}

void InitializatingCommand::executeCommand(const qv::events::EventArgs *args)
{
    
//    mEventManager->
}
    //-----------------------------------------------------------------------------
}
}
