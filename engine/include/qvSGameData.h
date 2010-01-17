
#ifndef __SGAMEDATA_H_
#define __SGAMEDATA_H_

#include "qvPrerequisites.h"
#include "qvIGameView.h"

using namespace qv::gaming;

namespace qv
{
    namespace gaming
    {
	    struct SGameData
        {

		    SGameData()
		    {
		    }

		    SGameData(const SGameData& other)
		    {
			    *this = other;
		    }

		    SGameData& operator= (const SGameData& other)
		    {

			    return *this;
		    }
	    };
    }
}
#endif

