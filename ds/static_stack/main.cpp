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

#define SIZE 5

class stack
{
private:
	int arr[SIZE];
	int top;
public:
	stack(void)
	{
		this->top = -1;
	}

	bool is_stack_empty(void)
	{
		return ( this->top == -1 );
	}

	bool is_stack_full(void)
	{
		return ( this->top == SIZE-1 );
	}

	void push_element(int ele)
	{
		//- increment the value of top by 1
		this->top++;
		//- push ele into the stack at top pos
		this->arr[ this->top ] = ele;
	}

	void pop_element(void)
	{
		//- decrement the value of top by 1 i.e. we are popping ele from the stack
		this->top--;
	}

	int peek_element(void)
	{
		//- get the value of topmost ele (without incrementing/decrementing value of top).
		return ( this->arr[ this->top ] );
	}
};


enum menu_options{ EXIT, PUSH, POP, PEEK };

int menu(void)
{
	int choice;
	cout << "STATIC STACK" << endl;
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
	stack s1;
	int ele;

	while(1)
	{
		int choice = menu();

		switch( choice )
		{
		case EXIT: exit(0);

		case PUSH:
			if( !s1.is_stack_full() )
			{
				cout << "enter an ele: ";
				cin >> ele;
				s1.push_element(ele);
				cout << ele << " pushed into the stack successfully..." << endl;
			}
			else
				cout << "stack overflow !!!" << endl;
			break;
		case POP:
			if( !s1.is_stack_empty() )
			{
				ele = s1.peek_element();
				s1.pop_element();
				cout << "popped ele is: " << ele << endl;
			}
			else
				cout << "stack underflow !!!" << endl;

			break;

		case PEEK:
			if( !s1.is_stack_empty() )
			{
				cout << "topmost ele is: " << s1.peek_element() << endl;
			}
			else
				cout << "stack underflow !!!" << endl;

			break;

		}

	}

	return 0;
}
