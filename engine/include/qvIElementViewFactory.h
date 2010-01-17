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


#ifndef __IELEMENTVIEWFACTORY_H_
#define __IELEMENTVIEWFACTORY_H_

//#include "qvPrerequisites.h"
#include "qvIElementView.h"

namespace qv
{
    class IEngineManager;

    namespace views
    {

		class IElementViewFactory : public IReferenceCounted
		{
		public:

            virtual IElementView* addElementView( const c8* name, const EVT_ELEMENT_VIEW_TYPE& type) = 0;

			virtual u32 getCreatableElementViewTypeCount() const = 0;

			virtual bool getCreateableElementViewType(const EVT_ELEMENT_VIEW_TYPE& type) = 0;
		};
    }
}
#endif

