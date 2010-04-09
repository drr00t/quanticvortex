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

#ifndef __I_SCENE_VIEW_H_
#define __I_SCENE_VIEW_H_

#include "qvIElementView.h"
#include "qvIActor.h"

#include "ICameraSceneNode.h"
#include "ISceneManager.h"

namespace qv
{

	namespace gaming
	{
		struct SActorArgs;
	}

    namespace views
    {
        static const EVT_ELEMENT_VIEW_TYPE EVT_ELEMENT_VIEW_SCENE = HASH_STRING("EVT_ELEMENT_VIEW_SCENE");

		class ISceneView: public IElementView //, public ISceneUserDataSerializer
        {
        public:

			virtual irr::scene::ICameraSceneNode* getCamera() = 0;
			virtual void setCamera(irr::scene::ICameraSceneNode* camera) = 0;

			virtual irr::scene::ISceneManager* getSceneManager() = 0;

         //   virtual void render( u32 currentTimeMs, u32 elapsedTimeMs)=0;
	        //virtual void update( u32 elapsedTimeMs)=0;

			virtual void loadScene(const c8* sceneName) = 0;

			virtual void addSceneNode(const gaming::SActorArgs& args, u32 actorHashId = 0) = 0;
			virtual irr::scene::ISceneNode* findSceneNode( u32 actorHashId) = 0;

			//virtual void OnCreateNode(ISceneNode* node)=0;
			//virtual void OnReadUserData(ISceneNode* forSceneNode, io::IAttributes* userData)=0;
			//virtual io::IAttributes* createUserData(ISceneNode* forSceneNode)=0;
		};
    }
}
#endif

