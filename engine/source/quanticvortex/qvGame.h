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


#ifndef __GAME_H_
#define __GAME_H_

#include "qvPrerequisites.h" 
//#include "core/qvGameLogic.h"
//#include "events/qvEventManager.h"
//#include "input/qvInputManager.h"

#include "IReferenceCounted.h"
//
//using namespace qv::core;
//using namespace qv::input;
//using namespace qv::events;

namespace qv
{
	class EngineManager;

	//namespace core
	//{
	//	//class IGameLogic;
	//	class IGameView;
	//}
}

namespace qv
{    
	class _QUANTICVORTEX_API Game : public irr::IReferenceCounted
    {

	private:
		bool initialize();

    protected:
        stringc mGameTitle;
        stringc mGameAppDirectory;
        stringc mUserHomeDirectory;

		EngineManager* mEngineManager;

		//void addInitialGameView(IGameView* gameView);
        //virtual void registerGameEvents();
	    

    public:

	    Game();
        virtual ~Game();

 	    s32 main(s32 argc, c8 *argv[]);

		virtual bool loadGame() = 0;
    };
}

#endif

