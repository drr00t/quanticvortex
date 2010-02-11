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
//#include "qvSuperFastHash.h"

#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const u16 *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((u32)(((const u8 *)(d))[1])) << 8)\
					   +(u32)(((const u8 *)(d))[0]) )
#endif

namespace qv
{
    struct HashedString
    {
		stringc Name;
        u32 ID;

		//-------------------------------------------------------------------------
		HashedString()
		{
		}
		//-------------------------------------------------------------------------
		HashedString(const c8* name)
			//:Name(name)
		{
			PrepareHash(name);
			//Name.make_lower();
			//ID = SuperFastHash(Name.c_str(),Name.size());
		}
		//-------------------------------------------------------------------------
		HashedString( const HashedString &other )
		{
			*this= other;
		}
		//-------------------------------------------------------------------------
		void createHashedString(const c8* name)
		{
			PrepareHash(name); 
		}
		//-------------------------------------------------------------------------
		void createHashedString(const stringc& name)
		{
			PrepareHash(name.c_str());
		}
		//operators
		//-------------------------------------------------------------------------
		HashedString& operator= ( const HashedString &other )
		{
			ID = other.ID;
			Name = other.Name;

			return *this;
		}
		//-------------------------------------------------------------------------
		bool operator== ( const HashedString &other ) const
		{
			return ((ID == other.ID) && (Name == other.Name));
		}
		//-------------------------------------------------------------------------	    
		bool operator!= ( const HashedString &other ) const
		{
			return ((ID != other.ID) && (Name != other.Name));
		}
		//-------------------------------------------------------------------------
		bool operator< ( const HashedString &other ) const
		{
			return (ID < other.ID);
		}
		//-------------------------------------------------------------------------
		bool operator> ( const HashedString &other ) const
		{
			return (ID > other.ID);
		}
		//-------------------------------------------------------------------------
		u32 SuperFastHash (const char * data, u32 len) 
		{
			u32 hash = len, tmp;
			u32 rem;

			if (len <= 0 || data == NULL) return 0;

			rem = len & 3;
			len >>= 2;

			/* Main loop */
			for (;len > 0; len--) {
				hash  += get16bits (data);
				tmp    = (get16bits (data+2) << 11) ^ hash;
				hash   = (hash << 16) ^ tmp;
				data  += 2*sizeof (uint16_t);
				hash  += hash >> 11;
			}

			/* Handle end cases */
			switch (rem) {
				case 3: hash += get16bits (data);
						hash ^= hash << 16;
						hash ^= data[sizeof (u16)] << 18;
						hash += hash >> 11;
						break;
				case 2: hash += get16bits (data);
						hash ^= hash << 11;
						hash += hash >> 17;
						break;
				case 1: hash += *data;
						hash ^= hash << 10;
						hash += hash >> 1;
			}

			/* Force "avalanching" of final 127 bits */
			hash ^= hash << 3;
			hash += hash >> 5;
			hash ^= hash << 4;
			hash += hash >> 17;
			hash ^= hash << 25;
			hash += hash >> 6;

			return hash;
		}
		//-------------------------------------------------------------------------
		void PrepareHash (const c8* data)
		{
			Name = data;
			Name.make_lower();
			ID = SuperFastHash(Name.c_str(),Name.size());
		}

    };
}
#endif

