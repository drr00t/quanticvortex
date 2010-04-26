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

#include "qvSceneViewIrrlicht.h"

#include "qvEngineManager.h"
#include "qvEventManager.h"
//#include "qvICameraActorAddedEventArgs.h"

#include "IFileSystem.h"
#include "IMeshSceneNode.h"
#include "irrTypes.h"

namespace qv
{
    namespace views
    {
        //-----------------------------------------------------------------------------------------
        SceneViewIrrlicht::SceneViewIrrlicht( const c8* name, EngineManager* engine, u32 elementViewHashType)
			:mVisible(true), mDefaultCamera(0), mSceneManager(0),
			mEventManager(engine->getEventManager()), mElementViewHashType(elementViewHashType)//, mOrder(1) //first element view to render
        {

//#ifdef _DEBUG
//			setDebugName("SceneView");
//#endif
			mID = HASH_STRING(name);
        }
        //-----------------------------------------------------------------------------------------
        SceneViewIrrlicht::~SceneViewIrrlicht()
        {
			mSceneManager = 0;
			ActorSceneNodeMap::ParentLastIterator itrActor = mActorSceneNodeMap.getParentLastIterator();

			while(!itrActor.atEnd())
				mActorSceneNodeMap.delink(itrActor->getKey());
        }
        //-----------------------------------------------------------------------------------------
		irr::scene::ISceneNode* SceneViewIrrlicht::findSceneNode( u32 actorHashId)
        {
//			map<s32,ISceneNode*>::Node* node = mActorSceneNodeMap.find(actorID->HashedText);
//
//			if(node)
//				return node->getValue();

			return 0;
        }
		//-----------------------------------------------------------------------------------------
		void SceneViewIrrlicht::addSceneNode(const gaming::SActorArgs& args,  u32 actorHashId)
		{

		}
		//-----------------------------------------------------------------------------------------
        void SceneViewIrrlicht::loadScene(const c8 *sceneName)
        {
			mSceneManager->getFileSystem()->addZipFileArchive(sceneName);
//            mSceneManager->loadScene("Scene.irr", this);
        }
        //-----------------------------------------------------------------------------------------
        void SceneViewIrrlicht::render( u32 currentTimeMs, u32 elapsedTimeMs)
        {
			mSceneManager->drawAll();
        }
        //-----------------------------------------------------------------------------------------
		void SceneViewIrrlicht::update( u32 elapsedTimeMs)
        {

        }
        //-----------------------------------------------------------------------------------------------
		void SceneViewIrrlicht::OnCreateNode(irr::scene::ISceneNode* node)
		{
		}
        //-----------------------------------------------------------------------------------------------
		void SceneViewIrrlicht::OnReadUserData(irr::scene::ISceneNode* forSceneNode, irr::io::IAttributes* userData)
		{
            irr::core::stringc nodeName = forSceneNode->getName();
            irr::core::stringc exporterName = userData->getAttributeAsString("Exporter");
            bool hasPhysics = userData->getAttributeAsBool("Physics.Enabled");

            //processing scene attributes
            if(nodeName.equals_ignore_case("root"))
            {
                //only irrb has physics attributes
                if(exporterName.equals_ignore_case("irrb"))
                {
                    if(hasPhysics)
                    {
                        real gravity=-9.8f;

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

                irr::scene::ICameraSceneNode* camera(0);
                irr::scene::IMeshSceneNode* meshNode(0);

                switch(forSceneNode->getType())
                {
                case irr::scene::ESNT_CAMERA:

                    //2 - fire event for camera added, this cameras should be storage by camera system, to control camera effets, etc...
                    camera = static_cast<irr::scene::ICameraSceneNode*>(forSceneNode);
                    break;

                case irr::scene::ESNT_EMPTY:
                    // 3 - will be my marckers, zones (aabb), waypoints, etc... used on AI and Physics
                    //scene::ISceneNode* emptyNode = forSceneNode;
                    break;

                case irr::scene::ESNT_MESH:

                    meshNode = static_cast<irr::scene::IMeshSceneNode*>(forSceneNode);

                    if(meshNode && !ghostObject && userData->existsAttribute("HWHint") &&
                        userData->existsAttribute("HWType"))
                    {
                        irr::scene::IMesh* staticMesh = meshNode->getMesh();

                        //hardware mapping for mesh
                        irr::scene::E_HARDWARE_MAPPING  hwMapping = irr::scene::EHM_STATIC;

                        if(userData->getAttributeAsString("HWHint").equals_ignore_case("never"))
                            hwMapping = irr::scene::EHM_NEVER;

                        else if(userData->getAttributeAsString("HWHint").equals_ignore_case("dynamic"))
                            hwMapping = irr::scene::EHM_DYNAMIC;

                        else if(userData->getAttributeAsString("HWHint").equals_ignore_case("stream"))
                            hwMapping = irr::scene::EHM_STREAM;

                        //vertex and index buffer caching
                        irr::scene::E_BUFFER_TYPE hwBufferType = irr::scene::EBT_NONE;

                        if(userData->getAttributeAsString("HWType").equals_ignore_case("vertex"))
                            hwBufferType = irr::scene::EBT_VERTEX;

                        else if(userData->getAttributeAsString("HWType").equals_ignore_case("index"))
                            hwBufferType = irr::scene::EBT_INDEX;

                        else if(userData->getAttributeAsString("HWType").equals_ignore_case("vertexindex"))
                            hwBufferType = irr::scene::EBT_VERTEX_AND_INDEX;

                        staticMesh->setHardwareMappingHint(hwMapping, hwBufferType);
                    }
                    break;

                case irr::scene::ESNT_LIGHT:

                    break;

                default:
                    break;
                }
            }
		}
		//-----------------------------------------------------------------------------------------------
		irr::io::IAttributes* SceneViewIrrlicht::createUserData(irr::scene::ISceneNode* forSceneNode)
		{
			return 0;
		}
    }
}

