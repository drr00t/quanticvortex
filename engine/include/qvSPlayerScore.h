
#ifndef __SGAMEDATA_H_
#define __SGAMEDATA_H_

#include "qvPrerequisites.h"
#include "qvIGameView.h"

using namespace qv::gaming;

namespace qv
{
    namespace gaming
    {

        struct SPlayerScore
        {
            SPlayerScore()
            {
            }

            SPlayerScore(const AI_ACTOR_ID& actor, const views::GVT_GAME_VIEW_TYPE& attachedViewType, u32 score = 0, u8 level = 1)
                :Actor(actor), Score(score), AttachedViewType(attachedViewType),Level(level)
            {
            }
            
            SPlayerScore(const SPlayerScore& other)
            {
                *this = other;
            }

            SPlayerScore& operator=(const SPlayerScore& other)
            {
                Level = other.Level;
                Actor = other.Actor;
                Score = other.Score;
                AttachedViewType = other.AttachedViewType;

                return *this;
            }

            //
            //bool operator==(const SGameActorScore& other)
            //{
            //    ID = other.ID;
            //    Score = other.Score;
            //    AttachedViewType = other.AttachedViewType;

            //    return *this;
            //}

            u8 Level;
            AI_ACTOR_ID Actor;
            u32 Score;
            views::GVT_GAME_VIEW_TYPE AttachedViewType;
            
        };
    }
}
#endif

