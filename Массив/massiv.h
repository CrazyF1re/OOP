#pragma once
#include <iostream>
class Array
{
private:
	int n;//количество элементов
	int* a;//указатель на массив
public:
	Array();//конструктор по умолчанию
	Array(int N);//конструктор с аргументом, N - количество элементов
	Array(int* b, int m);//конструктор с аргументом где N - количество элементов в массиве b
	Array(const Array& X);//конструктор копирования
	~Array();//деструктор
	Array& operator= (const Array& X);//перегрузка оператора присваивания
	void Scan(int m);//считывание m элементов
	void Print();//вывод массива
	int FindKey(int key);// поиск элемента в массиве
	int & operator[] (int i);//перегрузка для считывания элемента по позиции
	Array& operator+= (int key);//перегрузка для добавления key в конец массива
	Array operator+(int key);//перегрузка для формирования нового массива b = a+ key
	Array& operator+=(const Array &С);// перегрузка добавления массива С в конец массива а
	Array operator+(const Array& C);//перегрузка формирования массива y = a + C
	Array& operator-=(int key);//перегрузка удаления элемента	key
	Array operator-(int key);// формирование нового массива b = a - key
	Array& DelPosEq(int pos);// удаление элемента с позиции pos
	Array DelPosNew(int pos);// формирование нового массива b, в котором удален элемент на позиции pos
	bool operator==(Array C);// проверка равенства массивов
	bool operator!=(Array C);// проверка неравенства массивов
	int Max();//индекс максимального элемента массива 
	int Min();//индекс минимального элемента массива
	void Sorting();// сортировка массива 
	void ShiftLeft(int pos);//сдвиг влево начиная с позиции pos+1
	friend std::ostream & operator << (std::ostream &r,Array &x);
	friend std::istream & operator >> (std::istream &r,Array &x);
	int len();
	int Get_one(int i);
	void random_generate();
};