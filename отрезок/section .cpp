#include "section .h"
#include <iostream>
#define l 0.0000000005//�.�. �������� � float, �� ��������� ���������� ����� ���� ��������� 
using namespace std;
struct Point // ��������� �����
{
	float x;
	float y;
};
Section::Section() { x1 = x2 = y1 = y2 = 0; }
Section::Section(float x1, float y1, float x2, float y2) //����������� � �����������
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
void Section::Input()//������� ����� ���������� �����������
{
	float x1=0, x2=0, y1=0, y2=0;
	cout << "Enter x1, y1,x2,y2:";
	cin>>x1 >> y1 >> x2 >> y2;
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void Section::Output()//������� ������ ����������
{
	cout << "x1 = " << x1 << endl;
	cout << "y1 = " << y1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "y2 = " << y2 << endl;
}

float Section::Length()//������ �������
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));//�� �������
}

void Section::Middle()//�������� �������
{
	cout << "Middle cords is ";
	cout << "X: " << abs(x1 - x2)/2<<"	";//�� �������
	cout << "Y: " << abs(y1 - y2)/2 << endl;//�� �������
}

void Section::Point_by_ratio(float a, float b)// ���������� ����� ������� ������� � ��������� a/b
{
	float temp = abs(a / b);
	cout << "Point by ration  "<<a<<":"<<b<<" is ";
	cout << "X: " << abs(x1 + x2 * temp) / (1 + temp) << "	";
	cout << "Y: " << abs(y1 + y2*temp)/(1+temp)<<endl;
}

bool Section::Is_equal(Section X)//�������� ���������  ���� ��������
{
	if (this->Length() - X.Length()< l)return 1;// �� ������� ������������ ����� ��������
	return 0;
}

bool Section::Paralel_OX()//�������������� ������� ��� OX
{
	if (abs(y1 -y2) <l)return 1;
	return 0;
}

bool Section::Paralel_OY()//�������������� ������� ��� OY
{
	if (abs(x1 - x2)<l)return 1;
	return 0;
}

bool Section::Paralel_to_other(Section X)//�������������� ������� ������� �������
{
	if ((x1 / X.x1 - x2 / X.x2) < l && (y1 / X.y1 - y2 / X.y2) < l)return 1;
	else return 0;
}

bool Section::Perpendicular_to_other(Section X)//������������������ ������� ������� �������
{
	float k1 = (y2 - y1) / (x2 - x1);//������� k1 � y = k1*x+b1
	float k2 = (X.y2 - X.y1) / (X.x2 - X.x1);//������� k2 � � = k2*x+b2
	if ((int)(k2 - k1) / (1 + k2 * k1) == 90)return 1;//����������� ���� ����� ������� ������� ��������� ������������� � int
	else return 0;
}

bool Section::Is_cross_OX()//���������� �� ������� ��� OX
{
	if (y1 * y2 <= 0)return 1;
	else return 0;
}

bool Section::Is_cross_OY()//���������� �� ������� ��� OY
{
	if(x1 * x2 <= 0)return 1;
	else return 0;
}

bool Section::Is_point_belong_section(float a, float b)//����������� �� ����� �������
{
	Section s1(a, b, x1, y1);//1� �������
	Section s2(a, b, x2, y2);//2� �������
	if ((a - x1) / (x2 - x1) - (b - y1) / (y2 - y1) < l && Length()-(s1.Length()+s2.Length()<l))return 1;
	//���������� ������ ��������� ������� � ������ ���� 1�� � 2�� ��������
	else return 0;
}

void Section::Ratio_by_point(float a, float b)// ����� ��������� ���� ���������� �����
{
	if (Is_point_belong_section(a, b))
	{
		Section s1(a, b, x1, y1);
		Section s2(a, b, x2, y2);
		cout << "Ratio = " << s1.Length() << ":" << s2.Length()<<endl;//������� ����� ���� �������� � ������� �� �����������
	}
	else cout << "Point does not belong section";
}

bool Section::Is_point_belong_line(float a, float b)//����������� �� ����� �����, ����������� ����� ����� �������
{
	if ((a - x1) / (x2 - x1) - (b - y1) / (y2 - y1) < l)return 1;//�������
	else return 0;
}

bool Section::Is_section_belong_line()//���������� �� ������� �������� ������
{
	float A1=0, B1=0, C1=0;
	cout << "Enter A,B,C(Ax+By+C=0): ";
	cin >> A1 >> B1 >> C1;
	float A2 = 0, B2 = 0, C2 = 0;
	Point temp;
	A1 = 1 / (x2 - x1);
	B1 = 1 / (y2 - y1);
	C1 = -x1 / (x2 - x1) + y1 / (y2 - y1);
	temp.x = -(C1 * B2 - C2 * B1) / (A1 * B2 - A2 * B1);//������� ���������� ����������� 
	temp.y = -(A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1);//�������� ����� � ����� ����������� �� ������ �������
	if (Is_point_belong_section(temp.x, temp.y))return 1;//�������� ����������� �� ����� �������
	else return 0;
}

void Section::Increase(int k)//��������� ������� �� ����� k
{
	x2 *= k;//�������� ���������� ����� ����� � k ���
	y2 *= k;
}
