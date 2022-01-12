#pragma once
#include "bool_vector.h"

class Set : public BoolVector 
{
	int M; // количество элементов

public:
	Set();
	Set(char* );
	Set(const Set& );
	~Set() override;
	Set& operator = (const Set& );
	Set operator +(char);// добавление элемента к множеству создается новое множество
	Set& operator+=(char);//добавление элемента к множеству, изменяется *this
	Set operator -(char);// удаление элемента из множества создается новое множество
	Set& operator-=(char);//удаление элемента из множества,изменяется *this
	Set operator +(Set );// объединение множеств,создается новое множество
	Set& operator+=(Set );//объединение множеств, изменяется *this
	Set operator *(Set );// пересечение множеств,создается новое множество
	Set& operator*=(Set );//пересечение множеств, изменяется *this
	Set operator -(Set );// разность множеств *this/X создается новое множество
	Set& operator-=(Set );//разность множеств *this/X,изменяется *this
	Set operator~();//дополнение до универсального множества (ун.множество - множество из 256 символов алфавита)
	bool operator ==(Set );//операция сравнения двух множеств
	bool operator !=(Set );
	int GetNumber();//нахождение числа  элементов множества
	bool FindKey(char);//проверка принадлежности множству
	bool Is_Empty();
	bool Is_not_Empty();
	virtual void Print()override;
	virtual void Scan(int n)override;

	friend std::ostream& operator <<(std::ostream& r, Set& X);
	friend std::istream& operator >>(std::istream& r, Set& X);
	operator int() 
	{
		return M;
	}
};