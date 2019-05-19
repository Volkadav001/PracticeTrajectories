#include <Render/Window.h>
#include <Trajectories/Trajectories.h>
#include <Render/Renderer.h>
/*============================================================================*/
std::vector<Vec2> ConvertToRenderPoints(const std::vector<Point>& points)
{
  std::vector<Vec2> res;

  for (const Point& point : points)
    res.push_back({ point.x, point.y });

  return res;
}
/*============================================================================*/
int main()
{
  setlocale(LC_ALL, "ru");

  vector<Point> points =
  {
	  //{   0.0,   0.0 },
	  //{  50.0,  50.0 },
	  //{  90.0,  20.0 },
	  //{ 120.0,  80.0 }

    { 0.0, 0.0 },
    { 50.0,  50.0 },
    {  90.0,  20.0 },
    { 120.0,  80.0 },
  };

  Route One;

  vector<Point> result = One.Rounding(points);
  vector<Vec2> renderPoints2 = ConvertToRenderPoints(points);
  vector<Vec2> renderPoints = ConvertToRenderPoints(result);
  

  Window window("Trajectories", 600, 600);



  while (!window.Closed())
  {
    window.Clear();

	
	Renderer::Draw(renderPoints, { 255, 0, 0 });
	Renderer::Draw(renderPoints2, { 0, 255, 0 });

    window.Update();
  }

  /*One.Trajectory(points);

	Point A(0, 0);
  Point B(5, 5);
  Point C(12, 6);
  A.Print();
  B.Print();
  C.Print();

  Vector AB = CreatVector(points[0], points[1]);
  Vector BA = CreatVector(points[1], points[0]);
  AB.Print();
  BA.Print();
  double lengthAB = AB.Length(); // можно не писать, но возможно нужны будут далее
  cout << lengthAB;              //
  Vector ABnorm = AB.Normalized();
  Vector BAnorm = BA.Normalized();

  Vector BC = CreatVector(points[1], points[2]);
  BC.Print();
  double lengthBC = BC.Length();
  cout << lengthBC;
  Vector BCnorm = BC.Normalized();

  double angleFi_rad = Scalar(BAnorm, BCnorm);
  double angleFi_grad = ToGrad(angleFi_rad);*/

  return 0;
}
/*============================================================================*/