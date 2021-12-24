#ifndef EVENT_H
#define EVENT_H

#include "khpc.h"

#include "Kernstuck/Core.h"



namespace Kernstuck
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	enum  EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type)  static EventType        getStaticType()					 { return EventType::##type; }\
								virtual  EventType      getEventType()	 const override  { return getStaticType(); }\
								virtual  const char*    getName()		 const override	 { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual inline int getCategoryFlags() const override { return category; }



	class KS_API Event
	{
		friend class EventDispatcher;
	public:
		[[nodiscard]] virtual EventType getEventType()  const = 0;
		[[nodiscard]] virtual const char* getName()     const = 0;
		[[nodiscard]] virtual int getCategoryFlags()    const = 0;
		[[nodiscard]] virtual std::string toString() const { return getName(); }

		[[nodiscard]] inline auto isInCategory(const EventCategory& category) const -> bool
		{
			return getCategoryFlags() & category;
		}
		
	protected:
		~Event() = default;
		bool m_Handled = false;

	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event):
			m_Event(event)
		{
		}

		template<typename T>
		auto dispatch(EventFn<T> func)->bool
		{
			if (m_Event.getEventType() == T::getStaticType())
			{
				m_Event.m_Handled = func(*(T*)m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
		
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}

}







#endif