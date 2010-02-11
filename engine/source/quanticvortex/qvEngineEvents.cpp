
#include "events/qvEngineEvents.h"


namespace qv
{
    namespace events
    {
        ///game startup

        //game graphics
		const EventType GraphicsStartedEventArgs::mEventType("GraphicsSystemStarted");

		GraphicsStartedEventArgs::GraphicsStartedEventArgs(const f32& timestamp)
			:mTimestamp(timestamp)
		{
		}
		
		GraphicsStartedEventArgs::~GraphicsStartedEventArgs()
		{
		}
//-------------------------------------------------------------------------------------------------

        //game PhysicsStarted
		const EventType PhysicsStartedEventArgs::mEventType("PhysicsSystemStarted");

		PhysicsStartedEventArgs::PhysicsStartedEventArgs(const f32& timestamp)
			:mTimestamp(timestamp)
		{
		}
		
		PhysicsStartedEventArgs::~PhysicsStartedEventArgs()
		{
		}
//-------------------------------------------------------------------------------------------------

        //game EventSystemStarted
		const EventType EventSystemStartedEventArgs::mEventType("EventSystemStarted");

		EventSystemStartedEventArgs::EventSystemStartedEventArgs(const f32& timestamp)
			:mTimestamp(timestamp)
		{
		}
		
		EventSystemStartedEventArgs::~EventSystemStartedEventArgs()
		{
		}
//-------------------------------------------------------------------------------------------------

        //game HumanViewAttached
		const EventType HumanViewAttachedEventArgs::mEventType("HumanViewAttached");

		HumanViewAttachedEventArgs::HumanViewAttachedEventArgs(const f32& timestamp)
			:mTimestamp(timestamp)
		{
		}
		
		HumanViewAttachedEventArgs::~HumanViewAttachedEventArgs()
		{
		}
//-------------------------------------------------------------------------------------------------

        //game GameLogicStarted
		const EventType GameLogicStartedEventArgs::mEventType("GameLogicStarted");

		GameLogicStartedEventArgs::GameLogicStartedEventArgs(const f32& timestamp)
			:mTimestamp(timestamp)
		{
		}
		
		GameLogicStartedEventArgs::~GameLogicStartedEventArgs()
		{
		}
//-------------------------------------------------------------------------------------------------
        ////game events
//-----------------------------------------------------------------------------
		const EventType NewGameEventArgs::mEventType("NewGame");

		NewGameEventArgs::NewGameEventArgs(const f32& timestamp)
			:mTimestamp(timestamp)
		{
		}
		
		NewGameEventArgs::~NewGameEventArgs()
		{
		}

        //-----------------------------------------------------------------------------
        const EventType GameStateEventArgs::mEventType("GameState");

		GameStateEventArgs::GameStateEventArgs(const f32& timestamp)
			:mTimestamp(timestamp)
		{
		}
		
		GameStateEventArgs::~GameStateEventArgs()
		{
		}

		//const EventType& GameStateEventArgs::getEventType() const
  //      {
  //          return mEventType;
  //      }

        const f32 GameStateEventArgs::getTimeStamp() const
        {
            return mTimestamp;
        }
//-----------------------------------------------------------------------------
        const EventType UpdateTickEventArgs::mEventType("UpdateTick");

		UpdateTickEventArgs::UpdateTickEventArgs(const f32& timestamp)
			:mTimestamp(timestamp)
		{
		}
		
		UpdateTickEventArgs::~UpdateTickEventArgs()
		{
		}

		//static const EventType& UpdateTickEventArgs::getEventType() const
  //      {
  //          return mEventType;
  //      }

        const f32 UpdateTickEventArgs::getTimeStamp() const
        {
            return mTimestamp;
        }
//-----------------------------------------------------------------------------
        const EventType NewActorEventArgs::mEventType("NewActor");

        NewActorEventArgs::NewActorEventArgs(ActorID& actorID, ActorArgs* args)
            :mActorID(actorID), mArgs(args)
		{
		}
		
		NewActorEventArgs::~NewActorEventArgs()
		{
		}

//----------------------------------------------------------------------------
        const EventType DestroyActorEventArgs::mEventType("DestroyActor");

		DestroyActorEventArgs::DestroyActorEventArgs(ActorID& actorID)
			:mActorID(actorID)
		{
		}
		
		DestroyActorEventArgs::~DestroyActorEventArgs()
		{
		}

//-------------------------------------------------------------------------------------------------
		const EventType MoveActorEventArgs::mEventType("MoveActor");

		MoveActorEventArgs::MoveActorEventArgs(ActorID& actorID, vector3df& direction)
			:mActorID(actorID),mDirection(direction)
		{
		}
		
		MoveActorEventArgs::~MoveActorEventArgs()
		{
		}

//-------------------------------------------------------------------------------------------------

        ////network
        //const EventType EvtData_Remote_Client::sk_EventType( "remote_client" );
        //const EventType EvtData_Network_Player_Actor_Assignment::sk_EventType ( "netplayer_actor_assign" );
        //const EventType EvtData_Request_Start_Game::sk_EventType( "game_request_start" );

        //const EventType EvtData_Debug_String::sk_EventType( "debug_string" );
        //const EventType EvtData_Decompress_Request::sk_EventType( "decompress_request" );
        //const EventType EvtData_Decompression_Progress::sk_EventType( "decompression_progress" );

        //const EventType EvtData_UpdateActorParams::sk_EventType( "update_actor_params" );

        //// Note: these are game specific events, which really should be in TeapotEvents.cpp.
        //// They aren't because of an annoying dependancy in Network.cpp, which creates events
        //// from a bitstream. Once we get "real" streaming code in we can move these back to TeapotEvents.cpp.
        //const EventType EvtData_Fire_Weapon::sk_EventType( "fire_weapon" );
        //const EventType EvtData_Thrust::sk_EventType( "thrust" );
        //const EventType EvtData_Steer::sk_EventType( "steer" );
    }
}
