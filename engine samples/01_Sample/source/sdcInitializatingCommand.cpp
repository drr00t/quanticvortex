
#include "sdcInitializatingCommand.h"



namespace sdc
{
namespace commands
{

InitializatingCommand::InitializatingCommand(qv::Game* gameApp)
        : //mCommandHashId(sdc::controller::CI_INITIALIZATING.Hash),
        mCommandHashType(qv::events::EET_GAME_LOGIC_INITIALIZATING.Hash),
        mGameApp(gameApp)
{

}

InitializatingCommand::~InitializatingCommand()
{

}

void InitializatingCommand::executeCommand(const qv::events::EventArgs *args)
{


}
//-----------------------------------------------------------------------------
}

}
