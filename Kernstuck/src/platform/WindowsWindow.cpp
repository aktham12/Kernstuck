#include "khpc.h"

#include "WindowsWindow.h"

#include "Kernstuck/Logger.h"


namespace Kernstuck
{
	static bool s_GLFWInitialized = false;
	Window* Window::createWindow(const WindowProps& props) 
	{
		return new WindowsWindow(props);
	}
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		initWindow(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutDownWindow();
	}


	auto WindowsWindow::initWindow(const WindowProps& props) -> void
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		KS_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if(!s_GLFWInitialized)
		{
			auto success = glfwInit();

			KS_CORE_ASSERT(success, "Could not initialize GLFW!");
			s_GLFWInitialized = true;

		}

		m_Window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height),
									props.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);

	}

	auto WindowsWindow::shutDownWindow() const -> void
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	auto WindowsWindow::setVSync(const bool enabled) -> void
	{
		enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);
		m_Data.VSync = enabled;
	}

	auto WindowsWindow::isVSync() const -> bool
	{
		return m_Data.VSync;
	}

}
