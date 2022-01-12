#pragma once
#include <iostream>
template <class T> class Array
{
private:
	int n;//количество элементов
	T* a;//указатель на массив
public:
	Array() {
		n = 0;
		a = new T[n + 1];
		a[0] = 0;
	}//конструктор по умолчанию
	Array(int N) {
		a = new T[N]; n = N;
		for (int i = 0; i < n; i++)a[i] = 0;
	}//конструктор с аргументом, N - количество элементов
	Array(T* b, int m) {
		a = new T[m];
		for (int i = 0; i < m; i++)a[i] = b[i];
		n = m;
	}//конструктор с аргументом где N - количество элементов в массиве b
	Array(const Array<T>& X)// конструктор
	{
		n = X.n;
		a = new T[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = X.a[i];
		}
	}//конструктор копирования
	~Array() { delete[]a; }//деструктор
	Array<T>& operator= (const Array<T>& X)//перегрузка оператора =
	{
		if (this != &X)
		{
			delete[]a;
			n = X.n;
			a = new T[n];
			for (int i = 0; i < n; i++)a[i] = X.a[i];
		}
		return *this;
	}//перегрузка оператора присваивания
	void Scan(int m)// считывание элементов
	{
		std::cout << "enter array of " << m << " numbers: " << std::endl;
		if (n == m) for (int i = 0; i < n; i++)std::cin >> a[i];
		else
		{
			delete[]a;
			a = new T[m];
			for (int i = 0; i < m; i++)std::cin >> a[i];
			n = m;
		}
	}//считывание m элементов
	void Print()//вывод элементов
	{
		for (int i = 0; i < n; i++) std::cout << a[i] << ' ';
		std::cout << std::endl;
	}//вывод массива
	int FindKey(int key)//поиск индекса, где стоит элемент key
	{
		int i = 0;
		while (this->a[i] != key && i < this->n)i++;
		if (i == this->n)return -1;
		else return i;
	}// поиск элемента в массиве
	T & operator[] (int i) {
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
	}//перегрузка для считывания элемента по позиции
	Array<T>& operator+= (T key)//перегрузка оператора добавления элемента в конец массива
	{
		int i; T* t;
		t = new T[n + 1];
		for (i = 0; i < n; i++)t[i] = a[i];
		t[i] = key;
		delete[]a;
		n++;
		a = t;
		return *this;
	}//перегрузка для добавления key в конец массива
	Array<T> operator+(T key)//перегрузка, формирование нового массива b = a+ key;
	{
		Array<T> X(n + 1);
		for (int i = 0; i < n; i++)X.a[i] = a[i];
		X.a[n] = key;
		return X;
	}//перегрузка для формирования нового массива b = a+ key
	Array<T>& operator+=(const Array<T>& c)//перегрузка, добавление массива C в конец массива a
	{
		int i, s = 0;
		int size = this->n + c.n;
		T* mas = new T[size];//временный массив
		for (i = 0; i < this->n; i++)
		{
			mas[i] = this->a[i];
		}
		for (i; i < size; i++)
		{
			mas[i] = c.a[s];
			s++;
		}
		delete[]this->a;//удаление массива 
		this->n = size;//обновление переменной размера массива
		this->a = new T[size];//объявление нового массива
		for (int i = 0; i < size; i++) this->a[i] = mas[i];//конструктор копирования
		delete[]mas;//освобождение динамической памяти
		return *this;
	};// перегрузка добавления массива С в конец массива а
	Array<T> operator+(const Array<T>& C) //перегрузка, формированиe массива y= a + C
	{
		int size = n + C.n;
		int i, s = 0;
		Array<T> y(size);
		for (i = 0; i < n; i++)y.a[i] = a[i];
		for (i; i < size; i++)
		{
			y.a[i] = C.a[s];
			s++;
		}
		return y;
	};//перегрузка формирования массива y = a + C
	Array<T>& operator-=(T key)//перегрузка, удалениe элемента	key
	{
		int i = -1;
		while (this->a[i] != key)i++;
		if (i > n - 1)return *this;
		else
		{
			i++;
			T* mas = new T[this->n - 1];
			int j = 0;
			for (; j < i; j++)mas[j] = this->a[j];
			for (; j < this->n - 1; j++)mas[j] = this->a[j + 1];
			delete[]this->a;
			this->n -= 1;
			a = mas;
			return *this;
		}
	};//перегрузка удаления элемента	key
	Array<T> operator-(T key) //формирование нового массива b = a - key 
	{
		Array<T> b = *this;
		b -= key;
		return b;
	};// формирование нового массива b = a - key
	Array<T>& DelPosEq(int pos)// удаление элемента с позиции pos
	{
		if (pos < 0 || pos >= n)return *this;
		this->ShiftLeft(pos);
		return *this;
	};// удаление элемента с позиции pos
	Array<T> DelPosNew(int pos)//полное удаление элемента pos
	{
		Array<T> s = *this;
		if (pos < 0 || pos >= n)return s;
		s.ShiftLeft(pos);
		return s;
	};// формирование нового массива b, в котором удален элемент на позиции pos
	bool operator==(Array<T> C) // проверка равенства массивов
	{
		int i = 0;
		if (n != C.n)return 0;
		while (i < n && this->a[i] == C.a[i])i++;
		if (i == this->n)return 1;
		else return 0;
	};// проверка равенства массивов
	bool operator!=(Array<T> C) // проверка неравенства массивов
	{
		int i = 0;
		if (n != C.n)return 1;
		while (i < n && this->a[i] == C.a[i])i++;
		if (i == this->n)return 0;
		else return 1;
	};// проверка неравенства массивов
	int Max() //индекс максимального элемента массива 
	{
		int i = 1;
		int imax = 0;
		int max = a[0];
		while (i < n)
		{
			if (a[i] > max)
			{
				max = a[i];
				imax = i;
			}
			i++;
		}
		return imax;
	};//индекс максимального элемента массива 
	int Min()//индекс минимального элемента массива
	{
		int i = 1;
		int min = a[0];
		while (i < n)
		{
			if (a[i] < min)min = a[i];
			i++;
		}
		return min;
	};//индекс минимального элемента массива
	void Sorting() //сортировка массива  бинарной вставкой
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
	};// сортировка массива 
	void ShiftLeft(int pos)//сдвиг влево начиная с позиции pos+1
	{
		for (int i = pos; i < n - 1; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
	};//сдвиг влево начиная с позиции pos+1
	template <class T> friend std::ostream & operator << (std::ostream &r,Array<T>&x)
	{
		for (int i = 0; i < x.n; i++)
		{
			r << " " << x.a[i];

		}
		return r;

	}
	template <class T> friend std::istream & operator >> (std::istream &r,Array<T>&x)
	{
		for (int i = 0; i < x.n; i++)
		{
			r >> x.a[i];
		}
		return r;
	}
	int len()// длинна массива
	{
		return this->n;
	}
	int Get_one(int i) // i-ый элемент массива
	{
		if (i < n && i >= 0) return this->a[i];
		else return -1;
	}
};