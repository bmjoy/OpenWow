#pragma once

// FORWARD BEGIN
struct GLFWmonitor;
struct GLFWwindow;
// FORWARD END

class OpenGLAdapter_GLFW : public IOpenGLAdapter
{
public:
	OpenGLAdapter_GLFW();
	~OpenGLAdapter_GLFW();

	// IOpenGLAdapter
	bool SwapWindowBuffers() override;
	double GetTime() override;
	CInput* GetInput() override;

	void MakeMainContext() override;
	void MakeThreadContext() override;

	void SetWindowSize(int32 _width, int32 _height) override;
	void SetWindowTitle(cstring _title) override;

	void CreateCursor();
	void ShowCursor() override;
	void HideCursor() override;

	void setMousePosition(cvec2 _mousePosition) override;

	int isExtensionSupported(const char* _extension) override;
	void* getProcAddress(const char* _procname) override;

private:
	GLFWmonitor* primaryMonitor;
	GLFWwindow* m_Window;
	GLFWwindow* m_ThreadWindow;
	CInput* m_Input;
};
