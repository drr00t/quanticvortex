/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009 QuanticMinds Software Ltda.
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


#include "qvDefaultElementViewFactory.h"
#include "qvSceneView.h"
#include "qvGuiView.h"

namespace qv
{
    namespace views
    {
        //-----------------------------------------------------------------------------------------
        DefaultElementViewFactory::DefaultElementViewFactory(IEngineManager* engine)
            :mEngine(engine)
        {
            mSupportedElementViewTypes.push_back(EVT_ELEMENT_VIEW_SCENE.ID);
            mSupportedElementViewTypes.push_back(EVT_ELEMENT_VIEW_GUI.ID);
        }
        //-----------------------------------------------------------------------------------------
        DefaultElementViewFactory::~DefaultElementViewFactory()
        {
        }
		//-----------------------------------------------------------------------------------------------
        IElementView* DefaultElementViewFactory::addElementView( const c8* name, const EVT_ELEMENT_VIEW_TYPE& type)
		{
            IElementView* elementView = 0;

            if(type == EVT_ELEMENT_VIEW_SCENE)
                elementView = new SceneView(name, mEngine);

            else if(type == EVT_ELEMENT_VIEW_GUI)
                elementView = new GuiView(name, mEngine);

			return elementView;
		}
        //-----------------------------------------------------------------------------------------
        u32 DefaultElementViewFactory::getCreatableElementViewTypeCount() const
        {
            return mSupportedElementViewTypes.size();
        }
        //-----------------------------------------------------------------------------------------
        bool DefaultElementViewFactory::getCreateableElementViewType(const EVT_ELEMENT_VIEW_TYPE& type)
        {
	        for (u32 i=0; i<mSupportedElementViewTypes.size(); ++i)
				if (mSupportedElementViewTypes[i] == type.ID)
			        return true;

            return false;

        }
        //-----------------------------------------------------------------------------------------
    }
}