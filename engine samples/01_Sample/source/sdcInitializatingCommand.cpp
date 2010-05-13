
#include "sdcInitializatingCommand.h"
#include "qvAbstractGameView.h"
#include "qvEventArgs.h"
#include "qvGame.h"
#include "qvEventTypes.h"



namespace sdc
{
namespace controller
{
    
InitializatingCommand::InitializatingCommand(qv::Game* gameApp)
:mCommandHashId(sdc::controller::CI_INITIALIZATING.Hash),
mCommandHashType(qv::events::EET_GAME_LOGIC_INITIALIZATING.Hash),
mGameApp(gameApp)
{
    
}

InitializatingCommand::~InitializatingCommand()
{

}

void InitializatingCommand::executeCommand(const qv::events::EventArgs *args)
{
    
//    mEventManager->
     qv::views::AbstractGameView* view = 
        mGameApp->getGameLogic()->addView("MainView", qv::views::GVT_GAME_VIEW_HUMAN.Hash,0);
        
    static_cast<qv::views::HumanView*>(view)->

}
    //-----------------------------------------------------------------------------
}
}
