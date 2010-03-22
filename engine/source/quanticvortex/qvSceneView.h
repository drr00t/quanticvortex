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

#ifndef __SCENE_VIEW_H_
#define __SCENE_VIEW_H_

#include "qvISceneView.h"

using namespace irr::scene;

namespace qv
{
    class IEngineManager;

	namespace events
	{
		class IEventManager;
	}

    namespace views
    {
		typedef map<s32,ISceneNode*> ActorSceneNodeMap;

		class SceneView: public ISceneView
        {

        public:
            SceneView( const c8* name, IEngineManager* engine, const EVT_ELEMENT_VIEW_TYPE& type = EVT_ELEMENT_VIEW_SCENE);
			virtual ~SceneView();

            virtual u32 getHashId() const { return mID->Hash; }

            virtual u32 getHashType() const { return mHashType; }

	        virtual bool getVisible() const { return mVisible; }

//            virtual const EVT_ELEMENT_VIEW_TYPE* getType()
//            {
//                return mType;
//            }
//
//            virtual const EVI_ELEMENT_VIEW_ID* getID()
//            {
//                return mID;
//            }
//
//			virtual bool getVisible()
//            {
//                return mVisible;
//            }

            virtual void setVisible(bool visible)
            {
                mVisible = visible;
            }

            virtual void setCamera(ICameraSceneNode* camera)
            {
                mDefaultCamera = camera;
            }

			virtual ICameraSceneNode* getCamera()
            {
                return mDefaultCamera;
            }

			virtual ISceneManager* getSceneManager()
            {
                return mSceneManager;
            }

            virtual void render( u32 currentTimeMs, u32 elapsedTimeMs);

			virtual void update( u32 elapsedTimeMs);

			virtual void loadScene(const c8* sceneName);

			virtual void addSceneNode(const gaming::SActorArgs& args, const gaming::AI_ACTOR_ID* actorID = 0);

			virtual ISceneNode* findSceneNode(const gaming::AI_ACTOR_ID* actorID);

			virtual void OnCreateNode(ISceneNode* node);

			virtual void OnReadUserData(ISceneNode* forSceneNode, io::IAttributes* userData);

			virtual io::IAttributes* createUserData(ISceneNode* forSceneNode);

		protected:
			events::IEventManager* mEventManager;
			ISceneManager* mSceneManager;
			ICameraSceneNode* mDefaultCamera;
			ActorSceneNodeMap mActorSceneNodeMap;
            u32 mHashType;
            EVI_ELEMENT_VIEW_ID* mID;
            bool mVisible;
		};
    }
}
#endif

