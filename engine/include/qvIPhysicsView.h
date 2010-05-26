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


#ifndef __PHYSICS_VIEW_H_
#define __PHYSICS_VIEW_H_

//#include "qvEngineManager.h"
#include "qvIGameView.h"
#include "qvIElementView.h"
//#include "input/qvInputController.h"
//#include "runtime/qvProcessManager.h"

using namespace irr::gui;

using namespace qv::gaming;
//using namespace qv::input;
//using namespace qv::runtime;

//namespace qv{
//	class EngineManager;
//}

namespace qv
{
	class EventManager;
	
    namespace views
    {
//        class HumanView: public IGameView
//        {
//
//        protected:
//            GameViewID mViewID;
//			E_GAME_VIEW_TYPE mType;
//			ElementViewList mElementViews;
//            
//            ActorID* mActorID;
//
//            IGUIFont* mFont;
//
//            //IGUIEnvironment* mGuiEnvironment;
//
//
//            f32 mCurrentTime;    // current time
//            f32 mLastUpdateTime; // last tick time update
//			f32 mAccumulatorTime;
//            // is it good can control GUI urender speed? what i can do with this? may be deal with consoles and TV
//            //bool m_runFullSpeed;	// set to true if you want to run full speed
//
//	        //// Interface sensitive objects
//	        //shared_ptr<IMouseHandler> mMouseHandler;
//	        //shared_ptr<IKeyboardHandler> mKeyboardHandler;
//			//InputController* mInputController;
//	        //ProcessManager *mProcessManager;				    // just for gui elements.
//
//
//        public:
//			HumanView( const c8* viewID);
//            virtual ~HumanView();
//
//	        virtual E_GAME_VIEW_TYPE getType()
//			{
//				return mType;
//			}
//
//	        virtual const GameViewID& getID() const
//			{
//				return mViewID;
//			}
//
//			virtual void lostDevice();
//	        virtual void attach(const GameViewID& viewID, ActorID* actorID=0);
//	        virtual void update(u32 elapsedTimeMs);
//	        virtual void render( u32 currentTimeMs, u32 elapsedTimeMs); //time in miliseconds
//
//	        //// Virtual methods to control the layering of interface elements
//            virtual void pushElement(IElementView* element);
//			virtual void popElement(IElementView* element);
//
//			//void attachProcess(Process* process){mProcessManager->attach(process);}
//        };
    }
}
#endif

