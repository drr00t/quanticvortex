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
#include "qvIEventManager.h"
//#include "qvICameraActorAddedEventArgs.h"


namespace qv
{
    namespace views
    {
        //-----------------------------------------------------------------------------------------
        SceneView::SceneView( const c8* name, IEngineManager* engine, const EVT_ELEMENT_VIEW_TYPE* type)
			:mVisible(true), mDefaultCamera(0), mSceneManager(engine->getDevice()->getSceneManager()),
			mEventManager(engine->getEventManager())//, mOrder(1) //first element view to render
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
		}
        //-----------------------------------------------------------------------------------------------		
		void SceneView::OnReadUserData(ISceneNode* forSceneNode, io::IAttributes* userData)
		{
            stringc nodeName = forSceneNode->getName();
            stringc exporterName = userData->getAttributeAsString("Exporter");
            bool hasPhysics = userData->getAttributeAsBool("Physics.Enabled");

            //processing scene attributes
            if(nodeName.equals_ignore_case("root"))
            {   
                //only irrb has physics attributes
                if(exporterName.equals_ignore_case("irrb"))
                {
                    if(hasPhysics)
                    {
                        f32 gravity=-9.8f;
                        
                        if(userData->existsAttribute("Gravity"))
                            gravity = userData->getAttributeAsFloat("Gravity");
                        
                        //1 - fire event to configure physics system gravity
                        //getPhysicsManager()->setGravity(TVector3(0.f,gravity,0.f));
                    }
                }
            }
            else // Real SceneNodes
            {
                bool ghostObject = false;

                if(hasPhysics)
                {
                    ghostObject = userData->getAttributeAsBool("Physics.Ghost");
                }

                scene::ICameraSceneNode* camera(0);
                scene::IMeshSceneNode* meshNode(0);

                switch(forSceneNode->getType())
                {
                case scene::ESNT_CAMERA:

                    //2 - fire event for camera added, this cameras should be storage by camera system, to control camera effets, etc...
                    camera = static_cast<scene::ICameraSceneNode*>(forSceneNode);
                    break;

                case scene::ESNT_EMPTY:  
                    // 3 - will be my marckers, zones (aabb), waypoints, etc... used on AI and Physics
                    //scene::ISceneNode* emptyNode = forSceneNode;
                    break;

                case scene::ESNT_MESH:
                    
                    meshNode = static_cast<scene::IMeshSceneNode*>(forSceneNode);

                    if(meshNode && !ghostObject && userData->existsAttribute("HWHint") &&
                        userData->existsAttribute("HWType"))
                    {
                        scene::IMesh* staticMesh = meshNode->getMesh();

                        //hardware mapping for mesh
                        scene::E_HARDWARE_MAPPING  hwMapping = scene::EHM_STATIC;

                        if(userData->getAttributeAsString("HWHint").equals_ignore_case("never"))
                            hwMapping = scene::EHM_NEVER;

                        else if(userData->getAttributeAsString("HWHint").equals_ignore_case("dynamic"))
                            hwMapping = scene::EHM_DYNAMIC;

                        else if(userData->getAttributeAsString("HWHint").equals_ignore_case("stream"))
                            hwMapping = scene::EHM_STREAM;

                        //vertex and index buffer caching
                        scene::E_BUFFER_TYPE hwBufferType = scene::EBT_NONE;

                        if(userData->getAttributeAsString("HWType").equals_ignore_case("vertex"))
                            hwBufferType = scene::EBT_VERTEX;
                        
                        else if(userData->getAttributeAsString("HWType").equals_ignore_case("index"))
                            hwBufferType = scene::EBT_INDEX;
                        
                        else if(userData->getAttributeAsString("HWType").equals_ignore_case("vertexindex"))
                            hwBufferType = scene::EBT_VERTEX_AND_INDEX;

                        staticMesh->setHardwareMappingHint(hwMapping, hwBufferType);
                    }
                    break;

                case scene::ESNT_LIGHT:

                    break;
                
                default:
                    break;
                }
            }
		}
		//-----------------------------------------------------------------------------------------------
		io::IAttributes* SceneView::createUserData(ISceneNode* forSceneNode)
		{
			return 0;
		}
    }
}

