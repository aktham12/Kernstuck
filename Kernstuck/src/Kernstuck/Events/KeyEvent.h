#ifndef  KEY_EVENT_H
#define  KEY_EVENT_H

#include "Event.h"

#include <sstream>

namespace Kernstuck
{
	class KS_API KeyEvent : public Event
	{
	public:
		[[nodiscard]] inline int getKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(const int KeyCode)
			: m_KeyCode(KeyCode)
		{
		}
		int m_KeyCode;

	};

	class KS_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int KeyCode,const int RepeatCount)
			: KeyEvent(KeyCode), m_RepeatCount(RepeatCount)
		{
		}
		[[nodiscard]]  inline int getRepeatCount() const { return m_RepeatCount; }
		[[nodiscard]]  std::string toString() const override
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
		KeyReleasedEvent( const int keycode)
			: KeyEvent(keycode) {}

		[[nodiscard]] std::string toString() const override
			{
				std::stringstream ss;
				ss << "KeyReleasedEvent: " << m_KeyCode;
				return ss.str();
			}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
#endif // !KEY_EVENT_H