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


#ifndef __IRR_SCENE_LOADER_H_
#define __IRR_SCENE_LOADER_H_

#include "qvAddinIrrlichtConfig.h"

//#include "ISceneUserDataSerializer.h"
//#include "IAttributes.h"
//#include "ISceneNode.h"


namespace qv
{

namespace addins
{

//-----------------------------------------------------------------------------
//                       U s e r D a t a S e r i a l i z e r
//-----------------------------------------------------------------------------
class IrrSceceLoader : public irr::scene::ISceneUserDataSerializer
{
public:
	void OnCreateNode(irr::scene::ISceneNode* node);
	void OnReadUserData(irr::scene::ISceneNode* forSceneNode, irr::io::IAttributes* userData);

	irr::io::IAttributes* createUserData(irr::scene::ISceneNode* forSceneNode);
//    void _setPhysicsAttributes(irr::io::IAttributes* userData, struct PhysicsAttributes& attr);

};

}
}
#endif
