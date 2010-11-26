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

#include "qvIrrlichtSceneElementView.h"

#include "qvGame.h"


namespace qv
{

namespace addins
{
	
//-----------------------------------------------------------------------------------------	
IrrlichtSceneElementView::IrrlichtSceneElementView(qv::Game* game, irr::IrrlichtDevice* device)
:qv::views::SceneElementView(qv::addins::EVI_IRRLICHT_SCENE_VIEW, game), mDevice(device),
mGameParams(game->getGameParameters())
{
	
}
//-----------------------------------------------------------------------------------------
IrrlichtSceneElementView::~IrrlichtSceneElementView()
{
	
}
//-----------------------------------------------------------------------------------------
void IrrlichtSceneElementView::loadScene(const qv::c8* sceneFile)
{
    mDevice->getFileSystem()->addZipFileArchive( sceneFile, true, false);
    mDevice->getSceneManager()->loadScene("scene.irr", this);
}
//-----------------------------------------------------------------------------------------
void IrrlichtSceneElementView::render( qv::u32 currentTimeMs, qv::u32 elapsedTimeMs)
{
    mDevice->getSceneManager()->drawAll();
}
//-----------------------------------------------------------------------------------------
//void IrrlichtSceneElementView::update( qv::u32 elapsedTimeMs)
//{
//    qv::views::ElementViewsList::iterator itr;
//    for(itr = mElementViews.begin(); itr != mElementViews.end(); ++itr)
//        (*itr)->update(elapsedTimeMs);
//}
//-----------------------------------------------------------------------------------------
void  IrrlichtSceneElementView::OnCreateNode(irr::scene::ISceneNode* node)
{
	
}
//-----------------------------------------------------------------------------------------
void  IrrlichtSceneElementView::OnReadUserData(irr::scene::ISceneNode* forSceneNode, irr::io::IAttributes* userData)
{
	
}
//-----------------------------------------------------------------------------------------
irr::io::IAttributes*  IrrlichtSceneElementView::createUserData(irr::scene::ISceneNode* forSceneNode)
{
	return 0;
}
//-----------------------------------------------------------------------------------------
}
}
