#ifndef TRAJECTORIES
#define TRAJECTORIES

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Point
{

public:
	double x, y;

	Point(double valueX, double valueY) :
		x(valueX),
		y(valueY)  //Список инициализации
	{  }

	/*void SetXY(double valueX, double valueY)
	{
		x = valueX;
		y = valueY;
	}
*/
	void Print()
	{
		cout << "Начальная точка: (" << x << "; " << y << ")" << endl;
	}

};

class Route
{
private:
	double speed = 0.5;
	double Vx, Vy, t0, tmpx, tmpy;
public:
	double LenghtWay;

	//double CalculateLength(Point firstpoint, Point secondpoint)
	//{
	//	
	//	LenghtWay = sqrt(pow((secondpoint.x - firstpoint.x), 2) + pow((secondpoint.y - firstpoint.y), 2));
	//	Vx = (secondpoint.x - firstpoint.x) / LenghtWay * speed;
	//	Vy = (secondpoint.y - firstpoint.y) / LenghtWay * speed;
	//	t0 = LenghtWay / speed;

	//	for (double t = 0.0; t < t0; t+=0.05)
	//	{
	//		tmpx = firstpoint.x + Vx * t;
	//		tmpy = firstpoint.y + Vy * t;
	//		cout << tmpx << ", " << tmpy << endl;
	//	}
	//	
	//	//sin(0.0)

	//	//LenghtWay = sqrt(tmp);
	//	return LenghtWay;
	//}

	void Trajectory(const vector<Point> &points)
	{
		double L;
		for (int i = 1; i < points.size(); i++)
		{
			int j = i - 1;
			L = sqrt(pow((points[i].x - points[j].x), 2) + pow((points[i].y - points[j].y), 2));

			Vx = (points[i].x - points[j].x) / L * speed;
			Vy = (points[i].y - points[j].y) / L * speed;
			t0 = L / speed;

			for (double t = 0.0; t < t0; t += 0.05)
			{
				tmpx = points[j].x + Vx * t;
				tmpy = points[j].y + Vy * t;
				cout << tmpx << ", " << tmpy << endl;
			}

			cout << endl;
		}

	}
};

#endif
