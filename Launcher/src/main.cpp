#include <Render/Window.h>
#include <Trajectories/Trajectories.h>
#include <Render/Renderer.h>

/*============================================================================*/
int main()
{
  std::cout << "Hello world!\n";

  setlocale(LC_ALL, "ru");

  vector<Point> points =
  {
	  {  0,  0 },
	  {  5,  5 },
	  {  9,  2 },
	  { 12,  8 }
  };

  vector<Point> result;



  Route One;

  result = One.Rounding(points);

  /*One.Trajectory(points);*/

	/*Point A(0, 0);
  Point B(5, 5);
  Point C(12, 6);
  A.Print();
  B.Print();
  C.Print();*/

  //Vector AB = CreatVector(points[0], points[1]);
  //Vector BA = CreatVector(points[1], points[0]);
  //AB.Print();
  //BA.Print();
  //double lengthAB = AB.Length(); // можно не писать, но возможно нужны будут далее
  //cout << lengthAB;              //
  //Vector ABnorm = AB.Normalized();
  //Vector BAnorm = BA.Normalized();

  //Vector BC = CreatVector(points[1], points[2]);
  //BC.Print();
  //double lengthBC = BC.Length();
  //cout << lengthBC;
  //Vector BCnorm = BC.Normalized();

  //double angleFi_rad = Scalar(BAnorm, BCnorm);
  //double angleFi_grad = ToGrad(angleFi_rad);

  std::cout << "Hello World!\n";
  system("pause");

  return 0;
}
/*============================================================================*/