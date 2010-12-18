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

#include <string>

namespace qv
{

struct SHashedString
/// hashed string a converter from string to __int32 value
/// to be used for fast comparations.

{
    SHashedString()
    :Hash(0)
    {
#ifdef _DEBUG
        Text = "";
#endif

    }

    SHashedString(const c8* text, qv::u32 hash)
    :Hash(hash)
    {
#ifdef _DEBUG
        Text = text;
#endif

    }
    
    SHashedString(const c8* text)
    /// generate hash for text parameter
    {
#ifdef _DEBUG
        Text = std::string(text);
        Hash = qv::createMurmurHash2(Text.c_str(), Text.size(), 0);
#else
        Hash = qv::createMurmurHash2(text, std::string(text).size(), 0);
#endif
    }

    // operators
    SHashedString (const SHashedString& other)
    {
        *this = other;
    }
    
    SHashedString& operator=( const SHashedString& other)
    {
#ifdef _DEBUG
        Text = other.Text;
#endif
        Hash = other.Hash;

        return *this;
    }

    bool operator==( const SHashedString& other) const
    {
#ifdef _DEBUG
        return ((Hash == other.Hash) && (Text == other.Text));
#else
        return (Hash == other.Hash);
#endif
    }
//    bool operator!=( const SHashedString& other) const;

    qv::u32 Hash;
    /// hash of text passed by user

#ifdef _DEBUG
    std::string Text;
    /// text used to generate hash, use just for debug
    /// this attribute will not be avaible in release build
#endif

};

}
#endif
