#include "Render/Renderer.h"
/*============================================================================*/
#include <Windows.h>
#include <gl/GL.h>
/*============================================================================*/
void Renderer::Draw(const std::vector<Point>& points)
{
  glColor3f(0.0f, 1.0f, 0.0f);
  glBegin(GL_LINES);
  {
    for (std::size_t i = 0; i < points.size() - 1; ++i)
    {
      glVertex2f(points[  i  ].x, points[  i  ].y);
      glVertex2f(points[i + 1].x, points[i + 1].y);
    }
  }
  glEnd();
}
/*============================================================================*/