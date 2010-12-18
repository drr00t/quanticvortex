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


#ifndef __GAME_VIEW_CREATE_COMMAND_ARGS_H_
#define __GAME_VIEW_CREATE_COMMAND_ARGS_H_


#include "qvCommandArgs.h"
#include "qvViewsCommandTypes.h"
#include "qvGameViewTypes.h"



namespace qv
{
namespace views
{

class GameViewCreateCommandArgs: public qv::CommandArgs
{
public:

	GameViewCreateCommandArgs()
		:qv::CommandArgs(qv::views::CT_GAME_VIEW_CREATE)
	{

	}
	/// create a event argument with type

	virtual ~GameViewCreateCommandArgs()
	{

	}

	const qv::views::GVT_GAME_VIEW_TYPE& getGameViewType() const;
	/// game view type

	const qv::views::GVI_GAME_VIEW_ID& getGameViewId() const;
	/// get game view type

	void setGameViewType(const qv::views::GVT_GAME_VIEW_TYPE& gameViewType);
	/// set game view name

	void setGameViewId(const qv::views::GVI_GAME_VIEW_ID& gameViewId);

private:

	qv::views::GVT_GAME_VIEW_TYPE mGameViewType; // human view name
	qv::views::GVI_GAME_VIEW_ID mGameViewId;

};


//inlines
inline const qv::views::GVT_GAME_VIEW_TYPE& GameViewCreateCommandArgs::getGameViewType() const
{
	return mGameViewType;
}

inline void GameViewCreateCommandArgs::setGameViewType( const qv::views::GVT_GAME_VIEW_TYPE& gameViewType)
{
	mGameViewType = gameViewType;
}

inline const qv::views::GVI_GAME_VIEW_ID& GameViewCreateCommandArgs::getGameViewId() const
{
	return mGameViewId;
}

inline void GameViewCreateCommandArgs::setGameViewId( const qv::views::GVI_GAME_VIEW_ID& gameViewId)
{
	mGameViewId = gameViewId;
}
}
}

#endif
