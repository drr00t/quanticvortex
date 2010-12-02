/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009-2010 QuanticMinds Software Ltda.
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

**************************************************************************************************/


#include "qvGame.h"

#include <vector>
#include <algorithm>

// external classes
#include "LinearMath/btQuickprof.h"  // bullet timer

#include "qvGetopt.h"


// engine headers
#include "qvCommandManager.h"
#include "qvGameLogic.h"
#include "qvAddinManager.h"




namespace qv
{

Game::Game()
	: mQuit(false)
{
	if (!initialize())
		mQuit = true;
}

Game::~Game()
{
	finalize();
}
//-----------------------------------------------------------------------------
bool Game::initialize()
{
	//pre allocate 5 slots for views
	mGameViews.reserve(5);

	loadConfiguration(); // load default configuration files, if present

	mCommandManager = new qv::CommandManager();
	mGameLogic = new qv::gaming::GameLogic(this);
	mAddinManager = new qv::AddinManager(this);
//	mInputReceiver = new qv::input::InputReceiver();

//	mGameViewsFactory.insert(qv::views::GameViewFactoryRegistry::value_type(qv::views::GVT_HUMAN_VIEW.Hash,
//												new qv::views::GameViewFactory<qv::views::HumanView>()));

	// maybe each one raise next state
	// initialize game logic - here game logic will get parâmeters configure internal things like: physics, sound, actor managment
	// loading resources - maybe preloading something musics and textures
	// menu - show menu to user choose options
	// waiting for players - check Players attached to game logic, if enogh, if not attach local player as humam view
	// running - start run

	return true;
}
//-----------------------------------------------------------------------------
void Game::finalize()
{
	if (mGameLogic)
		delete mGameLogic;

	mGameViews.clear();

	if (mCommandManager)
		delete mCommandManager;

	//finalize render driver
//	finalizeImpl();
}
//-----------------------------------------------------------------------------
void Game::addGameView(qv::views::AbstractGameView* gameView)
{
	if(gameView)
		mGameViews.push_back(gameView);

	if (mGameViews.size() > 1)
		std::sort(mGameViews.begin(), mGameViews.end(), SortGameViewsLess());
}
//-----------------------------------------------------------------------------
void Game::removeGameView(qv::views::AbstractGameView* gameView)
{
	for ( qv::views::GameViewsArray::iterator itr = mGameViews.begin(); itr != mGameViews.end(); itr++)
	{
		if ((*itr)->getId().Hash == gameView->getId().Hash)
		{
			mGameViews.erase(itr);
			delete gameView; //may be this view should raise some events

			break;
		}
	}
}
//-----------------------------------------------------------------------------
qv::views::AbstractGameView* Game::findGameView(const qv::views::GVI_GAME_VIEW_ID& gameViewId)
{
	qv::views::AbstractGameView* gameView(0);
	for ( qv::views::GameViewsArray::iterator itr = mGameViews.begin(); itr != mGameViews.end(); itr++)
	{
		if ((*itr)->getId().Hash == gameView->getId().Hash)
			gameView = (*itr);
	}

	return gameView;
}
//-----------------------------------------------------------------------------
void Game::addGameViewFactory(const qv::views::GVT_GAME_VIEW_TYPE& gameViewType, qv::views::AbstractGameViewFactory* gameViewFactory)
{
	qv::views::GameViewsFactoryMap::iterator itr = mGameViewsFactory.find(gameViewType.Hash);

	if (itr == mGameViewsFactory.end())
		mGameViewsFactory.insert(qv::views::GameViewsFactoryMap::value_type(gameViewType.Hash, gameViewFactory));
}
//-----------------------------------------------------------------------------
void Game::removeGameViewFactory(qv::views::GameViewFactory* gameViewFactory)
{
	for ( qv::views::GameViewsFactoryMap::iterator itr = mGameViewsFactory.find(gameViewFactory);
	{
		if ((*itr)->getId().Hash == gameView->getId().Hash)
		{
			mGameViews.erase(itr);
			delete gameView; //may be this view should raise some events

			break;
		}
	}
}
//-----------------------------------------------------------------------------
//void Game::load( const qv::c8* gamePath, const qv::c8* gameFile)
//{
//	//mCommandManager->executeCommand(new LoadGameCommandArgs());
//
///*	qv::CommandArgs* args = mCommandManager->createCommandArgs<qv::LoadGameCommandArgs>(qv::gaming::CT_GAME_LOAD);*/
//
///*	static_cast<qv::LoadGameCommandArgs*>(args)->setGameFile(gameFile);
//	static_cast<qv::LoadGameCommandArgs*>(args)->setGamePath(gamePath);
//
//	mCommandManager->executeCommand(args);
//*/
//}
//-----------------------------------------------------------------------------
void Game::addCommand( qv::AbstractCommand* command)
{
//	mCommandManager->addc;
}
//-----------------------------------------------------------------------------
void Game::loadConfiguration()
{
	//load strings
	//load language
	//load key-action mappings
	//configure game application

	mGameParams.Bits = 32;
	mGameParams.Fullscreen = false;
	mGameParams.LocalPlayers = 1;
	mGameParams.HostGame = true;
	mGameParams.Title = "Default Game Window";
	mGameParams.WindowWidth = 1024;
	mGameParams.WindowHeight = 768;

}
//-----------------------------------------------------------------------------
void Game::loadAddin(const qv::c8* addinName)
{
	mAddinManager->load(addinName);
}
//-----------------------------------------------------------------------------
void Game::parseCommandLine( int argc, const char** argv)
{
	int c;

	while ((c = getopt( argc, argv, "s:a:")) != '\0')
	{
//        switch (c)
//        {
//        case 'i':
//            m_sceneFileName = optarg;
//            break;
//        case 'a':
//            sceneDirectory = optarg;
//            folderArchives.push_back(optarg);
//            break;
//        }
	}
}
//-----------------------------------------------------------------------------
void Game::update( qv::u32 currentTimeMs, qv::u32 elapsedTimeMs)
{
	mCommandManager->executeCommands();

	if (mGameLogic)
		mGameLogic->update(currentTimeMs, elapsedTimeMs);

	//update views after game logic update
	for (u32 i = 0; i < mGameViews.size(); i++)
		mGameViews.at(i)->update( elapsedTimeMs);
}
//-----------------------------------------------------------------------------
void Game::render( qv::u32 currentTimeMs, qv::u32 elapsedTimeMs)
{
	for (u32 i = 0; i < mGameViews.size(); i++)
		mGameViews.at(i)->render(currentTimeMs, elapsedTimeMs);
}
//-----------------------------------------------------------------------------
qv::s32 Game::run(int argc, const char** argv)
{
	// - process commandline params, this shoud override file config value
	// just in SGameParams not in real config file
	parseCommandLine( argc, argv);

	//mCommandManager->executeCommand(new StartupGameCommandArgs(argv[0]))

	btClock clock;
	clock.reset();

	u32 lastTimeMs =  clock.getTimeMilliseconds();
	u32 curentTimeMs = lastTimeMs;

	while (!mQuit)
	{
		curentTimeMs = clock.getTimeMilliseconds();
		u32 elapsedTimeMs = curentTimeMs - lastTimeMs;

		//game application update with current and
		//elapsed time from last application update
		update( curentTimeMs, elapsedTimeMs);

		render( curentTimeMs, elapsedTimeMs);
		//game views rendering update with current and
		//elapsed time from last application tick

		lastTimeMs = curentTimeMs; //update last time
	}

	return 0;
}

}
