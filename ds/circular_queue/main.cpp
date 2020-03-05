/*
 * main.cpp
 *
 *  Created on: 23-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<cstdlib>
#include"queue.h"

enum menu_options{ EXIT, ENQUEUE, DEQUEUE };

int menu(void)
{
	int choice;
	cout << "CIRCULAR QUEUE OPERATIONS" << endl;
	cout << "0. EXIT" << endl;
	cout << "1. ENQUEUE" << endl;
	cout << "2. DEQUEUE" << endl;
	cout << "ENTER THE CHOICE: ";
	cin >> choice;

	return choice;

}

int main(void)
{
	int choice;
	int ele;
	queue q1;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT: exit(0);
		case ENQUEUE:
			if( !q1.is_queue_full())
			{
				cout << "enter an ele: ";
				cin >> ele;
				q1.enqueue(ele);
				cout << ele << "inserted into the queue ..." << endl;
			}
			else
				cout << "queue is full !!!" << endl;
			break;
		case DEQUEUE:
			if( !q1.is_queue_empty())
			{
				ele = q1.get_front();
				q1.dequeue();
				cout << "deleted ele is: " << ele << endl;
			}
			else
				cout << "queue is empty !!!" << endl;

			break;

		}//end of switch control block
	}//end of while loop

	return 0;
}






