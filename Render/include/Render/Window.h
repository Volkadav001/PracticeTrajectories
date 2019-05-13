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
private:
  void _initWindow();
  void _initContext();
  void _onResize(int width, int height);
  static LRESULT CALLBACK _wndProc(HWND wnd, UINT msg,
                                   WPARAM wParam, LPARAM lParam);
public:
  Window(const std::string& title, int width, int height);
  ~Window();

  void Clear() const;
  void Update() const;

  bool Closed() const;
};
/*============================================================================*/
#endif // WINDOW_H