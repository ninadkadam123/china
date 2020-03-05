
/*
 * main.cpp
 *
 *  Created on: 24-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<cstdlib>
#include<stack>


enum menu_options{ EXIT, PUSH, POP, PEEK };

int menu(void)
{
	int choice;
	cout << "DYNAMIC STACK" << endl;
	cout << "0. EXIT" << endl;
	cout << "1. PUSH" << endl;
	cout << "2. POP" << endl;
	cout << "3. PEEK" << endl;
	cout << "enter the choice: ";
	cin >> choice;

	return choice;
}

int main(void)
{
	stack<int> s1;
	int ele;

	while(1)
	{
		int choice = menu();

		switch( choice )
		{
		case EXIT: exit(0);

		case PUSH:
			cout << "enter an ele: ";
			cin >> ele;
			s1.push(ele);
			cout << ele << " pushed into the stack successfully..." << endl;
			break;
		case POP:
			if( !s1.empty() )
			{
				ele = s1.top();
				s1.pop();
				cout << "popped ele is: " << ele << endl;
			}
			else
				cout << "stack underflow !!!" << endl;

			break;

		case PEEK:
			if( !s1.empty() )
			{
				cout << "topmost ele is: " << s1.top() << endl;
			}
			else
				cout << "stack underflow !!!" << endl;

			break;
		}
	}

	return 0;
}



