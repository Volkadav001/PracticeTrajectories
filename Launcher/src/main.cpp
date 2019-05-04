#include <iostream>
#include <Trajectories/Trajectories.h>

/*============================================================================*/
int main()
{
  std::cout << "Hello world!\n";

  setlocale(LC_ALL, "ru");

  vector<Point> points =
  {
	  {  0,  0 },
	  {  5,  5 },
	  { 12,  6 },
	  {  8, 12 }
  };

  /*Point A(0, 0);
  Point B(5, 5);
  Point C(12, 6);
  A.Print();
  B.Print();
  C.Print();*/

  Route One;

  One.Trajectory(points);



  std::cout << "Hello World!\n";
  system("pause");

  return 0;
}
/*============================================================================*/