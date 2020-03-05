/*
 * main.cpp
 *
 *  Created on: 23-Sep-2019
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#include<iomanip>
#include<list>

int main(void)
{
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	l1.push_back(60);

	list<int>::iterator itr;
	cout << "list ele's are: ";
	for( itr = l1.begin() ; itr != l1.end() ; itr++ )
		cout << setw(4) << left << *itr;
	cout << endl;

	l1.push_front(5);
	cout << "list ele's are: ";
	for( itr = l1.begin() ; itr != l1.end() ; itr++ )
		cout << setw(4) << left << *itr;
	cout << endl;



	return 0;
}



