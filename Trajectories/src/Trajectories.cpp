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

/*void SetXY(double valueX, double valueY)
	{
		x = valueX;
		y = valueY;
	}
*/

//������ ������� ���������� �' C'
//Vector tA, tB;
//
//if ((points[i].x < points[i + 1].x) && (points[i].y < points[i + 1].y)) //���� ����� �� � �� ������
//{
//	tA = ABnorm; // t1t2
//}
//else if ((points[i].x < points[i + 1].x) && (points[i].y > points[i + 1].y)) //���� ����� AB � �� �����
//{
//	tA = BAnorm; // t2t1
//}
//else {
//	cout << "�� ��������������� �������..." << endl;
//	//����� �� �����.....
//}
//
//if ((points[i + 1].x < points[i + 2].x) && (points[i + 1].y < points[i + 2].y)) //���� ����� �� � �� ������
//{
//	tB = BCnorm; //t1t2
//}
//else if ((points[i + 1].x < points[i + 2].x) && (points[i + 1].y > points[i + 2].y)) //���� ����� AB � �� �����
//{
//	tB = CBnorm; //t2t1
//}
//else {
//	cout << "�� ��������������� �������..." << endl;
//	//����� �� �����.....
//}
//
////������� ������ ��
//
//double CosinysA = Scalar(tA, Ox);
//double CosinysB = Scalar(tB, Ox);
