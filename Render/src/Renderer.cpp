#include "Render/Renderer.h"
/*============================================================================*/
#include <Windows.h>
#include <gl/GL.h>
/*============================================================================*/
void Renderer::Draw(const std::vector<Vec2>& points, const Color& color)
{
  glColor3ub(color.r, color.g, color.b);
  glBegin(GL_LINES);
  {
    for (std::size_t i = 0; i < points.size() - 1; ++i)
    {
      glVertex2d(points[  i  ].x, points[  i  ].y);
      glVertex2d(points[i + 1].x, points[i + 1].y);
    }
  }
  glEnd();
}
/*============================================================================*/