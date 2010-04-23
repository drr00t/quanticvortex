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


#include "qvGame.h"

#include "qvEngineManager.h"

#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/OptionProcessor.h"






namespace qv
{
    
Game::Game()
:mOptions(0)
{
    Poco::Util::OptionSet set;
	set.addOption(
		Poco::Util::Option("bits", "bpp")
		.description("bits per pixel of the color buffer. default: 16")
		.required(false)
		.repeatable(false)
        .argument("value"));
			
	set.addOption(
		Poco::Util::Option("windowsize", "ws")
		.description("window size. default: 1024x768")
		.required(false)
		.repeatable(false)
        .argument("value"));
	
    set.addOption(
		Poco::Util::Option("vsync", "sync")
		.description("vertical sync. default: false")
		.required(false)
		.repeatable(false)
        .argument("value"));
        
	set.addOption(
		Poco::Util::Option("scene", "s")
		.description("can load a scene file directly.")
		.required(false)
		.repeatable(false)
        .argument("value"));
        
	mOptions = new Poco::Util::OptionProcessor(set);
}

Game::~Game(){
    
}

s32 Game::run(s32 argc, c8* argv[])
{
//        mOptionsProcessor->
}


}
