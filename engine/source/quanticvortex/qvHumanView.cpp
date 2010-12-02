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


#include "qvHumanView.h"

#include "qvSceneElementView.h"
#include "qvGame.h"
#include "qvCommandManager.h"




namespace qv
{
namespace views
{
//-----------------------------------------------------------------------------------------
HumanView::HumanView(const qv::views::GVI_GAME_VIEW_ID& gameViewId, qv::Game* game)
        : qv::views::AbstractGameView( gameViewId, 1, qv::views::GVT_HUMAN_VIEW),
        mCurrentEngineTime(0.0f), mLastUpdateTime(0.0f), mAccumulatorTime(0), 
        mCommandManager(game->getCommandManager()) mGameParams(game->getGameParameters())
{

//    addSceneElementView("scene_view", qv::views::EVT_ELEMENT_VIEW_SCENE);
     
//     addGuiElementView("gui_view", qv::views::EVT_ELEMENT_VIEW_SCENE);
    
    //mFont = mEngineManager->getGuiManager()->getBuiltInFont();
    //IGUISkin* skin = mEngineManager->getGuiManager()->getSkin();
    //   skin->setFont(mFont);

    //InitAudio();

    //      mProcessManager = new ProcessManager();
    //mProcessManager->grab();

    //m_pFont = NULL;         // Font for drawing text
    //m_pTextSprite = NULL;   // Sprite for batching draw text calls

    ///human view will liten:
    /// - LoadContentEventArgs: load game content (types: scene, gui, player, npc, etc) fired by gamelogic,
    /// each content could say to human what input will should listen
    ///
    /// - ChangeGameStateEventArgs: listen change of game state, to reconfigure input translator of each
    /// translator for game state

}
//-----------------------------------------------------------------------------------------
HumanView::~HumanView()
{
    //mProcessManager->drop();

    mElementViews.clear();
}
//-----------------------------------------------------------------------------------------
void HumanView::render( u32 currentTimeMs, u32 elapsedTimeMs)
{
    //////// Lock FPS at around 60
    //////if((timeThisFrame - timePreviousFrame) <= 16)
    //////{
    //////  Timer->tick();
    //////  timeThisFrame = Timer->getTime();
    //////}
    //////timePreviousFrame = timeThisFrame;

    //get new system time, but FIXME: should be game time from GameLogic maybe
    mCurrentEngineTime = currentTimeMs;

    if (currentTimeMs == mLastUpdateTime)
        return;

    mAccumulatorTime += elapsedTimeMs;

    if (mAccumulatorTime > mGameParams.RenderFrequency)
    {
        qv::views::ElementViewsList::iterator itr;
        for (itr = mElementViews.begin(); itr != mElementViews.end(); ++itr)
            if ((*itr)->visible())
                (*itr)->render( mCurrentEngineTime, elapsedTimeMs);

        //register last render call time
        mLastUpdateTime = mCurrentEngineTime;
        mAccumulatorTime = 0;
    }
}
//-----------------------------------------------------------------------------------------
void HumanView::update( u32 elapsedTimeMs)
{

    //mProcessManager->update(elapsedTimeMs);

    //m_Console.Update(deltaMilliseconds);
    qv::views::ElementViewsList::iterator itr;
    for (itr = mElementViews.begin(); itr != mElementViews.end(); ++itr)
        (*itr)->update( elapsedTimeMs);

    //will did not need recreate this object every time
//            if(!mGameTickEventArgs)
//                mGameTickEventArgs = mEventManager->createEventArgs<qv::events::GameTickEventArgs>(qv::events::EET_GAME_LOGIC_TICK_UPDATE);
//            mEventManager->
}
//-----------------------------------------------------------------------------------------
//qv::views::AbstractElementView* HumanView::addElementView(const qv::views::EVI_ELEMENT_VIEW_ID& elementViewId, const qv::views::EVT_ELEMENT_VIEW_TYPE& elementViewType)
//{
//    qv::views::AbstractElementView* elementView(0); // = 
//        //mElementViewFactory.keep(new qv::views::SceneElementView(elementViewName, mCommandManager));
//
//    mElementViews.push_back(elementView);
//
//    if (mElementViews.size() > 1)
//        mElementViews.sort(SortElementViewsLess());
//
//    return static_cast<qv::views::SceneElementView*>(elementView);
//
//}
//-----------------------------------------------------------------------------------------
//qv::views::GuiElementView* HumanView::addSceneElementView(const qv::c8* elementViewName, const qv::views::EVT_ELEMENT_VIEW_TYPE& elementViewType)
//{
//    qv::views::AbstractElementView* elementView = 
//        mElementViewFactory.keep(new qv::views::SceneElementView(elementViewName, mCommandManager, mDevice3d->getSceneManager() ));
//
//    mElementViews.push_back(elementView);
//
//    if (mElementViews.size() > 1)
//        mElementViews.sort(SortElementViewsLess());
//
//    return static_cast<qv::views::SceneElementView*>(elementView);
//
//}
//-----------------------------------------------------------------------------------------
}
}
