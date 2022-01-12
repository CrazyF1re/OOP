#include "List.h"
List::List() { head = new Node(); tail = new Node(-1, head, NULL); head->next = tail;}
List::List(int n):List()
{
	int x;
	srand(time(0));
	for (int i = 0; i < n; i++) 
	{
		x = rand() % 50; Add_to_tail(x);
	}
}
List::List(int* a, int b):List()
{
	for (int i = 0; i < b; i++)
	{
		Add_to_tail(a[i]);
	}
}
List::List(const List& X) :List()
{
	Node* t = X.head->next;
	while (t != X.tail) 
	{
		Add_to_tail(t->key);
		t = t->next;
	}
}
List& List::operator=(const List&X)
{
	if (this != &X) {
		Node* t = X.head->next;
		while (t != X.tail)
		{
			Add_to_tail(t->key);
			t = t->next;
		}
	}
	return *this;
}
List::~List()
{
	clear();
	delete head;
	delete tail;
}
void List::Add_after(int k, Node* pr)
{
	Node* q = new Node(k, pr, pr->next);
	pr ->next = q;
	q->next->prev = q;
}
void List::Add_to_tail(int k) 
{
	Add_after(k, tail->prev);
}
void List::Add_to_tail(Node* p)
{
	p->next = tail;
	p->prev = tail->prev;
	tail->prev->next = p;
	tail->prev = p;
	
}
void List::Add_to_tail(List X) 
{
	Node* t = X.head->next;
	while (t != X.tail) 
	{
		this->Add_to_tail(t->key);
		t = t->next;
	}
}
void List::Add_to_head(int k) 
{
	Add_after(k, head);
}
void List::Add_to_head(List X) 
{
	Node* t = X.tail->prev;
	while (t != X.head)
	{
		this->Add_to_head(t->key);
		t = t->prev;
	}
}
void List::Del(Node* p) 
{
	Node* p1 = p->prev;
	Node* p2 = p->next;
	p1->next = p2;
	p2->prev = p1;
	delete p;
}
void List::Del_head() 
{
	Node* newHead = head ->next;
	delete head;
	head = newHead;
	head->prev = 0;
}
void List::Del_tail()
{
	Node* newTail = tail->prev;
	delete tail;
	tail = newTail;
	tail->next = 0;
}
Node* List::find_key(int k) 
{

	Node* temp = head->next;
	while (temp!=tail) {
		if (temp->key == k)return temp;
		temp = temp->next;
	}
	std::cout << "There is no such element" << std::endl;
	return head;
}
Node* List::find_pos(int k) 
{
	Node* temp = head->next; 
	k--;
	if (k == -1)return head;
	while (k >= 0 && temp!=tail) {
		temp = temp->next;
		k--;
	}
	if (temp == tail)std::cout << "wrong index of element" << '\n';
	return temp;
}
bool List::Is_empty() 
{
	if (head->next->prev!=tail->prev)return 0;
	else return 1;
}
bool List::Is_not_empty() 
{

	if (head->next->prev!=tail->prev)return 1;
	else return 0;
}
void List::clear() 
{
	Node* temp = head->next;
	while (this->Is_not_empty())
	{
		temp = temp->next;
		Del(temp->prev);
	}
}
bool List::operator ==(List s) 
{
	Node* temp1 = head->next;
	Node* temp2 = s.head->next;
	while (temp1->key == temp2->key &&temp1!=tail && temp2!=s.tail) 
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if (temp1 == tail && temp2 == s.tail)return 1;
	else return 0;
}
bool List::operator !=(List s) 
{
	if (*this == s)return 0;
	else return 1;
}
Node* List::Max()
{
	Node* temp = head->next;
	Node* ans = temp;
	temp = temp->next;
	while (temp != tail) 
	{
		if (temp->key > ans->key)ans = temp;
		temp = temp->next;
	}
	return ans;
}
Node* List::Min()
{
	Node* temp = head->next;
	Node* ans = temp;
	temp = temp->next;
	while (temp != tail)
	{
		if (temp->key < ans->key)ans = temp;
		temp = temp->next;
	}
	return ans;
}
void List::Sort()
{
	List temp;
	while (this->Is_not_empty()) 
	{
		Node* t = this->Min();
		temp.Add_after(t->key,temp.tail->prev);
		this->Del(this->Min());
	}
	*this = temp;
}
void List::Scan(int k) 
{
	this->clear();
	while (k > 0) 
	{
		int t;
		std::cin >> t;
		this->Add_after(t, tail->prev);
		k--;
	}
}
void List::Print() 
{
	Node* temp = head->next;
	while (temp != tail) 
	{
		std::cout << temp->Get_key()<<' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}
std::ostream& operator <<(std::ostream& r, List x) 
{
	Node* temp = x.head->Get_next();
	while (temp != x.tail) 
	{
		std::cout << temp->Get_key();
		temp = temp->Get_next();
	}
	return r;
}
std::istream& operator >> (std::istream& r, List& x) 
{
	Node* temp = x.head->Get_next();
	while (temp != x.tail)
	{
		temp->Get_next()->Set_key();
		temp = temp->Get_next();
	}
	return r;
}
