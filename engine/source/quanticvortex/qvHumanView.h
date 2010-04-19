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

#include "qvIHumanView.h"


namespace qv
{
	class IEngineManager;

    namespace views
    {
		class IElementViewFactory;

		class HumanView: public IHumanView
        {
        public:
            HumanView(IEngineManager* engine, u32 viewHashType = GVT_GAME_VIEW_HUMAN.Hash);

            virtual ~HumanView();

			virtual void attach(u32 viewHashId, u32 actorHashId = 0)
			{
				mViewHashId = viewHashId;
                mActorHashId = actorHashId;
			}

            virtual u32 getHashId() const { return mViewHashId; }

            virtual u32 getHashType() const { return mViewHashType; }

//			virtual void lostDevice();

	        virtual void update(u32 elapsedTimeMs);

	        virtual void render( u32 currentTimeMs, u32 elapsedTimeMs); //time in miliseconds

	        //// Virtual methods to control the layering of interface elements
            virtual IElementViewSharedPtr addElementView(const c8* name, u32 elementViewHashType);

   //         virtual void pushElement(IElementView* element);

			//virtual void popElement(IElementView* element);

            virtual void registerElementViewFactory(IElementViewFactory* factoryToAdd);

			//void attachProcess(Process* process){mProcessManager->attach(process);}

            //command that will registred on event manager to response to spacefic events
//            virtual const CommandList& commandEventResponseList() const { return mEventCommands; }

            //coomand that will registred on input manager to response to user input
//            virtual const CommandList& commandInputResponseList() const { return mInputCommands; }

        protected:
            IEngineManager*     mEngine;
            u32 mViewHashType;
            u32	mViewHashId;
            u32 mActorHashId;
			ElementViewArray mElementViews;
//            array<IElementViewFactory*> mElementViewFactories;
//            CommandList mInputCommands;
//            CommandList mEventCommands;
			//I need to put aITimer here, to allow private timer to player view

            //IGUIFont* mFont;

            //IGUIEnvironment* mGuiEnvironment;


            real mCurrentTime;    // current time
            real mLastUpdateTime; // last tick time update
			u32 mAccumulatorTime;

			cAudio::IAudioManager* mAudioManager;

	        //// Interface sensitive objects
	        //shared_ptr<IMouseHandler> mMouseHandler;
	        //shared_ptr<IKeyboardHandler> mKeyboardHandler;
			//InputController* mInputController;
	        //ProcessManager *mProcessManager;				    // just for gui elements.

        };
    }
}
#endif

