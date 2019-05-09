#ifndef RENDERER_H
#define RENDERER_H
/*============================================================================*/
#include <vector>
/*============================================================================*/
struct Point
{
  float x, y;
};
/*============================================================================*/
class Renderer
{
public:
  static void Draw(const std::vector<Point>& points);
};
/*============================================================================*/
#endif // RENDERER_H