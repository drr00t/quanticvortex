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

#ifndef __SCENE_ELEMENT_VIEW_H_
#define __SCENE_ELEMENT_VIEW_H_

#include "qvAbstractElementView.h"
#include "qvActor.h"


namespace qv
{
class CommandManager;
class Game;
}

namespace qv
{
namespace views
{


class _QUANTICVORTEX_API_ SceneElementView: public qv::views::AbstractElementView
	/// class responsable by element views craetion and managment. Scene file load,
	/// text, graphic scene elements
{
public:
	SceneElementView(const qv::views::EVI_ELEMENT_VIEW_ID& elementViewId, qv::Game* game);
	virtual ~SceneElementView();

	void addElementView(qv::views::AbstractElementView* elementView);

//    virtual irr::scene::ICameraSceneNode* getCamera() = 0;
//    virtual void setCamera(irr::scene::ICameraSceneNode* camera) = 0;
//
//    virtual irr::scene::ISceneManager* getSceneManager() = 0;

//	virtual void render( qv::u32 currentTimeMs, qv::u32 elapsedTimeMs);
	/// render all scene elements.

//	virtual void update( qv::u32 elapsedTimeMs);
	/// update all time dependent scene element

	virtual void loadScene(const qv::c8* sceneFile)=0;

//    virtual void addSceneNode(const gaming::SActorArgs& args, u32 actorHashId = 0) = 0;
//    virtual irr::scene::ISceneNode* findSceneNode( u32 actorHashId) = 0;

	//virtual void OnCreateNode(ISceneNode* node)=0;
	//virtual void OnReadUserData(ISceneNode* forSceneNode, io::IAttributes* userData)=0;
	//virtual io::IAttributes* createUserData(ISceneNode* forSceneNode)=0;
private:

	qv::CommandManager* mCommandManager;
	qv::views::ElementViewsList mElementViews;

};



}

}

#endif
