#include <iostream>
#include "bool_vector.h"
using namespace std;
int main()
{

    setlocale(LC_ALL, "Russian");
    cout << "№1" << endl;           //1
    cout << endl;
    BoolVector B1;
    BoolVector B2(10);
    BoolVector B3((char*)"111011101110");
    BoolVector B4((char*)"111011101110", 10);
    BoolVector B5((char*)"111011101110", 16);
    cout << "B1: ";B1.Print(); 
    cout << "B2: "; B2.Print();
    cout << "B3: "; B3.Print(); 
    cout << "B4: "; B4.Print(); 
    cout << "B5: "; B5.Print();
    cout << endl;
    cout << "№2" << endl;           //2
    cout << endl;
    cout << "Вес B3 = " << B3.Weight();
    cout << "  Вес B5= " << B5.Weight();
    if (B3 == B5)cout << "  B3 = B5" << endl;
    else cout << "  B3 != B5" << endl;
    cout << endl;
    cout << "№3" << endl;           //3
    cout << endl;
    BoolVector B6(B5);
    cout << "B5: "; B5.Print();
    cout << "B6: "; B6.Print();
    cout << endl;
    cout << "№4" << endl;           //4
    cout << endl;
    B2.Scan(B2.Get_n());
    cout << "B2: "; B2.Print();
    cout << endl;
    cout << "№5" << endl;           //5
    cout << endl;
    B1 = B2;
    cout << "B1 = "; B1.Print();
    if (B1 == B2)cout << "B1 = B2" << endl;
    else cout << "B1 != B2" << endl;
    cout << endl;
    cout << "№6" << endl;           //6
    cout << endl;
    BoolVector V1 = B1 & B3;
    BoolVector V2 = B1 | B3;
    BoolVector V3 = B1 ^ B3;
    cout << "V1=B1&B3: "; V1.Print();
    cout << "V2=B1|B3: "; V2.Print();
    cout << "V3B1^B3: "; V3.Print();
    cout << endl;
    cout << "№7" << endl;           //7
    cout << endl;
    B1 &= B3;
    cout << "B1&=B3: "; B1.Print();
    if (B1 == V1)cout << "B1 = V1" << endl;
    else cout << "B1 != V1" << endl;
    cout << endl;
    cout << "№8" << endl;           //8
    cout << endl;
    B2 |= B3;
    cout << "B2|=B3: "; B2.Print();
    if (B2 == V2)cout << "B2 = V2" << endl;
    else cout << "B2 != V2" << endl;
    cout << endl;
    cout << "№9" << endl;           //9
    cout << endl;
    cout << "B1: "; B1.Print();
    ~B1;
    cout << "~B1: "; B1.Print();
    cout << "B1[4] = " << B1[4];
    cout << " B1[5] = " << B1[5]<<endl;
    cout << endl;
    cout << "№10" << endl;          //10
    cout << endl;
    cout << "B1: "; B1.Print();
    B1.SetUp1(11);
    cout << "B1 : "; B1.Print();
    B1.SetUp0(7);
    cout << "B1SetUp0(7): "; B1.Print();
    B1.Invert(9);
    cout << "B1Invert(9): "; B1.Print();
    cout << endl;
    cout << "№11" << endl;          //11
    cout << endl;
    B1.SetUp1(3,5);
    cout << "B1: "; B1.Print();
    cout << "B1SetUp1(3,5): "; B1.Print();
    B1.Invert(3, 1);
    cout << "B1Invert(3,1): "; B1.Print();
    cout << endl;
    cout << "№12" << endl;          //12
    cout << endl;
    cout << "B1: "; B1.Print();
    BoolVector V4 = B1 << 4;
    B1>>= 4;
    cout << "V4=B1<<4: "; V4.Print();
    cout << "B1>>=4: "; B1.Print();
    if (B1 == V4)cout << "V4 = B1" << endl;
    else cout << "V4 != B1" << endl;

}