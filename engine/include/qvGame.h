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


#ifndef __GAME_H_
#define __GAME_H_

#include <algorithm>

#include "qvCompileConfig.h"
#include "qvGameViewFactory.h"
#include "qvCommandTypes.h"
#include "qvSGameParams.h"


namespace qv
{
class CommandManager;
class AbstractCommand;
class AddinManager;

namespace gaming
{
class GameLogic;
}
namespace input
{
class InputReceiver;
}
namespace views
{
class AbstractGameView;
}
}



namespace qv
{


struct SortGameViewsLess
		/// function object for sort abstract game views
{
	bool operator()(qv::views::AbstractGameView* a, qv::views::AbstractGameView* b) const
	{
		return (a->getOrder() < b->getOrder());
	}
};

class _QUANTICVORTEX_API_ Game //: private GameImpl
	/// engine core object, this work on lowest level and provide a
	/// generic loop for global service like: EventManager, GameLogic
{

public:

	Game();
	virtual ~Game();

	void addGameView( qv::views::AbstractGameView* gameView);
	/// register new game view

	void removeGameView(qv::views::AbstractGameView* gameView);
	/// remvoe a game view from game views collection and delete from memory

	qv::views::AbstractGameView* findGameView(const qv::views::GVT_GAME_VIEW_TYPE& gameViewType);
	/// find a game view on registerd in game views collection.

	void addGameViewFactory( const qv::views::GVT_GAME_VIEW_TYPE& gameViewType, qv::views::AbstractGameViewFactory* gameViewFactory);
	/// register new game view factory

	void removeGameViewFactory(qv::views::AbstractGameViewFactory* gameViewFactory);
	/// remove a game view factory from game views factories collection.

	void addCommand(qv::AbstractCommand* command);
	/// add command to listen command args

	void removeCommand(const qv::CT_COMMAND_TYPE& commandType);
	/// register command type to used in game

	void findCommand(const qv::CT_COMMAND_TYPE& commandType);
	/// register command type to used in game

	void parseCommandLine( int argc, const char** argv);
	/// override config file options with commandline options
	/// options passed by command line, will not be persisted
	/// to config file

	void loadConfiguration();
	/// load configuration from file, include saved game

	void loadAddin(const qv::c8* addinName);

	s32 run(int argc, const char** argv);
	/// called by user to start main loop of the game.

	qv::gaming::GameLogic* getGameLogic();
	/// all game data, views, physics, actor storage here.

	qv::CommandManager* getCommandManager();
	/// all global events are processed here

	qv::SGameParams& getGameParameters();
	/// game global configuration options, menu interface can
	/// change this values

//		const qv::views::GameViewsArray& getGameViews() const;
	/// game views collections, all views must be registred on game
	/// logic to be used on game, ex: HumanView, NetworkView.

	void setQuit(bool quit);
	/// quit from engine main loop if true

private:
	Game (const Game&);
	Game& operator = (const Game&);

	bool initialize();
	/// real method taht will start the engine, this it will
	/// called inside constructor

	void finalize();
	/// this method is analog to the initialize, and will be called
	/// in destructor to make a shutdown and cleanup before quit

	void update( u32 currentTimeMs, u32 elapsedTimeMs);
	/// will called every global engine tick and pass current
	/// system time to GameLogic, EventManager

	void render( u32 currentTimeMs, u32 elapsedTimeMs);
	/// render content of views registred in GameLogic


	bool mQuit; /// quit of engine loop if is true
	qv::SGameParams mGameParams; /// engine, render paramaters
	qv::gaming::GameLogic* mGameLogic; /// game core object updated on engine loop
	qv::CommandManager* mCommandManager; /// global event manager
	qv::CT_COMMAND_TYPE mStartupComandargsType;
	qv::views::GameViewsArray  mGameViews;
	qv::views::GameViewsFactoryMap mGameViewsFactory;
	qv::input::InputReceiver* mInputReceiver;
	qv::AddinManager* mAddinManager;
};


//inlines
inline qv::gaming::GameLogic* Game::getGameLogic()
{
	return mGameLogic;
}

inline qv::CommandManager* Game::getCommandManager()
{
	return mCommandManager;
}

inline qv::SGameParams& qv::Game::getGameParameters()
{
	return mGameParams;
}

//inline const qv::views::GameViewsArray& qv::Game::getGameViews() const
//{
//	return mGameViews;
//}

inline void qv::Game::setQuit(bool quit)
{
	mQuit = quit;
}

//inline void qv::Game::startupGameState(const qv::GS_GAME_STATE& gameState)
//{
//    mStartupComandargsType = commandType;
//}

//inline void qv::Game::addGameState(const qv::GS_GAME_STATE& gameState)
//{
//    mGameStates.push_back();
//}
}

#endif
