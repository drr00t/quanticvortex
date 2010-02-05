
#ifndef __SGAMEPARAMS_H_
#define __SGAMEPARAMS_H_

#include "qvPrerequisites.h"

namespace qv
{
	struct SGameLogicParams
    {

		SGameLogicParams()
		{
		}

		SGameLogicParams(const SGameLogicParams& other)
		{
			*this = other;
		}

		SGameLogicParams& operator= (const SGameLogicParams& other)
		{


			return *this;
		}

        //texture size
        //detail level
        //shadow maps
        //realtime shadows
	};
}
#endif

