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

#ifndef _QV_ADDIN_IRRLICHT_H_
#define _QV_ADDIN_IRRLICHT_H_

#include "qvAddinIrrlichtConfig.h"
#include "qvAddin.h"


namespace qv
{
namespace addins
{
	
class IrrlichtAddin: public qv::Addin
	/// Irrlicht interafce with Quantic Vortex Core, this plugin will add
	/// renderable objects and input receiver implementation.
{
public:
	IrrlichtAddin(qv::Game* game);
	virtual ~IrrlichtAddin();
	
	virtual void load();
	
	virtual void unload();	

private:
	qv::Game* mGame;

};
}
}


// Addin inteface instantiation
//

qv::Addin* mIrrlichtAddin;

extern "C"
{
	_QUANTICVORTEX_ADDIN_IRRLICHT_API_ void dllLoadAddin( qv::Game* game)
	{
		mIrrlichtAddin = new qv::addins::IrrlichtAddin(game);
		
		mIrrlichtAddin->load();

//		game.installAddin(addin);

	}


	_QUANTICVORTEX_ADDIN_IRRLICHT_API_ void dllUnloadAddin ()
	// Addin cleanup function
	{
		mIrrlichtAddin->unload();
		delete mIrrlichtAddin;
	}
}

#endif
