/*
 * list.cpp
 *
 *  Created on: 21-Sep-2019
 *      Author: sunbeam
 */
#include<iomanip>
#include<iostream>
using namespace std;
#include"list.h"

list::list(void)
{
	this->head = NULL;
	this->cnt = 0;
}

bool list::is_list_empty()
{
	return ( this->head == NULL );
}

int list::get_cnt(void)
{
	return ( this->cnt );
}

void list::add_node_at_last_position(int data)
{
	//create a newnode
	node *newnode = new node(data);

	//if list is empty - attach newly created node to the head
	if( is_list_empty())
	{
		head = newnode;
		newnode->next = head;
		this->cnt++;
	}
	else//if list not empty
	{
		//start traversal from the first node
		node *trav = head;
		//traverse the list till last node
		while( trav->next != head )
			trav = trav->next;

		//store the addr of first node into the next part of newly created node
		newnode->next = head;
		//attach newly created node to the last node
		trav->next = newnode;

		this->cnt++;
	}
}

void list::add_node_at_first_position(int data)
{
	//create a newnode
	node *newnode = new node(data);

	//if list is empty - attach newly created node to the head
	if( is_list_empty())
	{
		head = newnode;
		newnode->next = head;
		this->cnt++;
	}
	else//if list not empty
	{
		//start traversal from the first node
		node *trav = head;
		//traverse the list till last node
		while( trav->next != head )
			trav = trav->next;

		//store the addr of cur first node into the next part of newly created node
		newnode->next = head;
		//attach newly created node to the head
		head = newnode;
		//update next part of last node by newly added node at first pos
		trav->next = head;
		this->cnt++;
	}
}

void list::display_list(void)
{
	if(!is_list_empty())
	{
		//start traversal from first node
		cout << "no. of nodes in a list are: " << get_cnt() << endl;
		node *trav = head;
		//traverse the list till last node
		cout << "list is: ";
		do
		{
			//visit data part of each node
			cout << setw(4) << left << trav->data;
			trav = trav->next;
		}while( trav != head );
		cout << endl;
	}
	else
		cout << "list is empty !!!" << endl;

}

void list::delete_node_at_first_position(void)
{
	//if list is not empty
	if( !is_list_empty())
	{
		//if list contains only one node
		if( head == head->next )
		{
			//delete the node and make head as NULL & cnt as 0
			delete head;
			head = NULL;
			cnt = 0;
		}
		else//list contains more than one nodes
		{
			//start traversal from the first node
			node *trav = head;

			//traverse the list till last node
			while( trav->next != head )
				trav = trav->next;

			//store the addr of cur second node into the head
			head = head->next;
			//delete the first node
			delete trav->next;
			//update the next part of last node by modified value of head
			trav->next = head;
			this->cnt--;
		}
	}
	else
		cout << "list is empty !!!" << endl;
}

void list::delete_node_at_last_position(void)
{
	//if list is not empty
	if( !is_list_empty())
	{
		//if list contains only one node
		if( head == head->next )
		{
			//delete the node and make head as NULL & cnt as 0
			delete head;
			head = NULL;
			cnt = 0;
		}
		else//list contains more than one nodes
		{
			//start traversal from the first node
			node *trav = head;

			//traverse the list till second last node
			while( trav->next->next != head )
				trav = trav->next;

			//delete the last node
			delete trav->next;
			//store the addr of first node into the next part second last node
			trav->next = head;
			this->cnt--;
		}
	}
	else
		cout << "list is empty !!!" << endl;
}
