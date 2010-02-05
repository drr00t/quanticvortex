
#ifndef __ENGINEEVENTS_H_
#define __ENGINEEVENTS_H_

#include "qvPrerequisites.h"
#include "qvIActor.h"
#include "qvActorArgs.h"
#include "qvIEventArgs.h"


using namespace qv::core;

namespace qv
{
    namespace events
    {
		//FIXME: avaliar a possibilidade de serializar os eventos, uma vez que com isso poderei 
		//gravar a execução do jogo e parâmetros usados, reexecutar quando necessário etc...
		// o scene loader iria deserializar os eventos e dispará-los 

        //Game startup
            //GraphicsStarted
		class GraphicsStartedEventArgs: public IEventArgs
		{
		private:
			f32 mTimestamp;

        public:
            static const EventType mEventType;

		public:
			GraphicsStartedEventArgs(const f32& timestamp);
			~GraphicsStartedEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
            const f32 getTimeStamp() const{return mTimestamp;};
		};
//-------------------------------------------------------------------------------------------------
            //PhysicsStarted
		class PhysicsStartedEventArgs: public IEventArgs
		{
		private:
			f32 mTimestamp;

        public:
            static const EventType mEventType;

		public:
			PhysicsStartedEventArgs(const f32& timestamp);
			~PhysicsStartedEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
            const f32 getTimeStamp() const{return mTimestamp;};
		};
//-------------------------------------------------------------------------------------------------
            //EventSystemStarted
		class EventSystemStartedEventArgs: public IEventArgs
		{
		private:
			f32 mTimestamp;

        public:
            static const EventType mEventType;

		public:
			EventSystemStartedEventArgs(const f32& timestamp);
			~EventSystemStartedEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
            const f32 getTimeStamp() const{return mTimestamp;};
		};      
//-------------------------------------------------------------------------------------------------
            //HumanViewAttached
		class HumanViewAttachedEventArgs: public IEventArgs
		{
		private:
			f32 mTimestamp;

        public:
            static const EventType mEventType;

		public:
			HumanViewAttachedEventArgs(const f32& timestamp);
			~HumanViewAttachedEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
            const f32 getTimeStamp() const{return mTimestamp;};
		};      
//-------------------------------------------------------------------------------------------------
            //GameLogicStarted
		class GameLogicStartedEventArgs: public IEventArgs
		{
		private:
			f32 mTimestamp;

        public:
            static const EventType mEventType;

		public:
			GameLogicStartedEventArgs(const f32& timestamp);
			~GameLogicStartedEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
            const f32 getTimeStamp() const{return mTimestamp;};
		};      
//-------------------------------------------------------------------------------------------------
            //SoundsystemStarted
            //resourceCacheStarted
            //NetworkStarted
            //GamePaused
            //GameResumed
            //PreSave
            //PosSave

        //game events
            //ActorMove
            //ActorCollision
            //AICharacterChangeState
            //PlayerState
            //PlayerDeath
            //GameOver
            
//-------------------------------------------------------------------------------------------------
		//Map/Mission events
            //PreLoadLevel
            //LoadedLevel
            //EnterTriggerVolume
            //ExitTriggerVolume
            //PlayerTeleported
        
        //animation and sound events
            //AnimationStarted
            //AnimationLooped
            //AnimationNotetrack compond effects
            //AnimationEnded
            //SoundeffectStarted
            //SoundeffectLooped
            //SoundeffectEnded
            //VideoStarted    cinematic
            //VideoEnded

//-------------------------------------------------------------------------------------------------
        //game engine events
		class NewGameEventArgs: public IEventArgs
		{
		private:
			f32 mTimestamp;

        public:
            static const EventType mEventType;

		public:
			NewGameEventArgs(const f32& timestamp);
			~NewGameEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}

            const f32 NewGameEventArgs::getTimeStamp() const{return mTimestamp;}
		};
//-------------------------------------------------------------------------------------------------
		class GameStateEventArgs: public IEventArgs
		{
		private:
			f32 mTimestamp;
        
        public:
			static const EventType mEventType;
		
        public:
			GameStateEventArgs(const f32& timestamp);
			~GameStateEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
	        const f32 getTimeStamp() const;
		};
//-------------------------------------------------------------------------------------------------
		class UpdateTickEventArgs: public IEventArgs
		{
		private:
			f32 mTimestamp;
        public:			
            static const EventType mEventType;
		public:
			UpdateTickEventArgs(const f32& timestamp);
			~UpdateTickEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
	        const f32 getTimeStamp() const;
		};
//-------------------------------------------------------------------------------------------------
		class NewActorEventArgs: public IEventArgs
		{
		private:
			ActorID mActorID;
            ActorArgs* mArgs;

        public:
			static const EventType mEventType;

		public:
			NewActorEventArgs(ActorID& actorID, ActorArgs* args);
			~NewActorEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
	        const ActorID& getActorID() const{return mActorID;};
            ActorArgs* getActorArgs( void ) {return mArgs;}
		};
//-------------------------------------------------------------------------------------------------
		class DestroyActorEventArgs: public IEventArgs
		{
		private:
			ActorID mActorID;

        public:
			static const EventType mEventType;

		public:
			DestroyActorEventArgs(ActorID& actorID);
			~DestroyActorEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
	        const ActorID& getActorID() const{return mActorID;};
		};
//-------------------------------------------------------------------------------------------------
		class MoveActorEventArgs: public IEventArgs
		{
		private:
			ActorID mActorID;
			vector3df mDirection;

        public:
			static const EventType mEventType;
		public:
			MoveActorEventArgs( ActorID& actorID, vector3df& direction);
			~MoveActorEventArgs();

			const EventType& getEventType( void ) const{return mEventType;}
			vector3df getDirection(){return mDirection;}
		};
//-------------------------------------------------------------------------------------------------
        ////actor events
        //const EventType EvtData_Move_Actor;


        ////network
		//const EventType Request_Start_Game;
        //const EventType EvtData_Remote_Client;
        //const EventType EvtData_Network_Player_Actor_Assignment;

        //const EventType EvtData_Debug_String;
        //const EventType EvtData_Decompress_Request;
        //const EventType EvtData_Decompression_Progress;

        //const EventType EvtData_Request_New_Actor;

        //const EventType EvtData_UpdateActorParams;

        //// Note: these are game specific events, which really should be in TeapotEvents.cpp.
        //// They aren't because of an annoying dependancy in Network.cpp, which creates events
        //// from a bitstream. Once we get "real" streaming code in we can move these back to TeapotEvents.cpp.
        //const EventType EvtData_Fire_Weapon;
        //const EventType EvtData_Thrust;
        //const EventType EvtData_Steer;

    }
}

#endif

