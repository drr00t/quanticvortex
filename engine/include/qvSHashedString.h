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


#ifndef __S_HASHED_STRING_H_
#define __S_HASHED_STRING_H_

#include "qvPrerequisites.h"

#include "qvSuperFastHash.h"

namespace qv
{
	struct SHashedString: IReferenceCounted
    {
		//-------------------------------------------------------------------------
		SHashedString()
			:Text(0),HashedText(0)
		{
		}
		//-------------------------------------------------------------------------
		SHashedString(const c8* text)
			:Text(text)
		{
			Text.make_upper();
			HashedText = createSuperFastHash(Text);
		}
		//-------------------------------------------------------------------------
		SHashedString(const c8* text, u32 hashedText)
			:Text(text), HashedText(hashedText)
		{
		}
		//-------------------------------------------------------------------------
		SHashedString( const SHashedString &other )
		{
			*this= other;
		}
		//-------------------------------------------------------------------------
		//operators
		//-------------------------------------------------------------------------
		SHashedString& operator= ( const SHashedString &other )
		{
			Text = other.Text;
			HashedText = other.HashedText;

			return *this;
		}
		//-------------------------------------------------------------------------
		bool operator== ( const SHashedString &other ) const
		{
#ifdef _DEBUG
		return ((Text == other.Text) && (HashedText == other.HashedText));	
#else
		return (HashedText == other.HashedText);
#endif
		}
		//-------------------------------------------------------------------------	    
		bool operator!= ( const SHashedString &other ) const
		{
#	ifdef _DEBUG
			return ((HashedText != other.HashedText) && (Text != other.Text));
			//TODO: I will need debug possible hashe collisions
#	else
			return (HashedText != other.HashedText);
#	endif	
		}
		//-------------------------------------------------------------------------
		bool operator< ( const SHashedString &other ) const
		{
			return (HashedText < other.HashedText);
		}
		//-------------------------------------------------------------------------
		bool operator> ( const SHashedString &other ) const
		{
			return (HashedText > other.HashedText);
		}
		//-------------------------------------------------------------------------

		stringc Text;
		u32 HashedText;
    };
}
#endif

