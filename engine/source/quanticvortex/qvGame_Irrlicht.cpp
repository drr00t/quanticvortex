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



#include "qvGame_Irrlicht.h"

#if QUANTICVORTEX_RENDER == QUANTICVORTEX_RENDER_IRRLICHT

#include "irrlicht.h"

#include "qvInputReceiver_Irrlicht.h"


namespace qv
{

//-----------------------------------------------------------------------------
bool GameImpl::initializeImpl(const qv::SGameParams& gameParams)
{

	irr::SIrrlichtCreationParameters parameters;

	parameters.Bits = gameParams.Bits;
	parameters.DriverType = irr::video::EDT_OPENGL;
	parameters.Stencilbuffer = true;
	parameters.WindowSize = irr::core::dimension2du(gameParams.WindowWidth, gameParams.WindowHeight);
	parameters.Fullscreen = gameParams.Fullscreen;
	
	mDevice3d = irr::createDeviceEx(parameters);
	
//	mDevice3d->setEventReceiver(new qv::input::InputReceiverImpl(mInputReceiver));

	return true;
}
//-----------------------------------------------------------------------------
void GameImpl::finalizeImpl()
{
	mDevice3d->drop();
}
//-----------------------------------------------------------------------------
bool GameImpl::beginRenderFrameImpl()
{
	if ( !mDevice3d->run())
		return false;

	mDevice3d->getVideoDriver()->beginScene(true, true); //call some beginRender from engine

	return true;
}
//-----------------------------------------------------------------------------
void GameImpl::endRenderFrameImpl()
{
	mDevice3d->getVideoDriver()->endScene(); //call some endRender from engine
}
//-----------------------------------------------------------------------------


}

#endif
