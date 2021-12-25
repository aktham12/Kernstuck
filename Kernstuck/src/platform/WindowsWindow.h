#pragma once
#include "khpc.h"

#include "Kernstuck/Window.h"

#include <GLFW/glfw3.h>
namespace Kernstuck
{
	class KS_API WindowsWindow : public  Window
	{
	public:
		explicit WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		[[nodiscard]] inline auto getWidth() const -> unsigned int override { return m_Data.Width; }
		[[nodiscard]] inline auto getHeight() const -> unsigned int override { return m_Data.Height; }

		inline auto setEventCallback(const EventCallbackFn& callback) ->void override { m_Data.eventCallback = callback; }
		auto setVSync(const bool enabled)->void  override;
		[[nodiscard]] auto isVSync() const -> bool override;

	private:
		virtual auto initWindow(const WindowProps& props) ->void;
		virtual auto shutDownWindow() const ->void;



	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn eventCallback;
		};
		WindowData m_Data;
	};
}

