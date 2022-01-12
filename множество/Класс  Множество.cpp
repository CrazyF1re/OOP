#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "     №1" << endl;          //1
    char s[257];
    gets_s(s, 257);
    Set S1(s);
    cout << "S1:" << S1;
    cout << "Number elements in S1: " << S1.Weight()<<endl;
    cout << "     №2" << endl;          //2
    Set S2(S1);
    cout << "S2: " << S2;
    if (S1 == S2)cout << "S1==S2"<<endl;
    else cout << "S1!=S2"<<endl;
    cout << "     №3" << endl;          //3
    if (S2.FindKey('a'))  S2 -= 'a';
    else S2 += 'a';  
    if (S2.FindKey('o'))  S2 -= 'o';
    else  S2 += 'o'; 
    cout << "S2: "<< S2;
    if (S1 == S2)cout << "S1==S2" << endl;
    else cout << "S1!=S2" << endl;
    cout << "     №4" << endl;          //4
    Set S3;
    cout << "S3: " << S3;
    if (S3.Is_Empty())cout << "Set S3 is empty"<<endl;
    else cout << "Set S3 is not empty"<<endl;
    cout << "     №5" << endl;          //5
    S3.Scan(6);
    if (S3.Is_Empty())cout << "Set S3 is empty" << endl;
    else cout << "Set S3 is not empty" << endl;
    cout<<"S3: "<<S3;
    cout << "     №6" << endl;          //6
    Set S4 = S3 -'y'+'i';
    cout << "S4: " << S4;
    cout << "     №7" << endl;          //7
    cout << "S2: " << S2;
    cout << "S4: " << S4;
    Set T1 = S2 + S4;
    Set T2 = S2 * S4;
    Set T3 = S2 - S4;
    cout << "T1=S2+S4 : " << T1;
    cout << "T2=S2*S4 : " << T2;
    cout << "T3=S2-S4 : " << T3;
    cout << "     №8" << endl;          //8
    Set T4 = ~S2;
    cout << "T4=~S2 : " << T4;
    Set T5 = T4 * S2;
    cout << "T5=T4*S2 : " << T5;
    cout << "     №9" << endl;          //9
    Set S5;
    cin >> S5;
    cout << "S5: " << S5;
    cout << "     №10" << endl;          //10
    S5 *= S1;
    cout << "S5: " << S5;
    cout << "     №11" << endl;          //11
    S5 += T2;
    cout << "S5: " << S5;
    cout << "     №12" << endl;          //12
    Set S6 = S1;
    cout << "S6: " << S6;
    if (S5 == S6)cout << "S5==S6" << endl;
    else cout << "S5!=S6" << endl;
}
