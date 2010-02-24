
#include "sdcSylfurDCGame.h"

#include "qvSGameParams.h"
#include "qvIHumanView.h"

#include "sdcQuitCommand.h"

namespace sdc
{
	namespace input
	{
		qv::input::IT_INPUT_TRANSLATOR_ID* IT_QUIT_TRANSLATOR = new qv::input::IT_INPUT_TRANSLATOR_ID("IT_QUIT_TRANSLATOR");
	}
}

namespace sdc
{
	//------------------------------------------------------------------------------------------------
    SylfurDCGame::SylfurDCGame()
    {

        qv::SGameParams params;

        params.Bits = 32;
        params.Fullscreen = false;
        params.Title = "Sylfur D.C. - Dimencional Chronical";
        params.Vsync = false;
        params.WindowSize.Width = 800;
        params.WindowSize.Height = 600;

        mEngine = qv::createEngineManagerEx(params);
    }
    //-----------------------------------------------------------------------------
    SylfurDCGame::~SylfurDCGame()
    {
		mEngine->drop();
    }
    //-----------------------------------------------------------------------------
	bool SylfurDCGame::initialize()
    {
		bool initialized = mEngine->initialize();

		if(!initialized)
			return false;

		qv::gaming::IGameLogic* gameLogic = mEngine->addGameLogic();
		qv::gaming::AI_ACTOR_ID* playerID = new qv::gaming::AI_ACTOR_ID("PlayerID");
        qv::views::IHumanView* view = gameLogic->addHumanView("SylfurDCView", playerID);
		
		// start my sample
		//i really don´t need create event args my self, i just need pass event type that i want to my translator
		//internally the translator will create the event args using there onw eventManager pointer and feed the 
		//even args with the correct arguments, like this:
		qv::input::ISingleKeyInputTranslator* quit = 
			mEngine->getInputReceiver()->addSingleKeyTranslator(input::IT_QUIT_TRANSLATOR, irr::KEY_ESCAPE, 
													qv::input::EKS_PRESSED_OR_DOWN, qv::events::ET_GAME_QUIT, true);
		// end my sample


		// now i need create the command get this event when fired
		qv::events::ICommandEvent* command = new controller::QuitCommand(mEngine);
		mEngine->getEventManager()->registerCommandEvent(command);
		
		//state 

		//registrar o translator no receiver
		//registrar o command para o event QUIT
		qv::views::IElementView* sceneView = view->addElementView("DefaultScene",qv::views::EVT_ELEMENT_VIEW_SCENE);
		qv::views::ISceneView* scene = static_cast<qv::views::ISceneView*>(sceneView);
		//scene->loadScene("../../../media/syenval-v2.zip");
		scene->loadScene("../../../media/irrb-0.4.zip");

        //MygameStatesFactory factory = new MygameStatesFactory(gameLogic);
        //gameLogic->registerGameStateFactory(factory);
        //factory->drop();

        //IGameState* state = gameLogic->addGameState(type);

		return initialized;
    }
    //-----------------------------------------------------------------------------
	s32 SylfurDCGame::run(s32 argc, c8* argv[])
	{
		return mEngine->run();
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
