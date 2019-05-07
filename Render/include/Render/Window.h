#ifndef WINDOW_H
#define WINDOW_H
/*============================================================================*/
#include <string>
#include <Windows.h>
/*============================================================================*/
class Window
{
private:
  std::string _title;
  int _width;
  int _height;

  HWND _wnd;
  HDC _deviceContext;
  HGLRC _renderContext;
public:
  Window(const std::string& title, int width, int height);
  ~Window();

  void Run();
private:
  void _initWindow();
  void _initContext();
  static LRESULT CALLBACK _wndProc(HWND wnd, UINT msg,
                                   WPARAM wParam, LPARAM lParam);
};
/*============================================================================*/
#endif // WINDOW_H