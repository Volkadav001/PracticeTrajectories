#ifndef RENDERER_H
#define RENDERER_H
/*============================================================================*/
#include <vector>
/*============================================================================*/
struct Vec2
{
  double x, y;
};
/*============================================================================*/
struct Color
{
  unsigned char r, g, b;
};
/*============================================================================*/
class Renderer
{
public:
  static void Draw(const std::vector<Vec2>& points, const Color& color);
};
/*============================================================================*/
#endif // RENDERER_H