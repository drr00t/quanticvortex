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

#include "qvCompileConfig.h"
#include "qvTypes.h"
#include "qvHashFunctions.h"

#include "irrString.h"

namespace qv
{

struct SHashedString
/// hashed string a converter from string to __int32 value
/// to be used for fast comparations.

{
    SHashedString(const c8* text)
    /// generate hash for text parameter
    {
#ifdef _DEBUG
        Text = irr::core::stringc(text);
        Hash = qv::createMurmurHash2(Text.c_str(), Text.size(), 0);
#else
        Hash = qv::createMurmurHash2(text, irr::core::stringc(text).size(), 0);
#endif
    }

    // operators
//    SHashedString& operator=( const SHashedString& other)
//    {
//#ifdef _DEBUG
//        this->Text = other.Text;
//#endif
//
//        this->Hash = other.Hash;
//
//        return *this;
//    }

    bool operator==( const SHashedString& other) const
    {
#ifdef _DEBUG
        return ((this->Hash == other.Hash) && (this->Text == other.Text));
#else
        return (this->Hash == other.Hash);
#endif
    }
//    bool operator!=( const SHashedString& other) const;

    qv::u32 Hash;
    /// hash of text passed by user

#ifdef _DEBUG
    irr::core::stringc Text;
    /// text used to generate hash, use just for debug
    /// this attribute will not be avaible in release build
#endif

};

//    bool SHashedString::operator==( const SHashedString& other) const
//    {
//#ifdef _DEBUG
//        return ((this->Hash == other.Hash) && (this->Text == other.Text));
//#else
//        return (this->Hash == other.Hash);
//#endif
//    }
//
//    bool SHashedString::operator!=( const SHashedString& other) const
//    {
//#ifdef _DEBUG
//        return ((this->Text != other.Text) && (this->Hash != other.Hash));
//#else
//        return (this->Hash != other.Hash);
//#endif
//    }

//extern "C" _QUANTICVORTEX_API_ SHashedString QUANTICVORTEX_CALLCONV createHashedString( const qv::c8* text);
}
#endif
