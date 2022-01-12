#include "List.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "		¹1" << endl;
	List S1;
	S1.Add_to_head(1);
	S1.Add_to_tail(10);
	cout << "S1: "; S1.Print();
	cout << "		¹2" << endl;
	List S2(6);
	cout << "S2: "; S2.Print();
	cout << "Max = " << S2.Max()->Get_key() << endl;
	cout << "Min = " << S2.Min()->Get_key() << endl;
	S2.Sort();
	cout << "S2 SORTED: "; S2.Print();
	cout << "		¹3" << endl;
	cout << "S2[2] = " << S2.find_pos(2)->Get_key() << endl;
	S2.Del(S2.find_pos(2));
	cout << "		¹4" << endl;
	S2.find_pos(6);
	S2.Del_tail();
	cout << "S2:"; S2.Print();
	cout << "		¹5" << endl;
	List S3;
	S3 = S1;
	if (S1 == S3)cout << "S1==S3" << endl;
	else cout << "S1!=S3" << endl;
	S3.find_pos(15);
	cout << "		¹6" << endl;
	S3.Del_head();
	S3.Del(S3.find_key(10));
	cout << S3.Is_empty() << endl;
	cout << "		¹7" << endl;
	int a[6];
	for (int i = 0; i < 6; i++) a[i] = rand() % 20;
	List S4(a, 6);
	cout << "S4: "; S4.Print();
	S4.find_key(25);
	S4.Add_after(25, S4.find_pos(3));
	cout << "S4: "; S4.Print();
	cout << "		¹8" << endl;
	List S5(S2);
	cout << "S5: "; S5.Print();
	if (S5.find_key(4) != S5.find_pos(0))S5.Del(S5.find_key(4));
	else S5.Add_to_tail(4);
	cout << "S5: "; S5.Print();
	cout << "		¹9" << endl;
	S5.Scan(4);
	cout << "S5: "; S5.Print();
	cout << "S4: "; S4.Print();
	if (S5 == S4)cout << "S5==S4"<<endl;
	else cout << "S5!=S4"<<endl;
	cout << "		¹10" << endl;
	S5.Add_to_tail(S4);
	cout << "S5: "; S5.Print();
	S5.Add_to_head(S1);
	cout << "S5: "; S5.Print();

}