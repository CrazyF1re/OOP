#include "Set.h"
#include <iostream>
Set::Set() :BoolVector(256) { M = 0; }
Set::Set(char* str): BoolVector(256)
{
	for (int i = 0; str[i] != '\0'; i++) 
	{
		
		SetUp1((int)str[i]);
		M = Weight();
	}
}
Set::Set(const Set& X) : BoolVector(X) { M = X.M; }
Set::~Set(){}
Set& Set::operator=(const Set&X)
{
	
	this->BoolVector::operator=(X);
	M = X.M;
	return *this;
}
Set Set:: operator +(char ch) 
{
	Set ans = *this;
	ans.SetUp1((UC)ch);
	ans.M = ans.Weight();
	return ans;
}// добавление элемента к множеству создается новое множество
Set& Set:: operator+=(char ch) 
{
	SetUp1((UC)ch);
	M = Weight();
	return *this;
}
Set Set::operator-(char ch)
{
	Set ans = *this;
	ans.SetUp0((UC)ch);
	ans.M = ans.Weight();
	return ans;
}
Set& Set::operator-=(char ch)
{
	SetUp0((UC)ch);
	M = Weight();
	return *this;
}
Set Set::operator +(Set X) 
{
	Set ans = *this;
	ans |= X;
	ans.M = ans.Weight();
	return ans;
}
Set& Set::operator+=(Set X)
{
	*this |= X;
	M = this->Weight();
	return *this;
}
Set Set::operator*(Set X)
{
	Set ans = *this;
	ans &= X;
	ans.M = ans.Weight();
	return ans;
}
Set& Set::operator*=(Set X)
{
	*this &= X;
	M = this->Weight();
	return *this;
}
Set Set::operator -(Set X) 
{
	Set ans = *this;
	ans ^= X;
	ans &= *this;//чтобы исключить элементы  из X которых нет в *this
	ans.M = ans.Weight();
	return ans;
}
Set& Set::operator-=(Set X)
{
	*this ^= X;
	M = this->Weight();
	return *this;
}
Set Set::operator~() 
{
	Set ans = *this;
	ans.BoolVector::operator ~();
	ans.M = ans.Weight();
	return ans;
}
bool Set::operator ==(Set X) 
{
	if (this->BoolVector::operator==(X))return 1;
	else return 0;
}
bool Set::operator!=(Set X)
{
	if (this->BoolVector::operator==(X))return 0;
	else return 1;
}
//int Set::GetNumber()
//{
//	
//}
bool Set::FindKey(char ch)
{
	if (this->operator[]((int)ch)=='1')return 1;
	else return 0;
}
bool Set::Is_Empty() 
{
	if (M)return 0;
	return 1;
}
bool Set::Is_not_Empty() 
{
	if (M)return 1;
	return 0;
}
void Set::Print()
{
	if (Is_not_Empty()) {
		for (int i = 97; i < 123; i++) {
			if (this->operator[](i) == '1')std::cout << char(i) << ' ';
		}
		std::cout << std::endl;
	}
	else std::cout << "set is empty"<<std::endl;
}
void Set::Scan(int n) 
{
	std::cout << "Enter " << n << " elements: ";
	char str[257];
	gets_s(str, 257);
	*this = Set(str);

}
std::ostream& operator<<(std::ostream& r, Set& X)
{
	X.Print();
	return r;
}
std::istream& operator >>(std::istream& r, Set& X)
{
	std::cout << "enter elements: ";
	char str[257];
	gets_s(str, 257);
	X = Set(str);
	return r;	
}
