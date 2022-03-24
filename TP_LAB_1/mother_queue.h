#pragma once
#include <iostream>

struct Qelement
{
	int data;
	Qelement* next_element = nullptr;
} typedef Qelement;


class Queue {
public:
	Queue();
	~Queue();
	void Dobavit(int);
	void Ubrat();
	void Na_Ekran();
	void Kopying(Queue*);
	void Merge(Queue*, Queue*);

	friend class A;
	friend class B;
	friend class C;
private:
	Qelement* first_element;
	Qelement* last_element;

protected:
	int size;
};

