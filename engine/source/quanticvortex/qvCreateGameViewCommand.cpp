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

#include "qvCreateGameViewCommand.h"
#include "qvGameLogic.h"
#include "qvCreateGameViewEventArgs.h"
#include "qvHumanView.h"


namespace qv
{
namespace gaming
{

//-----------------------------------------------------------------------------------------
CreateGameViewCommand::CreateGameViewCommand(qv::gaming::GameLogic* gameLogic)
:mGameLogic(gameLogic), mEventHashType(qv::events::ET_CREATE_GAME_VIEW.Hash),
mCommandHashId(qv::gaming::CI_CREATE_GAME_VIEW.Hash)
{
}
//-----------------------------------------------------------------------------------------
CreateGameViewCommand::~CreateGameViewCommand()
{
    // TODO: may be i should use reference counted to GameLogic and decrease 
    // to each command that was deleted
    mGameLogic = NULL;
}
//-----------------------------------------------------------------------------------------
void CreateGameViewCommand::executeCommand(qv::events::EventArgs* args)
{
    qv::events::CreateGameViewEventArgs* gargs = 
            static_cast<qv::events::CreateGameViewEventArgs*>(args);
    
    qv::views::AbstractGameView* abstractView = 
                mGameLogic->addView(gargs->getGameViewName(), gargs->getGameViewType(),0 );
                
    qv::views::HumanView* humanView = static_cast<qv::views::HumanView*>(abstractView);
        
}

}

}
