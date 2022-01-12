#include "massiv.h"
#include <iostream>
int main()
{
	/*1*/Array mas1;
	/*1*/mas1.Scan(5);
	/*1*/mas1.Print(); 
	/*2*/Array mas2(mas1);
	/*2*/std::cout << mas2;
	/*2*/std::cout << std::endl;
	/*3*/if (mas1 == mas2)std::cout << "Its equal"<<std::endl;
	/*3*/else std::cout << "Its different" << std::endl;
	/*4*/mas1 += 6;
	/*4*/mas1.Print();
	/*4*/if (mas1 == mas2)std::cout << "mas1 and mas2 is equal" << std::endl;
	/*4*/else std::cout << "mas1 and mas2 is different" << std::endl;
	/*5*/Array mas3 = mas1 + 7;
	/*5*/mas3.Print();
	/*6*/mas3.DelPosEq(0);
	/*6*/mas3.Print();
	/*7*/Array mas4 = mas3.DelPosNew(mas3.len()-1);
	/*7*/mas4.Print();
	/*8*/int key = 1;
	/*8*/mas1 -= key;
	/*8*/if (mas1 == mas4)std::cout << "mas1 and mas4 is equal" << std::endl;
	/*8*/else std::cout << "mas1 and mas4 is different" << std::endl;
	/*9*/int n, * b;
	/*9*/std::cout << "Enter number of counts" << std::endl;
	/*9*/std::cin >> n;
	/*9*/b = new int[n];
	/*9*/srand(time(0));
	/*9*/for (int i = 0; i < n; i++)
	/*9*/ {
	/*9*/	b[i] = rand() % 100;
	/*9*/}
	/*9*/Array mas5(b,n);
	mas5.Print();
	/*10*/std::cout << "Index of Max is "<<mas5.Max() << std::endl;
	/*10*/std::cout << "Index of Min is " << mas5.Min() << std::endl;
	/*11*/mas5.Sorting();
	/*11*/mas5.Print();
	/*12*/Array mas6 = mas1 + mas5;
	std::cout << "Mas6 is";
	mas6.Print();
	/*13*/Array mas7(4);
	/*13*/mas7.Scan(mas7.len());
	/*14*/if (mas7.FindKey(1) != -1)std::cout << "Element 1 is here" << std::endl;
	/*14*/else std::cout << "Element 1 is absent" << std::endl;
	/*14*/if (mas7.FindKey(10) != -1)std::cout << "Element 10 is here" << std::endl;
	/*14*/else std::cout << "Element 10 is absent" << std::endl;
	/*15*/mas4 += mas7;
	/*15*/mas4.Print();
	/*15*/if (mas4 == mas6)std::cout << "mas4 and mas6 is equal" << std::endl;
	/*15*/else std::cout << "mas4 and mas6 is different" << std::endl;
	/*16*/mas4 = mas6;
	/*16*/mas4.Print();
}