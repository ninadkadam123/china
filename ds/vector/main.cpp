/*
 * main.cpp
 *
 *  Created on: 23-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<vector>
#include<algorithm>


int main(void)
{
	vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);

	cout << "v1 ele's are: ";
	for( int index = 0 ; index < v1.size() ; index++ )
		cout << setw(4) << left << v1[index];
	cout << endl;

	vector<int>::iterator itr;
	cout << "v1 ele's are: ";
	for( itr = v1.begin() ; itr != v1.end() ; itr++ )
		cout << setw(4) << left << *itr;
	cout << endl;



	cout << "min ele is: " << *min_element(v1.begin(), v1.end()) << endl;









	return 0;
}



