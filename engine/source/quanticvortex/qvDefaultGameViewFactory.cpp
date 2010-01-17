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


#include "qvDefaultGameViewFactory.h"
#include "qvHumanView.h"

namespace qv
{
    namespace views
    {
        //-----------------------------------------------------------------------------------------
        DefaultGameViewFactory::DefaultGameViewFactory(IEngineManager* engine)
            :mEngine(engine)
        {
            mSupportedGameViewTypes.push_back(GVT_GAME_VIEW_HUMAN.ID);
            mSupportedGameViewTypes.push_back(GVT_GAME_VIEW_AI.ID);
            mSupportedGameViewTypes.push_back(GVT_GAME_VIEW_RECORDER.ID);
            mSupportedGameViewTypes.push_back(GVT_GAME_VIEW_NETWORK.ID);
            mSupportedGameViewTypes.push_back(GVT_GAME_VIEW_PHYSICS.ID);
        }
        //-----------------------------------------------------------------------------------------
        DefaultGameViewFactory::~DefaultGameViewFactory()
        {
        }
		//-----------------------------------------------------------------------------------------------
        IGameView* DefaultGameViewFactory::addGameView(const c8* viewID, const GVT_GAME_VIEW_TYPE& type)
		{
            IGameView* gameView = 0;

            if(type == GVT_GAME_VIEW_HUMAN)
                gameView = new HumanView(viewID, mEngine);

            //else if(type == GameViewHuman)
            //    gameView = new HumanView(name,mEngine);
            
            //else if(type == GameViewAI)
            //    gameView = new HumanView(name,mEngine);
            //
            //else if(type == GameViewRecorder)
            //    gameView = new HumanView(name,mEngine);
            //
            //else if(type == GameViewRemote)
            //    gameView = new HumanView(name,mEngine);
            //
            //else if(type == GameViewPhysics)
            //    gameView = new HumanView(name,mEngine);

			return gameView;
		}
        //-----------------------------------------------------------------------------------------
        u32 DefaultGameViewFactory::getCreatableGameViewTypeCount() const
        {
            return mSupportedGameViewTypes.size();
        }
        //-----------------------------------------------------------------------------------------
        bool DefaultGameViewFactory::getCreateableGameViewType(const GVT_GAME_VIEW_TYPE& type)
        {
	        for (u32 i=0; i<mSupportedGameViewTypes.size(); ++i)
                if (mSupportedGameViewTypes[i] == type.ID)
			        return true;

            return false;

        }
        //-----------------------------------------------------------------------------------------
    }
}