/*
 * main.cpp
 *
 *  Created on: 23-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<deque>

int main(void)
{
	deque<int> dq1;

	dq1.push_back(11);
	dq1.push_back(22);
	dq1.push_back(33);
	dq1.push_back(44);
	dq1.push_back(55);

	deque<int>::iterator itr;

	cout << "elements in dq1 are: ";
	for( itr = dq1.begin() ; itr != dq1.end()  ; itr++ )
		cout << setw(4) << left << *itr;
	cout << endl;

	//dq1.push_front(5);
	//dq1.pop_back();
	dq1.pop_front();

	cout << "elements in dq1 are: ";
	for( itr = dq1.begin() ; itr != dq1.end()  ; itr++ )
		cout << setw(4) << left << *itr;
	cout << endl;


	return 0;
}







