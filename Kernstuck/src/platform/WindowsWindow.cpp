#include "khpc.h"

#include "WindowsWindow.h"

#include "Kernstuck/Logger.h"


namespace Kernstuck
{
	static bool s_GLFWInitialized = false;

	static void glfwErrorCallback(int error, const char* description)
	{
		KS_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}
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

		if (!s_GLFWInitialized)
		{
			auto success = glfwInit();
			glfwSetErrorCallback(glfwErrorCallback);
			KS_CORE_ASSERT(success, "Could not initialize GLFW!");
			s_GLFWInitialized = true;

		}

		m_Window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height),
			props.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);

		setWindowResizeEvent();
		setWindowCloseEvent();
		setKeyboardEvent();
		setMouseEvent();
		setMouseScrollEvent();
		setCursorPosEvent();
	}

	auto WindowsWindow::shutDownWindow() const -> void
	{
		glfwDestroyWindow(m_Window);
	}

	auto WindowsWindow::setWindowResizeEvent() const -> void
	{
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				KS_CORE_INFO("Created!");
				WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				data.Width = width;
				data.Height = height;
				WindowResizeEvent event(width, height);

				data.eventCallback(event);
			});
	}

	auto WindowsWindow::setWindowCloseEvent() const -> void
	{
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				KS_CORE_INFO("Created!");

				const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				WindowCloseEvent event;
				data.eventCallback(event);
			});
	}

	auto WindowsWindow::setKeyboardEvent() const -> void
	{
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scanCode, int action, int mods)
			{
				KS_CORE_INFO("Created!");

				const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
				default: KS_CORE_ERROR("No Keyboard Event");
				}

			});
	}

	auto WindowsWindow::setMouseEvent() const -> void
	{
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				KS_CORE_INFO("Created!");

				const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.eventCallback(event);
					break;
				}
				default: KS_CORE_ERROR("NoMouseEvent");
				}
			});
	}

	auto WindowsWindow::setMouseScrollEvent() const -> void
	{
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffSet, double yOffSet)
			{
				KS_CORE_INFO("Created!");

				const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				MouseScrolledEvent event(static_cast<float>(xOffSet), static_cast<float>(yOffSet));
				data.eventCallback(event);

			});
	}

	auto WindowsWindow::setCursorPosEvent() const -> void
	{

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				KS_CORE_INFO("Created!");

				const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
				data.eventCallback(event);

			});
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
