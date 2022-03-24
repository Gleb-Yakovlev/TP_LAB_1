#include "protected_c.h"

int C::Sum_of_odd_el() {
	int sum = 0;
	if (size == 0) { std::cout << "The queue is empty" << std::endl; return sum; }
	Qelement* q = first_element;
	for (int i = 1; i <= size; i++) {
		if(q->data % 2 != 0) sum = sum + q->data;
		q = q->next_element;
	}
	return sum;
}

