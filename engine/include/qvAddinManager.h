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


#ifndef __ADDIN_MANAGER_H_
#define __ADDIN_MANAGER_H_

#include <vector>

#include "qvCompileConfig.h"

#include "qvLibraryAddin.h"
#include "qvAddin.h"

namespace qv
{
	class Game;
}




namespace qv
{


class _QUANTICVORTEX_API_ AddinManager
	/// manager all addins dlls loaded to extend the engine core
{

public:

	AddinManager(qv::Game* game);
	virtual ~AddinManager();

	qv::Addin* load(const qv::c8* addinLibraryName);
	void unload(qv::Addin* addin);

	

private:
	AddinManager(const AddinManager&);
	AddinManager& operator = (const AddinManager&);
	
	qv::Game* mGame;
	std::vector<qv::LibraryAddin*> mLibraryAddins;

};


}

#endif
