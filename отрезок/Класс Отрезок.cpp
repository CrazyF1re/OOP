// Класс Отрезок.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "section .h"
using namespace std;
int main()
{
    Section S1;
    Section S2(0, 0, 3, 4);
    S1.Input();
    cout << "S1: " << endl;
    S1.Output();
    cout << "Length of S2 = " << S2.Length()<<endl;
    S2.Middle();
    S2.Point_by_ratio(1, 1);
    cout << "Equals of S1 and S2 = " << S2.Is_equal(S1) << endl;
    cout << "Is S2 paralel OX = " << S2.Paralel_OX() << endl;
    cout << "Is S2 paralel OY = " << S2.Paralel_OY() << endl;
    cout << "Is S2 paralel S1 = " << S2.Paralel_to_other(S1) << endl;
    cout << "Is S2 perpendicular S1 = " << S2.Perpendicular_to_other(S1) << endl;
    cout << "Is S2 cross OX = " << S2.Is_cross_OX() << endl;
    cout << "Is S2 cross OY = " << S2.Is_cross_OY() << endl;
    cout << "Is point belong S2: " << S2.Is_point_belong_section(3, 4)<<endl;
    cout << "Ratio of S2 by point:"; S2.Ratio_by_point(1.5, 2);
    cout << "Is point belong line by S2: " << S2.Is_point_belong_line(1.5, 2)<<endl;
    cout << "Is section S2 belong line: " << S2.Is_section_belong_line()<<endl;
    S2.Increase(3);
    cout <<"new length of S2: " <<S2.Length();

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
