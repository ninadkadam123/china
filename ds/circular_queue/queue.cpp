/*
 * queue.cpp
 *
 *  Created on: 23-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

#include"queue.h"

queue :: queue(void)
{
	this->front = -1;
	this->rear = -1;
}

bool queue :: is_queue_full(void)
{
	return ( this->front == ( (this->rear+1) % SIZE ) );
}

bool queue :: is_queue_empty(void)
{
	return ( this->rear == -1 && this->front == this->rear );
}

void queue :: enqueue(int ele)
{
	//increment the value of rear by 1
	this->rear = ( this->rear + 1 ) % SIZE;
	//insert ele into the queue at rear pos
	this->arr[ this->rear ] = ele;

	if( this->front == -1 )
		this->front = 0;

}

void queue :: dequeue(void)
{
	if( this->front == this->rear )//we are deleting last ele
	{
		//reinitialize queue
		this->front = this->rear = -1;
	}
	else
	{
		//increment the value of front by 1
		this->front = ( this->front + 1) % SIZE;
	}
}

int queue :: get_front(void)
{
	return ( this->arr[ this->front] );
}





