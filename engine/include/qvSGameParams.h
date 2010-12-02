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


#ifndef __SGAME_PARAMS_H_
#define __SGAME_PARAMS_H_

#include <string>

#include "qvTypes.h"
#include "qvActorTypes.h"



namespace qv
{
   
	struct SGameParams
    {
		SGameParams()
        :Fullscreen(false),
        Vsync(false),
		HostGame(false),
		InputBuffered(false),
		InputDebug(false),
		Bits(16),
        LocalPlayers(1),
        AIPlayers(0),  //player vs computer games i can use this to test the ai and animation, maybe
        RemotePlayers(0),
		WindowHeight(768),
		WindowWidth(1024),
		RenderFrequency(16),
        Title("Default Game Title")

		{
		}

		SGameParams(const SGameParams& other)
		{
			*this = other;
		}

		SGameParams& operator= (const SGameParams& other)
		{
			Title = other.Title;
			Bits = other.Bits;
			Fullscreen = other.Fullscreen;
			Vsync = other.Vsync;

            HostGame = other.HostGame;
            LocalPlayers = other.LocalPlayers;
            AIPlayers = other.AIPlayers;
            RemotePlayers = other.RemotePlayers;

            //input variables
            ShowCursor = other.ShowCursor;
            InputBuffered = other.InputBuffered;
            InputDebug = other.InputDebug;
			WindowHeight = other.WindowHeight;
			WindowWidth = other.WindowWidth;
			
			RenderFrequency = other.RenderFrequency;
			
			return *this;
		}
	
        bool Fullscreen;
		bool Vsync;
        bool HostGame;
        bool ShowCursor;
        bool InputBuffered;
        bool InputDebug;
		
		qv::u8 Bits;
        qv::u8 LocalPlayers;
        qv::u8 AIPlayers;
        qv::u8 RemotePlayers;

		qv::u32 WindowHeight;
		qv::u32 WindowWidth;
		qv::u32 RenderFrequency;
		
        std::string Title;

		
        //texture size
        //detail level
        //shadow maps
        //realtime shadows
	};
}
#endif

