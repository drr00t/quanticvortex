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


#include "qvGame.h"
//#include "core/qvIGameView.h"
//#include "events/qvEngineEvents.h"
#include "qvEngineManager.h"

using namespace qv; //::events;

namespace qv
{
	namespace core
	{
		class IGameLogic;
		class IGameView;
	}
}

namespace qv
{
	//------------------------------------------------------------------------------------------------
    Game::Game(): mEngineManager(0)
    {
		
    }
    //------------------------------------------------------------------------------------------------
    Game::~Game()
    {
		mEngineManager->drop();
    }
    //------------------------------------------------------------------------------------------------
	bool Game::initialize()
	{
		mEngineManager = new EngineManager();
		mEngineManager->grab();

		return true;
	}
    //------------------------------------------------------------------------------------------------
    s32 Game::main(s32 argc, c8 *argv[])
    {
        if (mEngineManager->initialize())
        {
            mDevice3d->getTimer()->getTime();

	        s32 lastFPS = -1;
            
			// In order to do framerate independent movement, we have to know
            // how long it was since the last frame
			u32 lastTimeMs = mEngineManager->getDevice()->getTimer()->getTime();

	        while(mDevice3d->run())
            {
                // Work out a frame delta time.
                const u32 curentTimeMs = mEngineManager->getDevice()->getTimer()->getTime();
                u32 elapsedTimeMs = (curentTimeMs - lastTimeMs); // Time in miliseconds
                
				lastTimeMs = curentTimeMs;

				if(elapsedTimeMs > 16)
					elapsedTimeMs = 16;

	            //if (mDevice3d->isWindowActive())
	            //{
					//game application update
					mEngineManager->update( curentTimeMs, elapsedTimeMs);

                    //game application render
                    mEngineManager->render( curentTimeMs, elapsedTimeMs);
					
					//lastTimeMs = curentTimeMs;

					//s32 fps = mVideoDriver->getFPS();

		   //         if (lastFPS != fps)
		   //         {
     //                   stringw str = mGameTitle + L" - QuanticVortex Engine [";
			  //          str += mVideoDriver->getName();
			  //          str += "] FPS:";
			  //          str += fps;
			  //          str += " Triangles:";
					//	str += mVideoDriver->getPrimitiveCountDrawn();

     //                   mDevice3d->setWindowCaption(str.c_str());
			  //          lastFPS = fps;
		   //         }

					//if(elapsedTimeMs > 16)
					//{
					//	mDevice3d->sleep((elapsedTimeMs - 16));
					//}
					//else if(elapsedTimeMs > 16)
					//{
					//	mDevice3d->sleep((16 - elapsedTimeMs));
					//}

                //}
                //else
                //{
                    //mDevice3d->yield();
                //}
            }
        }

        return 0;
    }
	//------------------------------------------------------------------------------------------------
}
