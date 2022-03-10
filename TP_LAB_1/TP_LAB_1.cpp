#include <iostream>
#include <string>
#include <conio.h>

#include "mother_queue.h"
#include "Anna.h"
#include "Bella.h"
#include "Cris.h"

using namespace std;

int main() {
	A anna_queue;
	B bella_queue;
	C cris_queue;
	Queue* current_queue;
	current_queue = &anna_queue;
	int order = 0;
	cout << "QUEUE" << endl;
	int numQ;
	cout << "---------------------------------------" << endl;
	cout << "select a task:" << endl;
	cout << "1 - Adding a Queue item" << endl;//Добавление элемента очереди
	cout << "2 - Retrieving a queue item" << endl;//Извлечение элемента очереди
	cout << "3 - Displaying the queue on the screen" << endl;//Вывод очереди на экран
	cout << "4 - Counting the sum of odd elements" << endl;//Подсчет суммы нечетных элементов
	cout << "5 - Creating a copy of the queue" << endl;//Создание копии очереди
	cout << "6 - Merging two queues" << endl;//Слияние двух очередей
	cout << "7 - Select a queue" << endl;//Выбор очереди
	cout << "0 - Exiting the program" << endl;//Выход из программы
	while (1)
	{
		cout << "---------------------------------------" << endl;
		cout << "Operation is:";
		cin >> order;
		cout << "---------------------------------------" << endl;
		switch (order)
		{
		case 7:
		{
			cout << "1)Annabelle" << endl << "2)Beatrice" << endl << "3)Clara" << endl << "Numder:";
			cin >> numQ;
			switch (numQ)
			{
			case(1): {current_queue = (Queue*)&anna_queue; break; }
			case(2): {current_queue = (Queue*)&bella_queue; break; }
			case(3): {current_queue = (Queue*)&cris_queue; break; }
			default: break;
			}
			break;
		}
		case 1:
		{
			int newdata = 0;
			cout << "Reading" << endl;
			cout << "Reading occurs before entering 1010" << endl;
			while (1) {
				cin >> newdata;
				if (newdata == 1010) { break; };
				current_queue->Dobavit(newdata);
			}
			cout << "The operation is completed" << endl;
			break;
		}
		case 2:
		{
			current_queue->Ubrat();
			cout << "The operation is completed" << endl;
			break;
		}
		case 3:
		{
			current_queue->Na_Ekran();
			cout << "The operation is completed" << endl;
			break;
		}
		case 4:
		{
			cout << "The sum of odd elements is: " << ((A*)current_queue)->Sum_of_odd_el() << endl;
			cout << "The operation is completed" << endl;
			break;
		}
		case 5:
		{
			current_queue->Kopying();
			cout << "The operation is completed" << endl;
			break;
		}
		case 6:
		{
			Queue* q1,* q2;
			cout << "Choose queue:" << endl << "1)Annabelle" << endl << "2)Beatrice" << endl << "3)Clara" << endl;
			cout << "First queue: ";
			q1 = &anna_queue;
			q2 = &anna_queue;
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case(1): {q1 = &anna_queue; break; }
			case(2): {q1 = (Queue*)&bella_queue; break; }
			case(3): {q1 = (Queue*)&cris_queue; break; }
			default: {cout << "Worng!"; break; }
			}

			choice = 0;
			cout << "Second queue: ";
			cin >> choice;
			switch (choice)
			{
			case(1): {q2 = &anna_queue; break; }
			case(2): {q2 = (Queue*)&bella_queue; break; }
			case(3): {q2 = (Queue*)&cris_queue; break; }
			default: {cout << "Worng!"; break; }
			}

			current_queue -> Merge(q1, q2);
			cout << "The operation is completed" << endl;
			break;
		}
		case 0: return 0;
		default: cout << "Wrong order" << endl;
		}
	}
}