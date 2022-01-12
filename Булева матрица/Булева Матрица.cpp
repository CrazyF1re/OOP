#include <iostream>
#include "Bool_Matrix.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "	№1" << endl;
	Bool_Matrix B1(4, 20);
	cout << "B1: " << endl;
	B1.Print();
	cout << "	№2" << endl;
	B1.Invert(0, 10, 8);
	B1.SetUp1(1, 14, 6);
	B1.SetUp1(2, 8, 6);
	for (int i = 1; i < B1.Get_n(); i += 2)
	{
		B1.SetUp1(3,i);
	}
	cout << "B1: " << endl;
	B1.Print();
	cout << "	№3" << endl;
	Bool_Matrix B2(B1);
	cout << "B2: " << endl;
	B2.Print();
	cout << "	№4" << endl;
	if (B2 == B1)cout << "B2 == B1" << endl;
	else cout << "B2!=B1" << endl;
	cout << "	№5" << endl;
	B2.ShiftRightEq(0,6);
	B2.ShiftLeftEq(2,6);
	B2.SetUp0(1, 16); B2.SetUp0(1, 18);
	for (int i = 0; i < B2.Get_n(); i += 2)
	{
		B2.Invert(3, i);
	}
	B2.Print();
	cout << "	№6" << endl;
	Bool_Matrix B3;
	B3.Scan(4,20);
	B3.Print();
	if (B2 != B3)cout << "B2 != B3" << endl;
	else cout << "B2 == B3" << endl;
	cout << "	№7" << endl;
	char** s = new char* [4];
	for (int i = 0; i < 4; i++) 
	{
		s[i] = new char[255];
		cin >> s[i];
	}
	Bool_Matrix B4(s,4);
	cout << "B4: "<<endl;
	B4.Print();
	cout << "	№8" << endl;
	Bool_Matrix C1;
	Bool_Matrix C2;
	Bool_Matrix C3;
	Bool_Matrix C4;
	cout << "C1: ";
	C1.Print();
	if ( C1==B1)cout << "C1 == B1" << endl;
	else cout << "C1 != B1" << endl;
	cout << "	№9" << endl;
	C1 = B1&B2;
	C2 = B1| B2;
	C3 = B1 ^ B2;
	C4 = ~B4;
	cout << "C1 = B1 & B2 " << endl;
	C1.Print();
	cout << "C2 = B1 | B2 " << endl;
	C2.Print();
	cout << "C3 = B1 ^ B2" << endl;
	C3.Print();
	cout << "~B4:" << endl;
	C4.Print();
	cout << "	№10" << endl;
	B1 &= B2;
	cout << "B1 &= B2 " << endl;
	B1.Print();
	if (C1 == B1)cout << "C1 == B1" << endl;
	else cout << "C1 != B1" << endl;
	cout << "	№11" << endl;
	BoolVector t (B1[1]);
	cout << "B1[1] = "; B1[1].Print();
	cout << "B1[1][19] = " << B1[1][19] << "   B1[1][18] = " << B1[1][18] << endl;
	cout << "	№12" << endl;
	cout << "B1.Disj() = ";
	B1.Disj().Print();
	cout << "B1.XOR = ";
	B1.Xor().Print();


}