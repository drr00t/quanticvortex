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

#include "qvSceneView.h"

#include "qvIEngineManager.h"


namespace qv
{
    namespace views
    {
        //-----------------------------------------------------------------------------------------
        SceneView::SceneView( const c8* name, IEngineManager* engine, const EVT_ELEMENT_VIEW_TYPE* type)
			:mVisible(true), mDefaultCamera(0), mSceneManager(engine->getDevice()->getSceneManager())//, mOrder(1) //first element view to render
        {

#ifdef _DEBUG
			setDebugName("SceneView");
#endif
			mID = new EVI_ELEMENT_VIEW_ID(name);
        }
        //-----------------------------------------------------------------------------------------
        SceneView::~SceneView()
        {
			mSceneManager = 0;
			map<s32,ISceneNode*>::ParentLastIterator itrActor = mActorSceneNodeMap.getParentLastIterator();

			while(!itrActor.atEnd())
				mActorSceneNodeMap.delink(itrActor->getKey());
        }
        //-----------------------------------------------------------------------------------------
		ISceneNode* SceneView::findSceneNode(const gaming::AI_ACTOR_ID* actorID)
        {
			map<s32,ISceneNode*>::Node* node = mActorSceneNodeMap.find(actorID->HashedText);

			if(node)
				return node->getValue();

			return 0;
        }
		//-----------------------------------------------------------------------------------------
		void SceneView::addSceneNode(const gaming::SActorArgs& args, const gaming::AI_ACTOR_ID* actorID)
		{

		}
		//-----------------------------------------------------------------------------------------
        void SceneView::loadScene(const c8 *sceneName)
        {
			mSceneManager->getFileSystem()->addZipFileArchive(sceneName);
            mSceneManager->loadScene("Scene.irr", this);
        }
        //-----------------------------------------------------------------------------------------
        void SceneView::render( u32 currentTimeMs, u32 elapsedTimeMs)
        {
			mSceneManager->drawAll();
        }
        //-----------------------------------------------------------------------------------------
		void SceneView::update( u32 elapsedTimeMs)
        {
            
        }
        //-----------------------------------------------------------------------------------------------
		void SceneView::OnCreateNode(ISceneNode* node)
		{
			if(node->getType() == scene::ESNT_CAMERA)
			{
				mDefaultCamera = static_cast<ICameraSceneNode*>(node);
			}
		}
        //-----------------------------------------------------------------------------------------------		
		void SceneView::OnReadUserData(ISceneNode* forSceneNode, io::IAttributes* userData)
		{
			//if(ESNT_MESH == forSceneNode->getType())
			//{
			//	IMeshSceneNode* mesh =  static_cast<IMeshSceneNode*>(forSceneNode);
			//	ActorArgs* args = new MeshActorArgs();

			//	args->setNodeType("mesh");
			//	args->setPosition(mesh->getPosition());
			//	args->setRotation(mesh->getRotation());
			//	args->setScale(mesh->getScale());

			//	NewActorEventArgs* e = new NewActorEventArgs(ActorID(forSceneNode->getName()), args);

			//	mActorSceneNodeMap[e->getActorID().getHashedName()] = forSceneNode;

			//	mEventManager->enqueueEvent(e);
			//}
		}
		//-----------------------------------------------------------------------------------------------
		io::IAttributes* SceneView::createUserData(ISceneNode* forSceneNode)
		{
			return 0;
		}
    }
}

