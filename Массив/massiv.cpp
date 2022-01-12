#include "massiv.h"
#include <iostream>
Array::Array() //конструктор по умолчанию
{
	n = 0;
	a = new int[n+1];
};
/*1*/Array::Array(int N) /*конструктор с целым аргументом, N - количество элементов в массиве*/
{
	a = new int[N]; n = N;
}
/*2*/Array::Array(int* b, int m) //коструктор с аргументом m - число элементов в массиве b;
{
	a = new int[m];
	for (int i = 0; i < m; i++)a[i] = b[i];
	n = m;
}
/*3*/Array::Array(const Array& X)// конструктор
{
	n = X.n;
	a = new int[n];
	for (int i = 0; i < n; i++) 
	{
		a[i] = X.a[i];
	}
}
/*4*/Array & Array::operator= (const Array& X)//перегрузка оператора =
{
	if (this != &X) 
	{
		delete[]a;
		n = X.n;
		a = new int[n];
		for (int i = 0; i < n; i++)a[i] = X.a[i];
	}
	return *this;
}
/*5*/Array::~Array() { delete[]a; }// деструктор
/*6*/void Array::Scan(int m)// считывание элементов
{
	std::cout << "enter array of " << m << " numbers: " << std::endl;
	if (n == m) for (int i = 0; i < n; i++)std::cin >> a[i];
	else 
	{
		delete[]a;
		a = new int[m];
		for (int i = 0; i < m; i++)std::cin >> a[i];
		n = m;
	}
}
/*7*/void Array::Print()//вывод элементов
{
	for (int i = 0; i < n; i++) std::cout << a[i] << ' ';
	std::cout << std::endl;
}
/*8*/int& Array:: operator [](int i)// считывание элемента по позиции 
{
	if (i < 0) 
	{
		std::cout << "incorrect index: i<0" << std::endl;
		return a[0];
	}
	if (i > n) 
	{
		std::cout << "incorrect index: i>n" << std::endl;
		return a[n - 1];
	}
	return a[i];
}
/*9*/int Array::FindKey(int key)//поиск индекса, где стоит элемент key
{
	int i = 0;
	while (this->a[i] != key && i < this->n)i++;
	if (i == this->n)return -1;
	else return i;
}
/*10*/Array& Array::operator+= (int key)//перегрузка оператора добавления элемента в конец массива
{
	int i, * t;
	t = new int[n + 1];
	for (i = 0; i < n; i++)t[i] = a[i];
	t[i] = key;
	delete[]a;
	n++;
	a = t;
	return *this;
}
/*11*/Array Array::operator+(int key)//перегрузка, формирование нового массива b = a+ key;
{
	Array X(n + 1);
	for (int i = 0; i < n; i++)X.a[i] = a[i];
	X.a[n] = key;
	return X;
}
/*12*/Array& Array::operator +=(const Array& C)//перегрузка, добавление массива C в конец массива a
{
	int i, s = 0;
	int size = this->n + C.n;
	int* mas = new int[size];//временный массив
	for ( i = 0; i < this->n; i++)
	{
		mas[i] = this->a[i];
	}
	for (i; i < size; i++) 
	{
		mas[i] = C.a[s];
		s++;
	}
	delete[]this->a;//удаление массива 
	this->n = size;//обновление переменной размера массива
	this->a = new int[size];//объявление нового массива
	for (int i = 0; i < size; i++) this->a[i] = mas[i];//конструктор копирования
	delete[]mas;//освобождение динамической памяти
	return *this;
};
/*13*/Array Array::operator+(const Array& C) //перегрузка, формированиe массива y= a + C
{
	int size = this->n + C.n;
	int i, s = 0;
	Array y(size);
	for (i = 0; i < n; i++)y.a[i] = this->a[i];
	for (i; i < size; i++)
	{
		y.a[i] = C.a[s];
		s++;
	}
	return y;
};
/*14*/Array& Array::operator-=(int key)//перегрузка, удалениe элемента	key
{
	int i = 0;
	while (this->a[i] != key)i++;
	if (i > n)return *this;
	else 
	{
		int* mas = new int[this->n - 1];
		int j = 0;
		for (; j < i; j++)mas[j] = this->a[j];
		for (; j < this->n-1; j++)mas[j] = this->a[j+1];
		delete[]this->a;
		this->n -= 1;
		a = mas;
		return *this;
	}
};
/*15*/Array Array::operator-(int key) //формирование нового массива b = a - key 
{
	Array b = *this;
	b -= key;
	return b;
};
/*16*/Array& Array::DelPosEq(int pos)// удаление элемента с позиции pos
{
	if (pos < 0 || pos >=n)return *this;
	this->ShiftLeft(pos);
	return *this;
};
/*17*/Array Array::DelPosNew(int pos)//полное удаление элемента pos
{
	Array T = *this;
	if (pos < 0 || pos >=n)return T;
	T.ShiftLeft(pos);
	return T;
};
/*18*/bool Array::operator==(Array C) // проверка равенства массивов
{
	int i = 0;
	if (n != C.n)return 0;
	while (i < n && this->a[i] == C.a[i]  )i++;
	if (i == this->n)return 1;
	else return 0;
};
/*19*/bool Array::operator!=(Array C) // проверка неравенства массивов
{
	int i = 0;
	if (n != C.n)return 1;
	while (i < n && this->a[i] == C.a[i])i++;
	if (i == this->n)return 0;
	else return 1;
};
/*20*/int Array::Max() //индекс максимального элемента массива 
{
	int i = 1;
	int imax = 0;
	int max = this->a[0];
	while (i < n) 
	{
		if (this->a[i] > max)
		{
			max = this->a[i];
			imax = i;
		}
		i++;
	}
	return imax;
};
/*21*/int Array::Min()//индекс минимального элемента массива
{
	int i = 1;
	int min = this->a[0];
	while (i < n)
	{
		if (this->a[i] < min)min = this->a[i];
		i++;
	}
	return min;
};
/*22*/void Array::Sorting() //сортировка массива  бинарной вставкой
{
	int i = 1;
	while (i < n)
	{
		int L = 0, R = i, x = a[i];
		while (L < R)
		{
			int m = (L + R) / 2;
			if (x < a[m])
			{
				R = m;
			}
			else L = m + 1;
		}
		int k = i - 1;
		while (k >= R)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = x;
		i++;
	}
};
std::ostream& operator << (std::ostream& r, Array& x) 
{
	for (int i = 0; i < x.n; i++) 
	{
		r <<" "<<x.a[i];
		
	}
	return r;
	
}
std::istream& operator >> (std::istream& r, Array& x) 
{
	for (int i = 0; i < x.n; i++) 
	{
		r >> x.a[i];
	}
	return r;
}
/*23*/void Array::ShiftLeft(int pos)//сдвиг влево начиная с позиции pos+1
{
	for (int i = pos; i < n-1;i++) 
	{
		this->a[i] = this->a[i+1];
	}
	n--;
};
int Array::len()// длинна массива
{
	return this->n;
}
int Array::Get_one(int i) // i-ый элемент массива
{
	if (i < n && i>=0) return this->a[i];
	else return -1;
}
void Array::random_generate()
{
	
}

