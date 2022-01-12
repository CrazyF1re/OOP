#pragma once
#include <iostream>
class List;
class Node
{
	int key;
	Node* next, * prev;
public:
	Node() { key = -1; prev = 0; next = 0; }
	Node(int k, Node* pr, Node* nxt)
	{
		key = k; prev = pr; next = nxt;
	}
	int Get_key() { return key; }
	Node* Get_next() { return next; }
	void Set_key() { std::cin >> key;}
	friend class List;
};
class List
{
	Node* head, * tail;
public:
	List();
	List(int n);
	List(int* a, int b);
	List(const List& X);
	List& operator =(const List&);
	~List();
	void Add_after(int k, Node* pr);
	void Add_to_tail(int k);
	void Add_to_tail(Node* p);
	void Add_to_tail(List X);
	void Add_to_head(int k);
	void Add_to_head(List X);
	void Del(Node*p);
	void Del_head();
	void Del_tail();
	Node* find_key(int k);
	Node* find_pos(int k);
	bool Is_empty();
	bool Is_not_empty();
	void clear();
	bool operator ==(List s);
	bool operator !=(List s);
	Node* Max();
	Node* Min();
	void Sort();
	void Scan(int k);
	void Print();
	friend std::ostream& operator <<(std::ostream& r, List x);
	friend std::istream& operator >> (std::istream& r, List& x);
};