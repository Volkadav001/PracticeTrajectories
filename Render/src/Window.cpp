#include "Render/Window.h"
/*============================================================================*/
#include <gl/GL.h>
#include <iostream>
/*============================================================================*/
Window::Window(const std::string& title, int width, int height):
  _title(title),
  _width(width),
  _height(height)
{
  _initWindow();
  _initContext();
  _onResize(width, height);
}
/*============================================================================*/
Window::~Window()
{
  wglMakeCurrent(NULL, NULL);
  wglDeleteContext(_renderContext);
  ReleaseDC(_wnd, _deviceContext);
}
/*============================================================================*/
void Window::_initWindow()
{
  HINSTANCE instance = GetModuleHandle(NULL);

  WNDCLASSEX windowClassInfo =
  {
    sizeof(WNDCLASSEX),
    CS_HREDRAW | CS_VREDRAW,
    (WNDPROC)Window::_wndProc,
    0, 0,
    instance,
    NULL,
    LoadCursor(NULL, IDC_ARROW),
    NULL,
    NULL,
    "Window",
    NULL
  };

  if (!RegisterClassEx(&windowClassInfo))
    std::cout << "Failed to register WNDCLASSEX\n";

  RECT rect = { 0, 0, _width, _height };
  DWORD wndStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
  AdjustWindowRect(&rect, wndStyle, FALSE);

  _wnd = CreateWindow("Window", _title.c_str(),
                      WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU |
                      WS_MINIMIZEBOX | WS_VISIBLE,
                      GetSystemMetrics(SM_CXSCREEN) / 2 - _width / 2,
                      GetSystemMetrics(SM_CYSCREEN) / 2 - _height / 2,
                      rect.right - rect.left,
                      rect.bottom - rect.top,
                      NULL, NULL, instance, NULL);

  if (!_wnd)
    std::cout << "Failed to create window\n";
}
/*============================================================================*/
void Window::_initContext()
{
  _deviceContext = GetDC(_wnd);

  PIXELFORMATDESCRIPTOR pfd =
  {
    sizeof(PIXELFORMATDESCRIPTOR),
    1,
    PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
    PFD_TYPE_RGBA,
    34,
    0, 0, 0, 0, 0, 0,
    8, 0,
    0,
    0, 0, 0, 0,
    24,
    8,
    0,
    PFD_MAIN_PLANE,
    0,
    0, 0, 0
  };

  int format = ChoosePixelFormat(_deviceContext, &pfd);

  if (!SetPixelFormat(_deviceContext, format, &pfd))
    std::cout << "Failed to set pixel format\n";

  _renderContext = wglCreateContext(_deviceContext);

  if (!wglMakeCurrent(_deviceContext, _renderContext))
    std::cout << "Failed to create and active render context\n";
}
/*============================================================================*/
void Window::_onResize(int width, int height)
{
  if (0 == height)
    height = 1;

  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(
    -(float)width / 2, (float)width / 2,
    -(float)height / 2, (float)height / 2,
    1.0f, -1.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
/*============================================================================*/
LRESULT Window::_wndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  Window* this_ptr = (Window*)GetWindowLongPtr(wnd, GWLP_USERDATA);

  switch (msg)
  {
    case WM_SIZE:
      this_ptr->_onResize(LOWORD(lParam), HIWORD(lParam));
      return 0;
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
    default:
      return DefWindowProc(wnd, msg, wParam, lParam);
  }
}
/*============================================================================*/
void Window::Clear() const
{
  glClear(GL_COLOR_BUFFER_BIT);
}
/*============================================================================*/
void Window::Update() const
{
  SwapBuffers(_deviceContext);
}
/*============================================================================*/
bool Window::Closed() const
{
  MSG msg = {  };

  while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);

    if (WM_QUIT == msg.message)
      return true;
    else
      return false;
  }

  return false;
}
/*============================================================================*/