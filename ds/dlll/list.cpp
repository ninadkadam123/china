/*
 * list.cpp
 *
 *  Created on: 21-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<cstdlib>

#include"list.h"

list::list(void)
{
	this->head = NULL;
	this->cnt = 0;
}

bool list::is_list_empty(void)
{
	return ( this->head == NULL );
}

void list::add_node_at_last_position(int data)
{
	//create a newnode
	node *newnode = new node(data);

	//if list is empty -- attach newly created node to the head
	if( is_list_empty())
	{
		head = newnode;
		cnt++;
	}
	else//if list is not empty
	{
		//start traversal from the first node
		node *trav = head;

		//traverse list till last node
		while( trav->next != NULL )
			trav = trav->next;

		//attach newly created node to the last node
		trav->next = newnode;
		//store the addr of cur last node into the prev part of newly created node
		newnode->prev = trav;
		this->cnt++;
	}

}


void list::add_node_at_first_position(int data)
{
	//create a newnode
	node *newnode = new node(data);

	//if list is empty -- attach newly created node to the head
	if( is_list_empty())
	{
		head = newnode;
		cnt++;
	}
	else//if list is not empty
	{
		//store the addr of cur first node into the next part of newly created node
		newnode->next = head;
		//store the addr of newly created node into prev part of cur first node
		head->prev = newnode;
		//attach newly created node to the head
		head = newnode;

		this->cnt++;
	}

}

void list::add_node_at_specific_position(int data, int pos)
{
	if( pos == 1  )
		add_node_at_first_position(data);
	else
	if( pos == this->cnt + 1 )
		add_node_at_last_position(data);
	else
	{
		node *newnode = new node(data);
		int i = 1;
		node *trav = head;
		//traverse list till (pos-1)th node
		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		//store the addr of cur (pos)th noed into the next part of newly created node
		newnode->next = trav->next;
		//store the addr of (pos-1)th node into the prev part of newly created node
		newnode->prev = trav;
		//store the addr of newly created node into the prev part cur (pos)th node
		trav->next->prev = newnode;
		//store the addr of newly created node into the next part cur (pos-1)th node
		trav->next = newnode;
		this->cnt++;
	}
}

void list::display_list(void)
{
	//if list is not empty
	if( !is_list_empty())
	{
		node *trav = head;
		node *temp = NULL;
		cout << "list in forward dir is : ";
		while( trav != NULL )
		{
			temp = trav;
			cout << setw(4) << left << trav->data;
			trav = trav->next;
		}
		cout << endl;
		trav = temp;
		cout << "list in backward dir is: ";
		while( trav != NULL )
		{
			cout << setw(4) << left << trav->data;
			trav = trav->prev;
		}
		cout << endl;
	}
	else
		cout << "list is empty !!!" << endl;
}

void list::delete_node_at_first_position(void)
{
	if( !is_list_empty())
	{
		if( head->next == NULL )
		{
			delete head;
			head = NULL;
			cnt = 0;
		}
		else//list contains more than one nodes
		{
			//store the addr of cur second node into the head
			head = head->next;
			//delete the first node
			delete head->prev;
			//make prev part of modified first node as NULL
			head->prev = NULL;
			this->cnt--;
		}
	}
	else
		cout << "list is empty !!!" << endl;

}

void list::delete_node_at_last_position(void)
{
	if( !is_list_empty())
	{
		if( head->next == NULL )
		{
			delete head;
			head = NULL;
			cnt = 0;
		}
		else//list contains more than one nodes
		{
			node *trav = head;
			while( trav->next->next != NULL )
				trav = trav->next;

			delete trav->next;
			trav->next = NULL;

			this->cnt--;
		}
	}
	else
		cout << "list is empty !!!" << endl;

}

list::~list()
{
	if( !is_list_empty())
		free_list();
	else
		cout << "list is empty !!!" << endl;
}

void list::free_list(void)
{
	while( !is_list_empty() )
		delete_node_at_last_position();
		//delete_node_at_first_position();

	cout << "list freed successfully..." << endl;
}

void list::delete_node_at_specific_position(int pos)
{
	if( pos == 1 )
		delete_node_at_first_position();
	else
	if( pos == this->cnt )
		delete_node_at_last_position();
	else
	{
		int i = 1;
		node *trav = head;
		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		node *temp = trav->next;
		trav->next = temp->next;
		temp->next->prev = trav;
		delete temp;
		temp = NULL;
		this->cnt--;

	}
}









