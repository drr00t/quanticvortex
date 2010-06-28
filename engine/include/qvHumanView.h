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


#ifndef __HUMAN_VIEW_H_
#define __HUMAN_VIEW_H_

#include "qvRAIIFactoryImp.h"

#include "qvAbstractGameView.h"
#include "qvAbstractElementView.h"



namespace irr
{
class IrrlichtDevice;
}

namespace qv
{

class CommandManager;

namespace input
{
class InputReceiver;
}

namespace views
{
    class SceneElementView;
}
}

namespace qv
{
namespace views
{

class _QUANTICVORTEX_API_ HumanView : public qv::views::AbstractGameView
            /// This class allow a local player to be atached
            /// on game, it is responsable by receive inputs
            /// from player (controller, keyboard, mouse, etc...)
            /// rendering data on screen
{
public:
    HumanView(const qv::c8* gameViewName, qv::CommandManager* commandManager, irr::IrrlichtDevice* device3d);
    ///create the HumanView

    virtual ~HumanView();
    ///create the HumanView

    void attach( u32 actorHashId);
    /// attach given view to a actor infromed by user,
    /// if zero means no actor

    virtual void update(u32 elapsedTimeMs);
    /// update all view elements, process and all other thing
    /// sibling to render system, animated gui and mesh

    virtual void render( u32 currentTimeMs, u32 elapsedTimeMs);
    /// render all element view data (scene, gui, shaders)

    //// Virtual methods to control the layering of interface elements
    qv::views::SceneElementView* addSceneElementView(const qv::c8* elementViewName, const qv::views::EVT_ELEMENT_VIEW_TYPE& elementViewType);

//    void registerElementViewFactory(IElementViewFactory* factoryToAdd);

//    void attachProcess(Process* process){mProcessManager->attach(process);}

private:

    u32 mActorHashId;
    u32 mCurrentEngineTime;    // current view time
    u32 mLastUpdateTime; // last tick time update
    u32 mAccumulatorTime;

    irr::IrrlichtDevice* mDevice3d;

    qv::input::InputReceiver* mInputReceiver;
    qv::CommandManager* mCommandManager;
    
    qv::views::ElementViewsList mElementViews;
    
    RaiiFactoryImp<qv::views::AbstractElementView> mElementViewFactory;


    //ProcessManager *mProcessManager;				    // just for gui elements.
//        cAudio::IAudioManager* mAudioManager;

    //IGUIFont* mFont;

    //IGUIEnvironment* mGuiEnvironment;
};

//
// inlines
//
inline void HumanView::attach( u32 actorHashId = 0)
{
    mActorHashId = actorHashId;
}


} // namespace views


} // namespace qv
#endif
