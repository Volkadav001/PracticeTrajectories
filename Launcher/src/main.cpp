#include <Render/Window.h>
#include <Render/Renderer.h>
/*============================================================================*/
int main()
{
  Window window("Test", 800, 600);

  std::vector<Point> points =
  {
    { -1.0f, -1.0f },
    { -0.8f,  0.3f },
    {  0.0f,  1.0f },
    {  0.8f,  0.3f },
    {  1.0f, -1.0f }
  };

  while(!window.Closed())
  {
    window.Clear();

    Renderer::Draw(points);

    window.Update();
  }

  return 0;
}
/*============================================================================*/