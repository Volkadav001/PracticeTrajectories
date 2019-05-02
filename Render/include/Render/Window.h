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
public:
  Window(const std::string& title, int width, int height);

  void Run();
private:
  void _initWindow();
  static LRESULT CALLBACK _wndProc(HWND wnd, UINT msg,
                                   WPARAM wParam, LPARAM lParam);
};
/*============================================================================*/
#endif // WINDOW_H