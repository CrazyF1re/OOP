#pragma once
class Section
{private:
	float x1, y1;
	float x2, y2;
public:
	/*1*/Section();//����������� �� ���������
	/*1*/Section(float,float,float,float);//����������� c ����������
	/*2*/void Input();//����
	/*2*/void Output();//�����
	/*3*/float Length();//����� �������
	/*4*/void Middle();//��������
	/*5*/void Point_by_ratio(float, float);//�����, ������� ����� ������� � �������� ����������� 
	/*6*/bool Is_equal (Section);//���������� ��������� ��������� ��� ��������� ���� ��������
	/*7*/bool Paralel_OX();//��������� �� ������� OX
	/*7*/bool Paralel_OY();//��������� �� ������� OY
	/*8*/bool Paralel_to_other(Section);//��������� �� ������� ������� �������
	/*9*/bool Perpendicular_to_other(Section);//��������������� �� ������� ������� �������
	/*10*/bool Is_cross_OX();//���������� �� ������� ��� OX
	/*10*/bool Is_cross_OY();//���������� �� ������� ��� OY
	/*11*/bool Is_point_belong_section(float ,float);//����� �� ����� �� �������
	/*12*/void Ratio_by_point(float,float);//��������� � ������� ����� ����� �������
	/*13*/bool Is_point_belong_line(float,float);//����� �� ����� �� ������, �� ������� ����� �������
	/*14*/bool Is_section_belong_line();
	/*15*/void Increase(int);
};