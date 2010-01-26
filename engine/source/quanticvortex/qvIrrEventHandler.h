

#ifndef __IRR_EVENT_HANDLER_H_
#define __IRR_EVENT_HANDLER_H_

#include "qvIInputReceiver.h"
//#include "qvIEventManager.h"

#include "qvSingleKeyInputTranslator.h"
#include "qvAnyKeyInputTranslator.h"

namespace qv
{
    namespace events
    {   
		class IEventManager;
	}

namespace input
{

	//class ISingleKeyInputTranslator;
	//class IAnyKeyInputTranslator;

	// Keyboard key states.
	//EKEY_STATE mKeyState[KEY_KEY_CODES_COUNT];

	//base implementation released by Seven on Irrlicht forums: 
	//http://irrlicht.sourceforge.net/phpBB2/viewtopic.php?t=34052&highlight=irreventhandler
	class IrrEventHandler : public IInputReceiver
        {

		private:
			//i need see which collection will work bether here
			array<IInputTranslator*> mInputTranslators;
			array<IInputTranslatorFactory*> mInputTranslatorsFactories;

			EKEY_STATE mKeyState[KEY_KEY_CODES_COUNT];

			events::IEventManager* mEventManager;

		public:

			// Mouse data.
			struct SMouseData
			{
			  s32 X;
			  s32 Y;
			  bool LButtonDown;
			  bool RButtonDown;
			  bool MButtonDown;
			  f32 Wheel;
			  f32 WheelDelta;
			};

			struct SMouseData mMouse;

			s32 mouseX()         { return mMouse.X;            }
			s32 mouseY()         { return mMouse.Y;            }
			f32 mouseWheel()      { return mMouse.Wheel;         }
			f32 mouseWheelDelta()   { return mMouse.WheelDelta;   }

			IrrEventHandler(events::IEventManager* eventManager)         
				:mEventManager(eventManager)
			{

#ifdef _DEBUG
			setDebugName("IrrEventHandler");
#endif
				
				for (s32 i = 0; i < KEY_KEY_CODES_COUNT; ++i) mKeyState[i] = EKS_RELEASED;

				mMouse.X = 0;
				mMouse.Y = 0;
				mMouse.Wheel = 0.0f;
				mMouse.WheelDelta = 0.0f;
				mMouse.LButtonDown = false;
				mMouse.RButtonDown = false;
				mMouse.MButtonDown = false;
			};

			virtual ~IrrEventHandler(void)   {}

			virtual IInputTranslator* getInputTranslator( const IT_INPUT_TRANSLATOR_ID* translatorID)
			{
				IInputTranslator* inputTranslator = 0;

				for(u32 i = 0; i < mInputTranslators.size(); ++i)
				{
					if(mInputTranslators[i]->getID()->HashedText == translatorID->HashedText)
					{					
						inputTranslator = mInputTranslators[i];
						break;
					}
				}

				return inputTranslator;				
			}
			
			//translators
			virtual ISingleKeyInputTranslator* addSingleKeyTranslator (const IT_INPUT_TRANSLATOR_ID* ID, EKEY_CODE keyCode, EKEY_STATE checkState, events::IEventArgs* args, bool realTime = false)
			{
				ISingleKeyInputTranslator* translator = new SingleKeyInputTranslator( mEventManager, keyCode, checkState, realTime, args, ID);
				mInputTranslators.push_back(translator);

				return translator;
			}

			virtual ISingleKeyInputTranslator* addSingleKeyTranslator (const IT_INPUT_TRANSLATOR_ID* ID, EKEY_CODE keyCode, EKEY_STATE checkState, const events::ET_EVENT_TYPE* type, bool realTime = false)
			{
				ISingleKeyInputTranslator* translator = new SingleKeyInputTranslator( mEventManager, keyCode, checkState, realTime, type, ID);
				mInputTranslators.push_back(translator);

				return translator;
			}

			virtual IAnyKeyInputTranslator* addAnyKeyTranslator (const IT_INPUT_TRANSLATOR_ID* ID, events::IEventArgs* args, bool realTime = false)
			{
				IAnyKeyInputTranslator* translator = new AnyKeyInputTranslator( mEventManager, realTime, args, ID);
				mInputTranslators.push_back(translator);

				return translator;
			}


			virtual void registerInputTranslator( IInputTranslator* translator)
			{
				IInputTranslator* inputTranslator = getInputTranslator(translator->getID());

				if(!inputTranslator)
					mInputTranslators.push_back(translator);
			}

			virtual void unregisterInputTranslator( const IT_INPUT_TRANSLATOR_ID* translatorID)
			{

			}

			virtual void unregisterInputTranslator( IInputTranslator* translator)
			{

			}

			virtual void registerInputTranslatorFactory( IInputTranslatorFactory* factory)
			{
				factory->grab();
				mInputTranslatorsFactories.push_back(factory);
			}

			//context
			virtual bool keyPressed(EKEY_CODE keycode)         {   return (mKeyState[keycode] == EKS_PRESSED);                        };
			virtual bool keyDown(EKEY_CODE keycode)         {   return (mKeyState[keycode] == EKS_DOWN || mKeyState[keycode] == EKS_PRESSED); };
			virtual bool keyUp(EKEY_CODE keycode)            {   return (mKeyState[keycode] == EKS_UP || mKeyState[keycode] == EKS_RELEASED);   };
			virtual bool keyReleased(EKEY_CODE keycode)      {   return (mKeyState[keycode] == EKS_RELEASED);                        };

			// keyboard events
			virtual bool OnKeyInputEvent(const SEvent& e)   
			{
				//update input state of keyboard
				//mContextInput.update(e);

			   //command for keyboard event registred by InputTranslators can executed here
				for(u32 i = 0; i < mInputTranslators.size(); ++i)
					return mInputTranslators[i]->translate(this);
			   return false;                                          
			}

			// guievents
			//virtual bool OnButtonClicked(const SEvent& e)         {   return false;   }
			//virtual bool OnScrollBarChanged(const SEvent& e)      {   return false;   }
			//virtual bool OnCheckBoxChanged(const SEvent& e)         {   return false;   }
			//virtual bool OnListBoxChanged(const SEvent& e)         {   return false;   }
			//virtual bool OnListBoxSelectedAgain(const SEvent& e)   {   return false;   }
			//virtual bool OnFileSelected(const SEvent& e)         {   return false;   }
			//virtual bool OnMessageBoxYes(const SEvent& e)         {   return false;   }
			//virtual bool OnMessageBoxNo(const SEvent& e)         {   return false;   }
			//virtual bool OnMessageBoxOk(const SEvent& e)         {   return false;   }
			//virtual bool OnMessageBoxCancel(const SEvent& e)      {   return false;   }
			//virtual bool OnEditBoxEnter(const SEvent& e)         {   return false;   }
			//virtual bool OnTabChanged(const SEvent& e)            {   return false;   }
			//virtual bool OnComboBoxChanged(const SEvent& e)         {   return false;   }
			//virtual bool OnSpinBoxChanged(const SEvent& e)         {   return false;   }

			// mouse events
			//virtual bool OnLMousePressedDown(const SEvent& e)      {   return false;   }
			//virtual bool OnRMousePressedDown(const SEvent& e)      {   return false;   }
			//virtual bool OnMMousePressedDown(const SEvent& e)      {   return false;   }
			//virtual bool OnLMouseLeftUp(const SEvent& e)         {   return false;   }
			//virtual bool OnRMouseLeftUp(const SEvent& e)         {   return false;   }
			//virtual bool OnMMouseLeftUp(const SEvent& e)         {   return false;   }
			//virtual bool OnMouseMoved(const SEvent& e)            {   return false;   }
			//virtual bool OnMouseWheel(const SEvent& e)            {   return false;   }

			// user events
			virtual bool OnUserEvent(const SEvent& e)            {   return false;   }

			virtual bool OnEvent(const SEvent& e)
			{
				switch (e.EventType)
				{
				case EET_KEY_INPUT_EVENT :
					{
						if (e.KeyInput.PressedDown == true)
					   if (e.KeyInput.PressedDown)
					   {
						  if (mKeyState[e.KeyInput.Key] != EKS_DOWN)
							 mKeyState[e.KeyInput.Key] = EKS_PRESSED;
						  else mKeyState[e.KeyInput.Key] = EKS_DOWN;
					   }
					   else
					   if (mKeyState[e.KeyInput.Key] != EKS_UP)   
						  mKeyState[e.KeyInput.Key] = EKS_RELEASED;
					    
					   //if (e.KeyInput.PressedDown == true) return OnKeyInputEvent(e);
					   if (e.KeyInput.PressedDown) return OnKeyInputEvent(e);
					}    
					break;

				case EET_GUI_EVENT :
					//{
					//   switch (e.GUIEvent.EventType)
					//   {
					//	  case EGET_BUTTON_CLICKED         : return OnButtonClicked(e);
					//	  case EGET_SCROLL_BAR_CHANGED      : return OnScrollBarChanged(e);
					//	  case EGET_CHECKBOX_CHANGED         : return OnCheckBoxChanged(e);
					//	  case EGET_LISTBOX_CHANGED         : return OnListBoxChanged(e);
					//	  case EGET_LISTBOX_SELECTED_AGAIN   : return OnListBoxSelectedAgain(e);
					//	  case EGET_FILE_SELECTED            : return OnFileSelected(e);
					//	  case EGET_MESSAGEBOX_YES         : return OnMessageBoxYes(e);
					//	  case EGET_MESSAGEBOX_NO            : return OnMessageBoxNo(e);
					//	  case EGET_MESSAGEBOX_OK            : return OnMessageBoxOk(e);
					//	  case EGET_MESSAGEBOX_CANCEL         : return OnMessageBoxCancel(e);
					//	  case EGET_EDITBOX_ENTER            : return OnEditBoxEnter(e);
					//	  case EGET_TAB_CHANGED            : return OnTabChanged(e);
					//	  case EGET_COMBO_BOX_CHANGED         : return OnComboBoxChanged(e);
					//	  case EGET_SPINBOX_CHANGED         : return OnSpinBoxChanged(e);
					//	  default : return false;
					//   }
					//} 
					break;

				case EET_MOUSE_INPUT_EVENT :
					//{
					//   mMouse.X = e.MouseInput.X;
					//   mMouse.Y = e.MouseInput.Y;

					//   switch (e.MouseInput.Event)
					//   {
					//	  case EMIE_LMOUSE_PRESSED_DOWN   :   mMouse.LButtonDown = true; return OnLMousePressedDown(e);
					//	  case EMIE_RMOUSE_PRESSED_DOWN   :   mMouse.RButtonDown = true; return OnRMousePressedDown(e);
					//	  case EMIE_MMOUSE_PRESSED_DOWN   :   mMouse.MButtonDown = true; return OnMMousePressedDown(e);
					//	  case EMIE_LMOUSE_LEFT_UP      :   mMouse.LButtonDown = false; return OnLMouseLeftUp(e);
					//	  case EMIE_RMOUSE_LEFT_UP      :   mMouse.RButtonDown = false; return OnRMouseLeftUp(e);
					//	  case EMIE_MMOUSE_LEFT_UP      :   mMouse.MButtonDown = false; return OnMMouseLeftUp(e);
					//	  case EMIE_MOUSE_MOVED         :   return OnMouseMoved(e);
					//	  case EMIE_MOUSE_WHEEL         :   
					//		 {
					//			mMouse.WheelDelta = mMouse.Wheel - e.MouseInput.Wheel;
					//			mMouse.Wheel += e.MouseInput.Wheel;
					//			return OnMouseWheel(e);
					//		 }
					//	  default : return false;
					//   }
					//} 
					break;

				case EET_USER_EVENT :
					{
					   return OnUserEvent(e);
					   default : return false;
					} 
					break;
				}

				return false;
			}
        }; 
    }
}

#endif