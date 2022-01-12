struct Point
{
	float x;
	float y;
};
#include <iostream>
#define PI 3.1415926535
class Straight
{
	float a, b, c;
	double eps = 0.0000005;
public:
	/*1*/Straight(float ax = 1, float by = 1, float C = 1)//1
	{
		a = ax;
		b = by;
		c = C;
	}
	/*2*/void Print()
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
	/*2*/void Input() 
	{
		int ax, by, C;
		std::cin >> ax >> by >> C;
		a = ax;
		b = by;
		c = C;
	}
	/*3*/bool check_start_cords()
	{
		if (c) return 0;
		else return 1;
	}
	/*4*/void check_parallelism_axis()
	{
		if (a && !b) std::cout << "Паралельна оси Ox" << std::endl;
		else if (!a && b)std::cout << "Паралельна оси Oy" << std::endl;
		else std::cout << "Не параллельна ни одной из осей" << std::endl;
	}
	/*5*/void segments()
	{
		if (c == 0) std::cout << "Отрезков нет т.к. прямая проходит через начало координат" << std::endl;
		else if (a ==0)
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
	/*6*/float coefficient()
	{
		if (b == 0)return 0;
		if (!a && b)
		{
			std::cout << "Паралельна оси Oy => коэффициент не существует" << std::endl;
			return 0;
		}
		else return -a / b;
	}
	/*7*/bool check_similarity(Straight line2)
	{
		if (a == line2.a && b == line2.b && c == line2.c)return 1;
		else return 0;
	}
	/*8*/bool check_parallelism_two_lines(Straight line2)
	{

		if (fabs(coefficient() -line2.coefficient())<eps) return 1;
		else return 0;
	}
	/*9*/bool check_perpendicularity(Straight line2)
	{
		if (fabs((a * line2.a + b * line2.b) )< eps)return 1;
		else return 0;
	}
	/*10*/float distance() { return (c / sqrt(a * a + b * b)); }
	/*11*/bool check_point(Point p)
	{
		if (fabs((a * p.x + b * p.y + c)) <eps) return 1;
		else return 0;
	}
	/*12*/float distance_to_point(Point p)
	{
		float chislitel = fabs(a * p.x + b * p.y + c);
		float znamenatel = sqrt(a * a + b * b);
		return chislitel / znamenatel;
	}
	/*13*/bool check_cross_two_lines(Straight line2)
	{
		if (check_parallelism_two_lines(line2))return 0;
		else return 1;
	}
	/*14*/Point cross_point(Straight line2)
	{
		Point p{0,0};
		if (check_parallelism_two_lines(line2))return p;
		else 
		{
			p.x = ((-c * line2.b + b * line2.c) / (a * line2.b - b * line2.a));
			p.y = (-a*line2.c+c*line2.a) / (a * line2.b - b * line2.a);
			return p;
		}
	}
	/*15*/double injection_between_lines(Straight line2)
	{
		if (check_parallelism_two_lines(line2))return 0;
		double param = a * line2.a + b * line2.b;
		if (param < 0)param *= -1;
		param /= (sqrt(a * a + b * b) * sqrt(line2.a * line2.a + line2.b * line2.b));
		param = acos(param) * 180.0 / PI;
		return param;
	}
	/*16*/void which_line_is_closer(Straight line2)
	{
		if (distance() > line2.distance()) std::cout << "Линия line2 ближе" << std::endl;
		else std::cout << "Линия line1 ближе" << std::endl;
	}
	/*17*/float distance_between_paralel_lines(Straight line2)
	{
		float ans = fabs(distance() - line2.distance());
		return ans;
	}
	/*18*/bool is_line_between_others(Straight line1,Straight line2)
	{
		if (check_parallelism_two_lines(line1) && check_parallelism_two_lines(line2))
		{
			float k1, k2;
			if ((line1.c >= c && line2.c <= c) || (line1.c <= c && line2.c >= c))return 1;
			if (a != 0) 
			{
				k1 =a / line1.a;
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
};
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	Point p{0, 0};
	/*1*/Straight line1;
	/*1*/Straight line2(1,1,-3);
	/*1*/Straight line3;
	/*1*/cout << "line1 : ";
	/*1*/line1.Print();
	/*1*/cout <<endl;
	/*1*/cout << "line2 : ";
	/*1*/line2.Print();
	/*1*/cout << endl;
	line3.Input();
	/*1*/cout << "line3 : ";
	/*1*/line3.Print();
	/*1*/cout << endl;
	/*3*/cout << "Проходит ли line1 через начало координат : " <<line1.check_start_cords() << endl;
	/*4*/cout << "Прямая  line1 : ";
	/*4*/line1.check_parallelism_axis();
	/*5*/line1.segments();
	/*6*/cout << "Коэффициент line1 : " << line1.coefficient() << endl;
	/*7*/cout << "Совпадают ли прямые line1 и line2? Ответ : " << line1.check_similarity(line2)<<endl;
	/*8*/cout << "Параллельны ли прямые line1 и line2? Ответ : " << line1.check_parallelism_two_lines(line2) << endl;
	/*9*/cout << "Перпендикулярны ли прямые line1 и line2? Ответ : " << line1.check_perpendicularity(line2)<<endl;
	/*10*/cout << "Расстояние от начала координат до прямой line1 равно : " << line1.distance()<<endl;
	/*11*/cout << "Пренадлежит ли точка p прямой line1? Ответ : " << line1.check_point(p) << endl;
	/*12*/cout << "Расстояние от точки p до прямой line1 равно : " << line1.distance_to_point(p) << endl;
	/*13*/cout << "Пересекаются ли прямые line1 и line2? Ответ : " << line1.check_cross_two_lines(line2)<<endl;
	/*14*/cout << "Точкой пересечения прямых line1 и line2 является точка : x = " << line1.cross_point(line2).x<< "y ="<< line1.cross_point(line2).y<< endl;
	/*15*/cout << "Угол между прямыми line1 и line2 равен : " << line1.injection_between_lines(line2)<<endl;
	/*16*/cout << "Какая из прямых ближе к началу координат? Ответ :"; line1.which_line_is_closer(line2);
	/*17*/cout << "Расстояние между двумя параллельными прямымми равно :" << line1.distance_between_paralel_lines(line2)<<endl;
	/*18*/cout << "Лежит ли прямая line3 между прямыми line1 и line2? Ответ :" << line3.is_line_between_others(line1, line2) << endl;


	
	//std::cout << line1.cross_point(-2,4,5).x << ' ' << line1.cross_point(-2, 4, 5).y; пересечение двух прямых
	//std::cout << line2.injection_between_lines(line1);        угол между двумя пересекающимися прямыми



}
