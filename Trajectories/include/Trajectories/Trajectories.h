#ifndef TRAJECTORIES
#define TRAJECTORIES

#include <iostream>
#include <cmath>
#include <vector>

#define PI 3.141592654
#define R 1
#define ANGELPOV 90
#define DEL 0.5

using namespace std;


class Point
{

public:
	double x, y;

	Point(double valueX, double valueY) :
		x(valueX),
		y(valueY)  //������ �������������
	{  }

	void Print()
	{
		cout << "��������� �����: (" << x << "; " << y << ")" << endl;
	}

};

class Vector
{

public:
	double x, y;

	Vector(double valueX, double valueY) :
		x(valueX),
		y(valueY)  //������ ������������� //�������� �������� ������� ��� ���������� ������
	{  }

	Vector () 
	{ }

	void Print()
	{
		cout << "������: (" << x << "; " << y << ")" << endl;
	}

	double Length()
	{
		return  sqrt(pow(x, 2) + pow(y, 2));
	}


	Vector Normalized () 
	{
		double length = Length();
		double tmpx = (x / length);
		double tmpy = (y / length);

		return Vector (tmpx, tmpy);
	}

};

Vector CreatVector (Point value1, Point value2) //�������� �������
{
	double x = value2.x - value1.x;
	double y = value2.y - value1.y;

	return Vector(x, y);

}

double Scalar (Vector norm1, Vector norm2) 
{
	return acos(norm1.x * norm2.x + norm1.y * norm2.y);

}

double ToGrad (double rad) 
{
	return (rad * 180) / PI;
}

double ToRad (double grad) 
{
	return (grad * PI) / 180;
}

double TochkaNaPrimoy(double v1, double v2, double lambda1)
{
	return (v1 + lambda1 * v2) / (lambda1 + 1);
}

Point Centre(double xA, double xB, double xC, double yA, double yB, double yC, double xAsh, double yAsh, double xCsh, double yCsh)
{
	double xO, yO;

	xO = (((xB - xC) / (yB - yC)) * xCsh + yCsh - ((xB - xA) / (yB - yA)) * xAsh - yAsh) / (((xB - xC) / (yB - yC)) - ((xB - xA) / (yB - yA)));

	yO = -((xB - xC) / (yB - yC)) * xO + ((xB - xC) / (yB - yC)) * xCsh + yCsh;

	Point CentreO(xO, yO);

	return CentreO;
}

class Route
{
private:
	double speed = 0.5;
	double Vx, Vy, t0, tmpx, tmpy;
public:
	double LenghtWay;

	

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

	
	vector<Point> Rounding (const vector<Point> &points)
	{
		vector<Point> rounding;
		vector<Point> result;

		result.push_back(points[0]);

		int SizeOfPoints = points.size();
		int i = 0;
		while (i + 3 <= SizeOfPoints)
		{
			
			double xA, xB, xC, yA, yB, yC, xO, yO;
			xA = points[i].x;
			yA = points[i].y;
			xB = points[i + 1].x;
			yB = points[i + 1].y;
			xC = points[i + 2].x;
			yC = points[i + 2].y;

			Vector AB = CreatVector(points[i], points[i + 1]);
			Vector BA = CreatVector(points[i + 1], points[i]);
			Vector ABnorm = AB.Normalized();
			Vector BAnorm = BA.Normalized();

			Vector BC = CreatVector(points[i + 1], points[i + 2]);
			Vector CB = CreatVector(points[i + 2], points[i + 1]);
			Vector BCnorm = BC.Normalized();
			Vector CBnorm = CB.Normalized();

			double angleFi_rad = Scalar(BAnorm, BCnorm);
			double angleFi_grad = ToGrad(angleFi_rad); //���� ����� ������� �� � ��

			if(180 - angleFi_grad > ANGELPOV) 
			{
				cout << "�� ����� ����: " << angleFi_grad << " ������ ��������� �� ������!" << endl;
				//����� �� �����....
			}

			double TangensPolFi = tan(angleFi_rad / 2);
			double l1 = R / TangensPolFi; //lengthAshB


			/// ���� ������ ���� ����������
			if (i + 3 < SizeOfPoints)
			{
				Vector CD = CreatVector(points[i + 2], points[i + 3]);
				Vector DC = CreatVector(points[i + 3], points[i + 2]);
				Vector CDnorm = CD.Normalized();

				double angleFi_rad2 = Scalar(BCnorm, CDnorm);
				double angleFi_grad2 = ToGrad(angleFi_rad2); // ���� ����� ������� �� � �D

				if (180 - angleFi_grad2 > ANGELPOV)
				{
					cout << "�� ����� ����: " << angleFi_grad2 << " ������ ��������� �� ������!" << endl;
					//����� �� �����....
				}

				double TangensPolFi2 = tan(angleFi_rad2 / 2);
				double l2 = R / TangensPolFi2; //lengthBshC

				double Lstoron = l1 + l2 + DEL;
				double lengthBC = BC.Length();

				if (lengthBC < Lstoron)
				{
					cout << "����� ��������� ���������� �������� �� �����!" <<
						" ������ �� ������ ������� �� �� � ����� �� ����� ����������!" << endl;
					//����� �� �����.....
				}
			}
			/// ���� ������ ���� ����������


			double AAsh = AB.Length() - l1; // - lengthAshB
			double CCsh = BC.Length() - l1; // - lengthBCsh

			double lambda1 = AAsh / l1;
			double xAsh = TochkaNaPrimoy(points[i].x, points[i + 1].x, lambda1);
			double yAsh = TochkaNaPrimoy(points[i].y, points[i + 1].y, lambda1);
			Point Ash(xAsh, yAsh);
			result.push_back(Ash);

			double lambda2 = l1 / CCsh;
			double xCsh = TochkaNaPrimoy(points[i + 1].x, points[i + 2].x, lambda2);
			double yCsh = TochkaNaPrimoy(points[i + 1].y, points[i + 2].y, lambda2);
			Point Csh(xCsh, yCsh);

			Point O = Centre(xA, xB, xC, yA, yB, yC, xAsh, yAsh, xCsh, yCsh); //���� ����� ����������


			xO = O.x;
			yO = O.y;
			double rx, ry, x1, y1, angleAlfa_grad, angleAlfa_rad, angleAlfa_Ch_grad, angleAlfa_Angle_grad, angleAlfa_Angel_rad;

			rx = xCsh - xO;
			ry = yCsh - yO;
			angleAlfa_grad = 180 - angleFi_grad; //���� ����� ����� ��������� = 180 - ���� ����� ����� ������� ����������
			angleAlfa_Ch_grad = angleAlfa_grad / 6; // ����� ���� �� ����� ������
			angleAlfa_Angle_grad = angleAlfa_Ch_grad; // ����� ���� �����, ����� ������ � �� �������� ���� �����

			for (int i = 0; i < 5; i++) // ����� �� �������� �� 0 �� 5 ��� ��� 5���(6��) ����� ��� ����� �ch
			{
				angleAlfa_Angel_rad = ToRad(angleAlfa_Angle_grad);

				x1 = xO + rx * cos(angleAlfa_Angel_rad) - ry * sin(angleAlfa_Angel_rad);
				y1 = yO + rx * sin(angleAlfa_Angel_rad) + ry * cos(angleAlfa_Angel_rad);
				// �������� ���������� ����� �� �' ������� � angleAlfa_Angle_grad ��������
				
				Point Tmp(x1, y1);
				rounding.push_back(Tmp);     // ��������� ����� ����������!!!!!!

				angleAlfa_Angle_grad = angleAlfa_Angle_grad + angleAlfa_Ch_grad;
			}

			//��������� ����� ���������� �������
			int tr = rounding.size(); //������ ������� ����� ���� �� �������� � ��������
			for (int i = 0; i < rounding.size(); i++)
			{
				//Point tmp = 
				result.push_back(rounding[tr - 1]); //��������� ����� � ����� ����������
				tr--;
			}
			result.push_back(Csh);

			i++;
		}

		result.push_back(points[SizeOfPoints - 1]);
		
		return result;
	}

};

#endif
