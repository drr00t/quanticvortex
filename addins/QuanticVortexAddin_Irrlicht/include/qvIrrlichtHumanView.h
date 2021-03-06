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

#ifndef _IRRLICHT_HUMAN_VIEW_H_
#define _IRRLICHT_HUMAN_VIEW_H_

#include "qvAddinIrrlichtConfig.h"
#include "qvHumanView.h"


namespace irr
{
class IrrlichtDevice;
}

namespace qv
{
struct SGameParams;

namespace views
{
	class SceneElementView;
}
}

namespace qv
{
namespace addins
{

static const qv::views::GVI_GAME_VIEW_ID GVI_IRRLICHT_HUMAN_VIEW("GVI_IRRLICHT_HUMAN_VIEW");

class _QUANTICVORTEX_ADDIN_IRRLICHT_API_ IrrlichtHumanView: public qv::views::HumanView
	/// human view irrlicht implementation.
{
public:
	IrrlichtHumanView(qv::Game* game);
	virtual ~IrrlichtHumanView();

//	virtual void update(u32 elapsedTimeMs);
	/// update all view elements, process and all other thing
	/// sibling to render system, animated gui and mesh

	virtual void render( u32 currentTimeMs, u32 elapsedTimeMs);
	/// render all element view data (scene, gui, shaders)

private:
	irr::IrrlichtDevice* mDevice;
	qv::SGameParams mGameParams;
	qv::views::SceneElementView* mScene;

};
}
}

#endif
