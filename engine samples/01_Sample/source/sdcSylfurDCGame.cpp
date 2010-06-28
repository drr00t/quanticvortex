
#include "sdcSylfurDCGame.h"

#include "qvHumanView.h"

//command args
#include "qvSceneLoadCommandArgs.h"


namespace sdc
{
//------------------------------------------------------------------------------------------------
SylfurDCGame::SylfurDCGame()
{
    qv::views::HumanView* humanView = qv::Game::addHumanView("player_view");
//    humanView->attach(humanView->getId())
//    qv::Game::load("media/","media/Mygame.zip");
//    humanView
}
//-----------------------------------------------------------------------------
SylfurDCGame::~SylfurDCGame()
{

}
//-----------------------------------------------------------------------------
}
