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


#ifndef __LIBRARY_ADDIN_H_
#define __LIBRARY_ADDIN_H_


#include "qvCompileConfig.h"
#include "qvAddin.h"


typedef qv::Addin* (*ADDIN_DLL_START)(qv::Game* game);
typedef void (*ADDIN_DLL_STOP)(qv::Addin* addin);

static const char* METHOD_ADDIN_START = "dlLoadAddin";
static const char* METHOD_ADDIN_STOP  = "dlUnloadAddin";

namespace qv
{
class Game;
}


namespace qv
{


class LibraryAddin
	/// Virtual FileSystem wrapper
{

public:
	LibraryAddin(const qv::c8* addinFileName)
	:mLoaded(false)
	{
		//preciso armazenar os addins carregados para poder liberar depois.
		mAddinDLLInstance = LIB_LOAD(addinFileName);
		
		if(mAddinDLLInstance)
			mLoaded = true;

	}

	virtual ~LibraryAddin()
	{
		LIB_UNLOAD(mAddinDLLInstance);
	}

	bool loaded() const
	{
		return mLoaded;
	}
	
	qv::Addin* getAddin()
	{
		return mAddin;
	}
	
	qv::Addin* load(qv::Game* game)
	{
		ADDIN_DLL_START dlStartMethod = (ADDIN_DLL_START) LIB_SYMBOL(mAddinDLLInstance, METHOD_ADDIN_START);
		 mAddin = dlStartMethod(game);
		 return mAddin;
	}

	void unload()
	{

		ADDIN_DLL_STOP dlStopMethod = (ADDIN_DLL_STOP) LIB_SYMBOL(mAddinDLLInstance, METHOD_ADDIN_STOP);
		
		dlStopMethod(mAddin);
	}

private:
	qv::Addin* mAddin;
	LIB_INSTANCE mAddinDLLInstance;
	bool mLoaded;

};

}

#endif
