/*
 * main.cpp
 *
 *  Created on: 19-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

#define SWAP(a,b) { int t = a; a = b; b = t; }
#define SIZE 8

void display_array_elements(int arr[]);
void selection_sort(int arr[]);
void bubble_sort(int arr[]);
void insertion_sort(int arr[]);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quick_sort(int arr[], int left, int right);

int main(void)
{
	int arr[SIZE] = { 50,10,70,40,80,30,20,60};
	//int arr[SIZE] = {10,20,30,40,50,60};

	display_array_elements(arr);

	//selection_sort(arr);
	//bubble_sort(arr);
	//insertion_sort(arr);
	//merge_sort(arr, 0, SIZE-1);
	quick_sort(arr, 0, SIZE-1);
	display_array_elements(arr);

	return 0;
}

void quick_sort(int arr[], int left, int right)
{
	if( left >= right )
		return;

	int i = left;
	int j = right;
	int pivot = arr[left];

	while( i < j )
	{
		while( i <= right && arr[i] <= pivot )
			i++;

		while( arr[j] > pivot )
			j--;

		//if i & j have not crossed swap them
		if( i < j )
			SWAP(arr[i], arr[j]);
	}

	//swap pivot ele with jth pos ele
	SWAP(arr[left], arr[j]);
	//apply quick sort on left partition
	quick_sort(arr,left,j-1);

	//apply quick sort on right partition
	quick_sort(arr,j+1,right);
}

void merge_sort(int arr[], int left, int right)
{
	if( left >= right )
		return;

	int mid = (left+right)/2;
	merge_sort(arr, left, mid);
	merge_sort(arr,mid+1, right);
	merge(arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right)
{
	int i = left;
	int j = mid+1;
	int k = 0;
	int size = (right-left)+1;
	int *temp = new int[size];

	while( i <= mid && j <= right )
	{
		if( arr[i] < arr[j] )
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	//copy remaining ele's from left subarray into temp array
	while( i <= mid )
		temp[k++] = arr[i++];

	//copy remaining ele's from right subarray into temp array
	while( j <= right )
		temp[k++] = arr[j++];

	//copy temp array ele's into an original array
	k=0;
	i=left;

	while( i <= right )
		arr[i++] = temp[k++];

	//delete temp array
	delete [] temp;
	temp = NULL;
}

void insertion_sort(int arr[])
{
	int iterations = 0;
	int while_cnt = 0;

	for( int i = 1 ; i < SIZE ; i++ )
	{
		int key = arr[i];
		int j = i-1;

		iterations++;

		while( j >= 0 && key <= arr[j] )
		{
			//shift ele towards right by 1 pos
			arr[j+1] = arr[j];
			j--;
			while_cnt++;
		}
		//insert key at appropriate pos
		arr[j+1] = key;
	}

	cout << "no. of iterations are	: " << iterations << endl;
	cout << "while_cnt	: " << while_cnt << endl;
}

void bubble_sort(int arr[])
{
	int iterations = 0;
	int comparisons=0;
	bool flag = true;

	for( int it = 0 ; it < SIZE-1 && flag == true ; it++ )
	{
		flag = false;
		iterations++;
		for( int pos = 0 ; pos < SIZE-it-1 ; pos++ )
		{
			comparisons++;
			//if ele's are not in order - then swap them
			if( arr[ pos ] > arr[ pos+1 ] )
			{
				flag = true;
				SWAP(arr[pos], arr[pos+1]);
			}
		}
	}

	cout << "no. of ietrations are	: " << iterations << endl;
	cout << "no. of comparisons are	: " << comparisons << endl;


}
void selection_sort(int arr[])
{
	int iterations=0;
	int comparisons=0;

	for( int sel_pos = 0 ; sel_pos < SIZE-1 ; sel_pos++ )
	{
		iterations++;
		for( int another_pos = sel_pos + 1 ; another_pos < SIZE ; another_pos++ )
		{
			comparisons++;
			if( arr[ sel_pos ] > arr[ another_pos] )
				SWAP(arr[sel_pos], arr[another_pos]);
		}
	}

	cout << "no. of ietrations are	: " << iterations << endl;
	cout << "no. of comparisons are	: " << comparisons << endl;

}

void display_array_elements(int arr[])
{
	cout << "array ele's are: ";
	for( int index = 0 ; index < SIZE ; index++ )
	{
		cout << setw(4) << left << arr[index];
	}
	cout << endl;
}
