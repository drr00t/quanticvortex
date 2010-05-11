
#include "sdcSylfurDCGame.h"

#include "qvSGameParams.h"

#include "sdcQuitCommand.h"


namespace sdc
{
//------------------------------------------------------------------------------------------------
SylfurDCGame::SylfurDCGame()
{
    
//    each game screen can be a HumanView if it get user input
//    MainMenu - HumanView 
//        Scene
//        Gui
//    Running - is it a HumanView too
//        Scenes
//   the engine user can´t need access HumanView, he just need feed HumanView with 
// componente that it need like:
// - input mtranslators
// - ElementViews (scene, gui, etc)
// - Commands to respond to the game events
//
// gameLogic->addGameState(qv::gaming::S_GAME_STATE_INITIALIZATING)
// gameLogic->addGameState(qv::gaming::S_GAME_STATE_MENU)
// gameLogic->addGameState(qv::gaming::S_GAME_STATE_LOADING)
// gameLogic->addGameState(qv::gaming::S_GAME_STATE_WAITING_PLAYER)
// gameLogic->addGameState(qv::gaming::S_GAME_STATE_RUNNING)
// gameLogic->validateGameState()
// gameLogic->addCommand(InitializatingCommand())
// gameLogic->addCommand(InitializatingCommand())->executeCommand(InitializatingEventArgs)
// gameLogic->changeGameState(qv::gaming::S_GAME_STATE_INITIALIZATING)
// gameLogic->changeGameState(qv::gaming::S_GAME_STATE_INITIALIZATING)->trigger(InitializatingEventArgs)
// 

// gameLogic->addCommand()
// gameLogic->initPhysics() - this should be done inside of game logic
// gameLogic->addHumanView()
// gameLogic->addHumanView()->iniAudio() - this should be done inside of human view
// gameLogic->addHumanView()->addCommand()
// gameLogic->addHumanView()->attachPlayer()
// gameLogic->addHumanView()->getPlayer()->addInputTranslator()
// gameLogic->addHumanView()->addSceneView()
// gameLogic->addHumanView()->getSceneView()->loadScene() - 3d/2d scene
// gameLogic->addHumanView()->addGuiView()
// gameLogic->addHumanView()->getGuiView()->loadGui() fonts, windows, etc
// gameLogic->addHumanView()->getGuiView()->addWindow()
// gameLogic->addHumanView()->getGuiView()->addWindow()-addButton()
// gameLogic->addHumanView()->getGuiView()->addWindow()-addText()
    
}
//-----------------------------------------------------------------------------
SylfurDCGame::~SylfurDCGame()
{

}
//-----------------------------------------------------------------------------
//void SylfurDCGame::registerGameEvents()
//{
//    EngineManager::registerGameEvents();

//    //my events game events here
//}
//-----------------------------------------------------------------------------
/*  void SylfurDCGame::createGameAndView()
  {
  	mGameLogic = new SylfurDCLogic();
  	mGameLogic->grab();

  	//mEventManager->addListener(mGameLogic->getEventListener());

      mGameTitle = "Sylfur-D.C";

  	IGameView* gameView = new SylfurDCView(this);
      mGameLogic->addView(gameView);
  	gameView->drop();

      mGameLogic->changeState(qv::core::Initializing);

      //if (m_pOptions->m_gameHost.empty())
      //{
  	   // game = GCC_NEW TeapotWarsGame(*m_pOptions);
      //}
      //else
      //{
  	   // game = GCC_NEW TeapotWarsGameProxy(*m_pOptions);

  	   // EventListenerPtr listener ( GCC_NEW NetworkEventForwarder( 0 ) );
  	   // extern void ListenForTeapotGameCommands(EventListenerPtr listener);
  	   // ListenForTeapotGameCommands(listener);

      //}

      //shared_ptr<IGameView> menuView(GCC_NEW MainMenuView());
      //game->VAddView(menuView);

      //mGameLogic->addView(umaView); //menu, play view
  }
  */
}
