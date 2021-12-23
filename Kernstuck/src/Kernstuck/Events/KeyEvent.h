#ifndef KEY_EVENT_h
#define  KEY_EVENT_h

#include "Event.h"

#include <sstream>

namespace Kernstuck
{
	class KS_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int KeyCode)
			: m_KeyCode(KeyCode)
		{
		}
		int m_KeyCode;

	};

	class KS_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int KeyCode, int RepeatCount)
			: KeyEven(KeyCode), m_RepeatCount(RepeatCount)
		{
		}
		inline int GetReatCount() const { return m_RepeatCount; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}




		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;

	};

	class KS_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
#endif // !KEY_EVENT_H
