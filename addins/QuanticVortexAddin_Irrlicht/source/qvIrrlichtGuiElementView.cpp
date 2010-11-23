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

#include "qvIrrlichtGuiElementView.h"

#include "qvGame.h"
#include "qvSGameParams.h"

#include "irrlicht.h"


namespace qv
{

namespace addins
{
	
//-----------------------------------------------------------------------------------------	
IrrlichtGuiElementView::IrrlichtGuiElementView(qv::Game* game)
:mGameParams(game->getGameParameters())
{

}
//-----------------------------------------------------------------------------------------
IrrlichtGuiElementView::~IrrlichtGuiElementView()
{
	
}
//-----------------------------------------------------------------------------------------
void IrrlichtGuiElementView::render( u32 currentTimeMs, u32 elapsedTimeMs)
{
    //////// Lock FPS at around 60
    //////if((timeThisFrame - timePreviousFrame) <= 16)
    //////{
    //////  Timer->tick();
    //////  timeThisFrame = Timer->getTime();
    //////}
    //////timePreviousFrame = timeThisFrame;
	
    //get new system time, but FIXME: should be game time from GameLogic maybe
//    mCurrentEngineTime = currentTimeMs;
//
//    if (currentTimeMs == mLastUpdateTime)
//        return;
//
//    mAccumulatorTime += elapsedTimeMs;
//
//    if (mAccumulatorTime > 16) //qv::GF_GAME_RENDER_FRAMERATE)
//    {
//        qv::views::ElementViewsList::iterator itr;
//        for (itr = mElementViews.begin(); itr != mElementViews.end(); ++itr)
//            if ((*itr)->visible())
//                (*itr)->render( mCurrentEngineTime, elapsedTimeMs);

		mDevice->getSceneManager()->drawAll();
		mDevice->getGUIEnvironment()->drawAll();

        //register last render call time
//        mLastUpdateTime = mCurrentEngineTime;
//        mAccumulatorTime = 0;

//    }
}
//-----------------------------------------------------------------------------------------
void IrrlichtGuiElementView::update( u32 elapsedTimeMs)
{

    //mProcessManager->update(elapsedTimeMs);

    //m_Console.Update(deltaMilliseconds);
//    qv::views::ElementViewsList::iterator itr;
//    for (itr = mElementViews.begin(); itr != mElementViews.end(); ++itr)
//        (*itr)->update( elapsedTimeMs);

    //will did not need recreate this object every time
//            if(!mGameTickEventArgs)
//                mGameTickEventArgs = mEventManager->createEventArgs<qv::events::GameTickEventArgs>(qv::events::EET_GAME_LOGIC_TICK_UPDATE);
//            mEventManager->
}
//-----------------------------------------------------------------------------------------

}
}
