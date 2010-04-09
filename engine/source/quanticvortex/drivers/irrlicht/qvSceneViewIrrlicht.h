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

#ifndef __SCENE_VIEW_IRRLICHT_H_
#define __SCENE_VIEW_IRRLICHT_H_

#include "qvISceneView.h"

#include "irrMap.h"

namespace qv
{
    class IEngineManager;

	namespace events
	{
		class IEventManager;
	}

    namespace views
    {
		typedef irr::core::map<s32, irr::scene::ISceneNode*> ActorSceneNodeMap;

		class SceneViewIrrlicht: public ISceneView
        {

        public:
            SceneViewIrrlicht( const c8* name, IEngineManager* engine, u32 elementViewHashType = EVT_ELEMENT_VIEW_SCENE.Hash);
			virtual ~SceneViewIrrlicht();

            virtual u32 getHashId() const { return mID.Hash; }

            virtual u32 getHashType() const { return mElementViewHashType; }

	        virtual bool getVisible() const { return mVisible; }

            virtual void setVisible(bool visible) { mVisible = visible; }

            virtual void setCamera(irr::scene::ICameraSceneNode* camera) { mDefaultCamera = camera; }

			virtual irr::scene::ICameraSceneNode* getCamera() { return mDefaultCamera; }

			virtual irr::scene::ISceneManager* getSceneManager() { return mSceneManager; }

            virtual void render( u32 currentTimeMs, u32 elapsedTimeMs);

			virtual void update( u32 elapsedTimeMs);

			virtual void loadScene(const c8* sceneName);

			virtual void addSceneNode(const gaming::SActorArgs& args, u32 actorHashId = 0);

			virtual irr::scene::ISceneNode* findSceneNode( u32 actorHashId);

			virtual void OnCreateNode(irr::scene::ISceneNode* node);

			virtual void OnReadUserData(irr::scene::ISceneNode* forSceneNode, irr::io::IAttributes* userData);

			virtual irr::io::IAttributes* createUserData(irr::scene::ISceneNode* forSceneNode);

		protected:

            bool mVisible;
			irr::scene::ICameraSceneNode* mDefaultCamera;
			irr::scene::ISceneManager* mSceneManager;
			events::IEventManager* mEventManager;
            u32 mElementViewHashType;
            EVI_ELEMENT_VIEW_ID mID;
            ActorSceneNodeMap mActorSceneNodeMap;

		};
    }
}
#endif

