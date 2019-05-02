#include "Render/Window.h"
/*============================================================================*/
#include <iostream>
/*============================================================================*/
Window::Window(const std::string & title, int width, int height):
  _title(title),
  _width(width),
  _height(height)
{
  _initWindow();
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

  HWND wnd = CreateWindow("Window", _title.c_str(),
                          WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                          GetSystemMetrics(SM_CXSCREEN) / 2 - _width / 2,
                          GetSystemMetrics(SM_CYSCREEN) / 2 - _height / 2,
                          rect.right - rect.left,
                          rect.bottom - rect.top,
                          NULL, NULL, instance, NULL);

  if (!wnd)
    std::cout << "Failed to create window\n";
}
/*============================================================================*/
LRESULT Window::_wndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch (msg)
  {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
    default:
      return DefWindowProc(wnd, msg, wParam, lParam);
  }
}
/*============================================================================*/
void Window::Run()
{
  MSG msg = {};

  while (WM_QUIT != msg.message)
  {
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    else { /*Some render code*/ }
  }
}
/*============================================================================*/