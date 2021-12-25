#ifndef WINDOW_H
#define WINDOW_H

#include "khpc.h"

#include "Kernstuck/Core.h"

#include "Kernstuck/Events/Event.h"

namespace Kernstuck
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		explicit WindowProps(std::string title = "Kernstuck Engine",
		                     const unsigned int width = 1280,
		                     const unsigned int height = 720)
						: Title(std::move(title)),Width(width),Height(height)
		{
		}

	};

	class KS_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() { }

		virtual void onUpdate() = 0;
		[[nodiscard]] virtual auto getWidth() const  -> unsigned int = 0;
		[[nodiscard]] virtual auto getHeight() const -> unsigned int = 0;

		virtual auto setEventCallback(const EventCallbackFn& callback) -> void = 0;
		virtual auto setVSync(bool enabled) -> void = 0;
		[[nodiscard]] virtual auto isVSync() const -> bool = 0;


		static Window* createWindow(const WindowProps& props = WindowProps());


	};

}
#endif // WINDOW_H