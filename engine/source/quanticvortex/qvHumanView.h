/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009 QuanticMinds Software Ltda.
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

#include "qvIHumanView.h"
//#include "runtime/qvProcessManager.h"


namespace qv
{
	class IEngineManager;

    namespace views
    {
		class IElementViewFactory;

		class HumanView: public IHumanView
        {

        protected:
            IEngineManager*     mEngine;
            GVT_GAME_VIEW_TYPE  mType;
            GVI_GAME_VIEW_ID	mViewID;
			gaming::AI_ACTOR_ID         mActorID;
			list<IElementView*> mElementViews;

            array<IElementViewFactory*> mElementViewFactories;

            //IGUIFont* mFont;

            //IGUIEnvironment* mGuiEnvironment;


            f32 mCurrentTime;    // current time
            f32 mLastUpdateTime; // last tick time update
			f32 mAccumulatorTime;

	        //// Interface sensitive objects
	        //shared_ptr<IMouseHandler> mMouseHandler;
	        //shared_ptr<IKeyboardHandler> mKeyboardHandler;
			//InputController* mInputController;
	        //ProcessManager *mProcessManager;				    // just for gui elements.


        public:
            HumanView( const c8* viewID, IEngineManager* engine, const GVT_GAME_VIEW_TYPE& viewType = GVT_GAME_VIEW_HUMAN);
            virtual ~HumanView();

            virtual const GVT_GAME_VIEW_TYPE& getType()
			{
				return mType;
			}

            virtual const GVI_GAME_VIEW_ID& getID() const
			{
				return mViewID;
			}
		
            virtual void attach(const GVI_GAME_VIEW_ID& viewID, const gaming::AI_ACTOR_ID& actorID=gaming::AI_ACTOR_EMPTY)
			{
				mViewID = viewID;
				mActorID = actorID;
			}
			
			virtual void lostDevice();

	        virtual void update(u32 elapsedTimeMs);

	        virtual void render( u32 currentTimeMs, u32 elapsedTimeMs); //time in miliseconds

	        //// Virtual methods to control the layering of interface elements
            virtual IElementView* addElementView(const c8* name, const EVT_ELEMENT_VIEW_TYPE& type);

            virtual void pushElement(IElementView* element);

			virtual void popElement(IElementView* element);

            virtual void registerElementViewFactory(IElementViewFactory* factoryToAdd);

			//void attachProcess(Process* process){mProcessManager->attach(process);}
        };
    }
}
#endif

