#include <Render/Window.h>
#include <gl/GL.h>
/*============================================================================*/
int main()
{
  Window window("Test", 800, 600);

  while(!window.Closed())
  {
    window.Clear();

    glBegin(GL_TRIANGLES);
    {
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-1.0f, -1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex2f( 0.0f,  1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex2f( 1.0f, -1.0f);
    }
    glEnd();

    window.Update();
  }

  return 0;
}
/*============================================================================*/