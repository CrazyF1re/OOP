#include "section .h"
#include <iostream>
#define l 0.0000000005//т.к. работаем с float, то некоторые вычисления могут быть неточными 
using namespace std;
struct Point // структура точка
{
	float x;
	float y;
};
Section::Section() { x1 = x2 = y1 = y2 = 0; }
Section::Section(float x1, float y1, float x2, float y2) //конструктор с аргументами
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
void Section::Input()//функция ввода аргументов склавиатуры
{
	float x1=0, x2=0, y1=0, y2=0;
	cout << "Enter x1, y1,x2,y2:";
	cin>>x1 >> y1 >> x2 >> y2;
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void Section::Output()//функция вывода аргументов
{
	cout << "x1 = " << x1 << endl;
	cout << "y1 = " << y1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "y2 = " << y2 << endl;
}

float Section::Length()//длинна отрезка
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));//по формуле
}

void Section::Middle()//середина отрезка
{
	cout << "Middle cords is ";
	cout << "X: " << abs(x1 - x2)/2<<"	";//по формуле
	cout << "Y: " << abs(y1 - y2)/2 << endl;//по формуле
}

void Section::Point_by_ratio(float a, float b)// координаты точки делящей отрезок в отношении a/b
{
	float temp = abs(a / b);
	cout << "Point by ration  "<<a<<":"<<b<<" is ";
	cout << "X: " << abs(x1 + x2 * temp) / (1 + temp) << "	";
	cout << "Y: " << abs(y1 + y2*temp)/(1+temp)<<endl;
}

bool Section::Is_equal(Section X)//проверка равенства  двух отрезков
{
	if (this->Length() - X.Length()< l)return 1;// по условию сравниваются длины отрезков
	return 0;
}

bool Section::Paralel_OX()//параллельность отрезка оси OX
{
	if (abs(y1 -y2) <l)return 1;
	return 0;
}

bool Section::Paralel_OY()//параллельность отрезка оси OY
{
	if (abs(x1 - x2)<l)return 1;
	return 0;
}

bool Section::Paralel_to_other(Section X)//параллельность отрезка другому отрезку
{
	if ((x1 / X.x1 - x2 / X.x2) < l && (y1 / X.y1 - y2 / X.y2) < l)return 1;
	else return 0;
}

bool Section::Perpendicular_to_other(Section X)//перпендикулярность отрезка другому отрезку
{
	float k1 = (y2 - y1) / (x2 - x1);//находим k1 в y = k1*x+b1
	float k2 = (X.y2 - X.y1) / (X.x2 - X.x1);//находим k2 в н = k2*x+b2
	if ((int)(k2 - k1) / (1 + k2 * k1) == 90)return 1;//высчитываем угол между прямыми приводя отношение коэффициентов к int
	else return 0;
}

bool Section::Is_cross_OX()//пересекает ли отрезок ось OX
{
	if (y1 * y2 <= 0)return 1;
	else return 0;
}

bool Section::Is_cross_OY()//пересекает ли отрезок ось OY
{
	if(x1 * x2 <= 0)return 1;
	else return 0;
}

bool Section::Is_point_belong_section(float a, float b)//принадлежит ли точка отрезку
{
	Section s1(a, b, x1, y1);//1й отрезок
	Section s2(a, b, x2, y2);//2й отрезок
	if ((a - x1) / (x2 - x1) - (b - y1) / (y2 - y1) < l && Length()-(s1.Length()+s2.Length()<l))return 1;
	//сравниваем длинну исходного отрезка с суммой длин 1го и 2го отрезков
	else return 0;
}

void Section::Ratio_by_point(float a, float b)// вывод отношения зная координаты точки
{
	if (Is_point_belong_section(a, b))
	{
		Section s1(a, b, x1, y1);
		Section s2(a, b, x2, y2);
		cout << "Ratio = " << s1.Length() << ":" << s2.Length()<<endl;//находим длины двух отрезков и выводим их соотношение
	}
	else cout << "Point does not belong section";
}

bool Section::Is_point_belong_line(float a, float b)//принадлежит ли точка линии, построенной через точки отрезка
{
	if ((a - x1) / (x2 - x1) - (b - y1) / (y2 - y1) < l)return 1;//формула
	else return 0;
}

bool Section::Is_section_belong_line()//пересекает ли отрезок заданную прямую
{
	float A1=0, B1=0, C1=0;
	cout << "Enter A,B,C(Ax+By+C=0): ";
	cin >> A1 >> B1 >> C1;
	float A2 = 0, B2 = 0, C2 = 0;
	Point temp;
	A1 = 1 / (x2 - x1);
	B1 = 1 / (y2 - y1);
	C1 = -x1 / (x2 - x1) + y1 / (y2 - y1);
	temp.x = -(C1 * B2 - C2 * B1) / (A1 * B2 - A2 * B1);//находим координаты пересечения 
	temp.y = -(A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1);//заданной линии и линии построенной по точкам отрезка
	if (Is_point_belong_section(temp.x, temp.y))return 1;//проверем принадлежит ли точка отрезку
	else return 0;
}

void Section::Increase(int k)//умножение отрезка на число k
{
	x2 *= k;//изменяем координаты одной точки в k раз
	y2 *= k;
}
