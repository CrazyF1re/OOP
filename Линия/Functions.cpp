#include "Functions.h";
#include <iostream>
#define PI 3.1415926535
	/*1*/Straight::Straight(float ax = 1, float by = 1, float C = 1)//1
	{
		a = ax;
		b = by;
		c = C;
	}
	/*2*/void Straight::Print()
	{
		if (a == 0)
		{
			if (c > 0)std::cout << b << "y+" << c << "=0" << std::endl;
			else if (c == 0)std::cout << b << "y=0" << std::endl;
			else std::cout << b << "y" << c << "=0" << std::endl;

		}
		else
		{
			if (b > 0)
			{
				if (c > 0)std::cout << a << "x+" << b << "y+" << c << "=0" << std::endl;
				else if (c == 0)std::cout << a << "x+" << b << "y=0" << std::endl;
				else std::cout << a << "x+" << b << "y" << c << "=0" << std::endl;
			}
			else if (b == 0)
			{
				if (c > 0)std::cout << a << "x+" << c << "=0" << std::endl;
				else if (c == 0)std::cout << a << "x" << "=0" << std::endl;
				else std::cout << a << "x" << c << "=0" << std::endl;
			}
			else
			{
				if (c > 0)std::cout << a << "x" << b << "y+" << c << "=0" << std::endl;
				else if (c == 0)std::cout << a << "x" << b << "y" << "=0" << std::endl;
				else std::cout << a << "x" << b << "y" << c << "=0" << std::endl;
			}
		}
	}

	/*2*/void Straight::Input()
	{
		int ax, by, C;
		std::cin >> ax >> by >> C;
		a = ax;
		b = by;
		c = C;
	}
	/*3*/bool Straight::check_start_cords()
	{
		if (c) return 0;
		else return 1;
	}
	/*4*/void Straight::check_parallelism_axis()
	{
		if (a && !b) std::cout << "Паралельна оси Ox" << std::endl;
		else if (!a && b)std::cout << "Паралельна оси Oy" << std::endl;
		else std::cout << "Не параллельна ни одной из осей" << std::endl;
	}
	/*5*/void Straight::segments()
	{
		if (c == 0) std::cout << "Отрезков нет т.к. прямая проходит через начало координат" << std::endl;
		else if (a == 0)
		{
			std::cout << "По оси Ox отрезок равен 0 т.к. коэффициент при x равен 0 " << std::endl;
			std::cout << "По оси Oy: " << -c / b << std::endl;

		}
		else if (b == 0)
		{
			std::cout << "По оси Ox: " << -c / a << std::endl;
			std::cout << "По оси Oy отрезок равен 0 т.к. коэффициент при y равен 0: " << -c / b << std::endl;
		}
		else
		{
			std::cout << "По оси Ox: " << -c / a << std::endl;
			std::cout << "По оси Oy: " << -c / b << std::endl;
		}
	}
	/*6*/float Straight::coefficient()
	{
		if (b == 0)return 0;
		if (!a && b)
		{
			std::cout << "Паралельна оси Oy => коэффициент не существует" << std::endl;
			return 0;
		}
		else return -a / b;
	}
	/*7*/bool Straight::check_similarity(Straight line2)
	{
		if (a == line2.a && b == line2.b && c == line2.c)return 1;
		else return 0;
	}
	/*8*/bool Straight::check_parallelism_two_lines(Straight line2)
	{

		if (fabs(coefficient() - line2.coefficient()) < eps) return 1;
		else return 0;
	}
	/*9*/bool Straight::check_perpendicularity(Straight line2)
	{
		if (fabs((a * line2.a + b * line2.b)) < eps)return 1;
		else return 0;
	}
	/*10*/float Straight::distance() { return (c / sqrt(a * a + b * b)); }
	/*11*/bool Straight::check_point(Point p)
	{
		if (fabs((a * p.x + b * p.y + c)) < eps) return 1;
		else return 0;
	}
	/*12*/float Straight::distance_to_point(Point p)
	{
		float chislitel = fabs(a * p.x + b * p.y + c);
		float znamenatel = sqrt(a * a + b * b);
		return chislitel / znamenatel;
	}
	/*13*/bool Straight::check_cross_two_lines(Straight line2)
	{
		if (check_parallelism_two_lines(line2))return 0;
		else return 1;
	}
	/*14*/Point Straight::cross_point(Straight line2)
	{
		Point p{ 0,0 };
		if (check_parallelism_two_lines(line2))return p;
		else
		{
			p.x = ((-c * line2.b + b * line2.c) / (a * line2.b - b * line2.a));
			p.y = (-a * line2.c + c * line2.a) / (a * line2.b - b * line2.a);
			return p;
		}
	}
	/*15*/double Straight::injection_between_lines(Straight line2)
	{
		if (check_parallelism_two_lines(line2))return 0;
		double param = a * line2.a + b * line2.b;
		if (param < 0)param *= -1;
		param /= (sqrt(a * a + b * b) * sqrt(line2.a * line2.a + line2.b * line2.b));
		param = acos(param) * 180.0 / PI;
		return param;
	}
	/*16*/void Straight::which_line_is_closer(Straight line2)
	{
		if (distance() > line2.distance()) std::cout << "Линия line2 ближе" << std::endl;
		else std::cout << "Линия line1 ближе" << std::endl;
	}
	/*17*/float Straight::distance_between_paralel_lines(Straight line2)
	{
		float ans = fabs(distance() - line2.distance());
		return ans;
	}
	/*18*/bool Straight::is_line_between_others(Straight line1, Straight line2)
	{
		if (check_parallelism_two_lines(line1) && check_parallelism_two_lines(line2))
		{
			float k1, k2;
			if ((line1.c >= c && line2.c <= c) || (line1.c <= c && line2.c >= c))return 1;
			if (a != 0)
			{
				k1 = a / line1.a;
				k2 = a / line2.a;
			}
			else
			{
				k1 = b / line1.b;
				k2 = b / line2.b;
			}
			if ((k1 * line1.c < c && c < k2 * line2.c) || (k1 * line1.c > c && c > k2 * line2.c))return 1;
			else return 0;
		}
		else return 0;
	}