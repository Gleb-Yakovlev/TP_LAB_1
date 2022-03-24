#include <iostream>
#include <string>
#include <conio.h>

#include "mother_queue.h"
#include "public_a.h"
#include "private_b.h"
#include "protected_c.h"

using namespace std;

int main() {
	A public_queue;
	B private_queue;
	C protected_queue;
	Queue* current_queue;
	Queue* local_queue;
	current_queue = &public_queue;
	int mega_kost = 1;
	int order;
	int numQ;
	while (1)
	{
		cout << "USED QUEUE ";
		switch (mega_kost) {
		case(1):
				cout << "<<PUBLIC>>" << endl;
				break;
		case(2):
			cout << "<<PRIVATE>>" << endl;
			break;
		case(3):
			cout << "<<PROTECTED>>"<<endl;
			break;
		}

		cout << "PUBLIC:" << endl;
		cout << "---------------------------------------" << endl;
		local_queue = (Queue*)&public_queue; local_queue->Na_Ekran();
		cout << "---------------------------------------" << endl;
		cout << "PRIVATE:" << endl;
		cout << "---------------------------------------" << endl;
		local_queue = (Queue*)&private_queue; local_queue->Na_Ekran();
		cout << "---------------------------------------" << endl;
		cout << "PROTECTED:" << endl;
		cout << "---------------------------------------" << endl;
		local_queue = (Queue*)&protected_queue; local_queue->Na_Ekran();
		cout << "---------------------------------------" << endl;

		cout << "select a task:" << endl;
		cout << "1 - Adding a Queue item" << endl;//Добавление элемента очереди
		cout << "2 - Retrieving a queue item" << endl;//Извлечение элемента очереди
		cout << "3 - Counting the sum of odd elements" << endl;//Подсчет суммы нечетных элементов
		cout << "4 - Creating a copy of the queue" << endl;//Создание копии очереди
		cout << "5 - Merging two queues" << endl;//Слияние двух очередей
		cout << "6 - Select a queue" << endl;//Выбор очереди
		cout << "0 - Exiting the program" << endl;//Выход из программы
		cout << "---------------------------------------" << endl;
		cout << "Operation is:";
		order = 0;
		cin >> order;
		cout << "---------------------------------------" << endl;
		switch (order)
		{
		case 6:
		{
			system("cls");
			cout << "1)Public" << endl << "2)Private" << endl << "3)Protected" << endl << "Numder:";
			cin >> numQ;
			switch (numQ)
			{
			case(1): {current_queue = (Queue*)&public_queue; mega_kost = 1; break; }
			case(2): {current_queue = (Queue*)&private_queue; mega_kost = 2; break; }
			case(3): {current_queue = (Queue*)&protected_queue; mega_kost = 3; break; }
			default: break;
			}
			system("cls");
			break;
		}
		case 1:
		{
			system("cls");
			int newdata;
			int kost = 0;
			cout << "Reading" << endl;
			cout << "Entering up to an incorrect value" << endl;
			while (kost == 0) {
				newdata = 0;
				cin >> newdata;
				if (cin.good() == false) {
					kost = 1;
					cin.ignore(100, '\n');
					cin.clear();
					cout << "End" << endl;
					break;
				}
				else current_queue->Dobavit(newdata);
			}
			cin.ignore(100, '\n');
			system("cls");
			cout << "The operation is completed" << endl;
			break;
		}
		case 2:
		{
			current_queue->Ubrat();
			system("cls");
			cout << "The operation is completed" << endl;
			break;
		}
		case 3:
		{
			system("cls");
			cout << "The sum of odd elements is: " << ((A*)current_queue)->Sum_of_odd_el() << endl;
			cout << "The operation is completed" << endl;
			break;
		}
		case 4:
		{
			system("cls");
			Queue* q = &public_queue;
			cout << "Choose queue:" << endl << "1)Public" << endl << "2)Private" << endl << "3)Protected" << endl;
			int choice = 0;
			cin >> choice;
			if (choice == mega_kost) {system("cls"); cout << "The operation is completed" << endl; break; }
			switch (choice) {
				case(1): {q = &public_queue; break; }
				case(2): {q = (Queue*)&private_queue; break; }
				case(3): {q = (Queue*)&protected_queue; break; }
				default: {cout << "Worng!"; break; }
			}
			current_queue->Kopying(q);
			system("cls");
			cout << "The operation is completed" << endl;
			break;
		}
		case 5:
		{
			system("cls");
			Queue* q1,* q2;
			cout << "Choose queue:" << endl << "1)Public" << endl << "2)Private" << endl << "3)Protected" << endl;
			cout << "First queue: ";
			q1 = &public_queue;
			q2 = &public_queue;
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case(1): {q1 = &public_queue; break; }
			case(2): {q1 = (Queue*)&private_queue; break; }
			case(3): {q1 = (Queue*)&protected_queue; break; }
			default: {cout << "Worng!"; break; }
			}

			choice = 0;
			cout << "Second queue: ";
			cin >> choice;
			switch (choice)
			{
			case(1): {q2 = &public_queue; break; }
			case(2): {q2 = (Queue*)&private_queue; break; }
			case(3): {q2 = (Queue*)&protected_queue; break; }
			default: {cout << "Worng!"; break; }
			}

			current_queue -> Merge(q1, q2);
			system("cls");
			cout << "The operation is completed" << endl;
			break;
		}
		case 0: return 0;
		default: cout << "Wrong order" << endl;
		}
	}
}