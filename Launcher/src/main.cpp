#include <Render/Window.h>
#include <Render/Renderer.h>
/*============================================================================*/
int main()
{
  Window window("Test", 600, 600);

  std::vector<Point> points =
  {
    { -50.0f, -50.0f },
    {  50.0f,  50.0f }
  };

  while(!window.Closed())
  {
    window.Clear();

    Renderer::Draw(points, { 255, 0, 0 });

    window.Update();
  }

  return 0;
}
/*============================================================================*/