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


#ifndef __GAME_VIEW_CREATE_COMMAND_H_
#define __GAME_VIEW_CREATE_COMMAND_H_

#include "qvAbstractCommand.h"
#include "qvGameViewCreateCommandArgs.h"

namespace qv
{
    class Game;
}
  
namespace qv
{
namespace views
{

class GameViewCreateCommand: public qv::AbstractCommand
    /// basic interface to execute a command inside the engine
{
public:
    CreateGameViewCommand(qv::Game* game);
    
    virtual ~CreateGameViewCommand();

    virtual void executeCommand(qv::CommandArgs* args)
		/// body of command
	{
		qv::views::GameViewCreateCommandArgs* gameViewArgs = 
			static_cast<qv::views::GameViewCreateCommandArgs*>(args);
			
		mGame->addGameView()
		
	}

private:
    qv::Game* mGame;
};

}

}

#endif

