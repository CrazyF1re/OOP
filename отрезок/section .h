#pragma once
class Section
{private:
	float x1, y1;
	float x2, y2;
public:
	/*1*/Section();//конструктор по умолчанию
	/*1*/Section(float,float,float,float);//конструктор c аргументом
	/*2*/void Input();//ввод
	/*2*/void Output();//вывод
	/*3*/float Length();//длина отрезка
	/*4*/void Middle();//середина
	/*5*/void Point_by_ratio(float, float);//точка, которая делит отрезок в заданном соотношении 
	/*6*/bool Is_equal (Section);//перегрузка оператора сравнения для сравнения двух отрезков
	/*7*/bool Paralel_OX();//паралелен ли отрезок OX
	/*7*/bool Paralel_OY();//паралелен ли отрезок OY
	/*8*/bool Paralel_to_other(Section);//паралелен ли отрезок другому отрезку
	/*9*/bool Perpendicular_to_other(Section);//перпендикулярен ли отрезок другому отрезку
	/*10*/bool Is_cross_OX();//пересекает ли отрезок ось OX
	/*10*/bool Is_cross_OY();//пересекает ли отрезок ось OY
	/*11*/bool Is_point_belong_section(float ,float);//лежит ли точка на отрезке
	/*12*/void Ratio_by_point(float,float);//отношение в котором делит точка отрезок
	/*13*/bool Is_point_belong_line(float,float);//лежит ли точка на прямой, на которой лежит отрезок
	/*14*/bool Is_section_belong_line();
	/*15*/void Increase(int);
};