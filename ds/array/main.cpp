/*
 * main.cpp
 *
 *  Created on: 18-Sep-2019
 *      Author: sunbeam
 */

//file inclusion section
#include<iomanip>
#include<iostream>
using namespace std;

//global declaration section
#define SIZE 5

//function declarations
void accept_array_elements(int arr[]);
void display_array_elements(int arr[]);
int array_sum(int arr[]);
int rec_array_sum(int arr[], int index);
bool linear_search(int arr[], int key);
bool updated_linear_search(int arr[], int key);
bool binary_search(int arr[], int key);

int comparisons=0;

//entry point function
int main(void)
{
	int arr[SIZE] = {10,20,30,40,50};

	//accept_array_elements(arr);
	display_array_elements(arr);
	//cout << "sum = " << array_sum(arr) << endl;
	//cout << "sum = " << rec_array_sum(arr, 0) << endl;

	int key;
	cout << "enter the key: ";
	cin >> key;

	//if( linear_search(arr, key) )
	if( updated_linear_search(arr, key) )
	{
		cout << key << " is found in an array" << endl;
		cout << "no. of comparisons are: " << comparisons << endl;
	}
	else
	{
		cout << key << " is not found in an array" << endl;
		cout << "no. of comparisons are: " << comparisons << endl;
	}

	return 0;
}

bool binary_search(int arr[], int key)
{
	int left = 0;
	int right = SIZE-1;

	comparisons=0;
	//while array/sub array is valid
	while( left <= right )
	{
		//calculate mid position
		int mid = (left+right)/2;

		//compare key with ele which is at mid pos
		comparisons++;
		if( arr[mid] == key )
			return true;

		if( key < arr[mid] )
			right = mid-1;
		else
			left = mid+1;
	}

	return false;
}

bool updated_linear_search(int arr[], int key)
{
	comparisons=0;

	for( int index = 0 ; index < SIZE && key >= arr[index] ; index++ )
	{
		comparisons++;
		if( arr[index] == key )
			return true;
	}

	return false;
}

bool linear_search(int arr[], int key)
{
	comparisons=0;
	for( int index = 0 ; index < SIZE ; index++ )
	{
		comparisons++;
		if( arr[index] == key )
			return true;
	}

	return false;
}

void accept_array_elements(int arr[])
{
	cout << "enter array ele's: " << endl;
	for( int index = 0 ; index < SIZE ; index++ )
	{
		cout << "enter arr[ " << index << " ] : ";
		cin >> arr[index];
	}
}

void display_array_elements(int arr[])
{
	cout << "array ele's are: ";
	for( int index = 0 ; index < SIZE ; index++ )
		cout << setw(4) << left << arr[index];
	cout << endl;
}

int array_sum(int arr[])
{
	int sum = 0;

	for( int index = 0 ; index < SIZE ; index++ )
		sum += arr[index];
	return sum;
}

int rec_array_sum(int arr[], int index)
{
	//base condition
	if( index == SIZE )
		return 0;

	return ( arr[index] + rec_array_sum(arr, index+1));
}



