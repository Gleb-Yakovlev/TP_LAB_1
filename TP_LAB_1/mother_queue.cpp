#include <iostream>
#include "mother_queue.h"
using namespace std;

Queue::Queue() {
	first_element = nullptr;
	last_element = nullptr;
	size = 0;
}

Queue::~Queue() {
	if (!first_element) return;
	Qelement* q = first_element->next_element;
	while (first_element) {
		delete(first_element);
		first_element = q;
		if (first_element) q = first_element->next_element;
	}
	return;
}

void Queue::Dobavit(int newdata) {

	Qelement* q = new Qelement;
	q->data = newdata;
	q->next_element = nullptr;

	if (size == 0) first_element = q;
	else last_element->next_element = q;

	last_element = q;
	size++;
	return;
}

void Queue::Ubrat() {
	if (first_element == nullptr) { cout << "The queue is empty" << endl; return; }
	cout << "Deleting" << endl;

	Qelement* q = first_element;
	first_element = first_element->next_element;
	delete(q);
	size--;
	return;
}

void Queue::Kopying(Queue* q) {
	if (size == 0) { cout << "The queue is empty, there is nothing to copy"; return; }
	Qelement* old_element = first_element;

	int new_size = q->size;
	for (int i = 1; i <= new_size; i++) {
		q->Ubrat();
	}
	for (int i = 1; i <= size; i++) {
		q->Dobavit(old_element->data);
		old_element = old_element->next_element;
	}
	delete old_element;
	return;
}

void Queue::Merge(Queue* q1, Queue* q2) {
	if ((q1->size == 0) && (q2->size == 0)) { cout << "both queues are empty" << endl; return; }

	Qelement* new_q_element = q2->first_element;

	int New_Size = q1->size + q2->size;
	for (int i = q1->size; i < New_Size; i++) {
		q1->Dobavit(new_q_element->data);
		new_q_element = new_q_element->next_element;
	}
	q1->Na_Ekran();
	return;
}

void Queue::Na_Ekran() {
	if (size == 0) { cout << "Empty queue" << endl; return; }
	Qelement* q = first_element;

	for (int i = 1; i <= size; i++) {
		cout << q->data << endl;
		q = q->next_element;
	}
	return;
}