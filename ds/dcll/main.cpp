/*
 * main.cpp
 *
 *  Created on: 21-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<cstdlib>

class list;

class node
{
private:
	node *prev;
	int data;
	node *next;
public:
	node(int data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
	friend class list;
};

class list
{
private:
	node *head;
	int cnt;
public:
	list(void)
	{
		this->head = NULL;
		this->cnt = 0;
	}

	bool is_list_empty(void)
	{
		return ( this->head == NULL );
	}

	void add_node_at_last_position(int data)
	{
		//create a newnode
		node *newnode = new node(data);

		//if list is empty
		if( is_list_empty())
		{
			head = newnode;
			newnode->next = newnode;
			newnode->prev = head;
		}
		else
		{
			//store the addr of first node into the next part of newly created node
			newnode->next = head;
			//store the addr of cur last node into the prev part of newly created node
			newnode->prev = head->prev;
			//store the addr of newly created  node into the next part of cur last node
			head->prev->next = newnode;
			//update prev part of first node by addr of newly created node
			head->prev = newnode;
			this->cnt++;
		}
	}

	void add_node_at_first_position(int data)
	{
		//create a newnode
		node *newnode = new node(data);

		//if list is empty
		if( is_list_empty())
		{
			head = newnode;
			newnode->next = newnode;
			newnode->prev = head;
		}
		else
		{
			//store the addr of cur first node into the next part of newly created node
			newnode->next = head;
			//store the addr of last node into the prev part of newly created node
			newnode->prev = head->prev;
			//store the addr of newly created node into prev part of cur first node
			head->prev = newnode;
			//attach newly created node to the head
			head = newnode;
			//update next part of last node by addr of newly created node at first pos
			head->prev->next = head;

			this->cnt++;
		}
	}

	void display_list(void)
	{
		if( !is_list_empty())
		{
			node *trav = head;
			cout << "list in forward dir is : ";
			do
			{
				cout << setw(4) << left << trav->data;
				trav = trav->next;
			}while( trav != head );
			cout << endl;

			trav = head->prev;
			cout << "list in backward dir is: ";
			do
			{
				cout << setw(4) << left << trav->data;
				trav = trav->prev;
			}while( trav != head->prev );
			cout << endl;
		}
		else
			cout << "list is empty !!!" << endl;
	}

	void delete_node_at_first_position()
	{
		if( !is_list_empty() )
		{
			//if list contains only one node
			if( head == head->next )
			{
				delete head;
				head = NULL;
				this->cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//store the addr of last node into the prev part cur second node
				head->next->prev = head->prev;
				//store the addr of cur second node into the head
				head = head->next;
				//delete the first node
				delete head->prev->next;
				//update next part of last node by new first node
				head->prev->next = head;
				this->cnt--;
			}
		}
		else
			cout << "list is empty !!!" << endl;
	}
};


int main(void)
{
	list l1;

	l1.add_node_at_last_position(11);
	/*
	l1.add_node_at_last_position(22);
	l1.add_node_at_last_position(33);
	l1.add_node_at_last_position(44);
	l1.add_node_at_last_position(55);
	l1.add_node_at_last_position(66);
	*/
	l1.display_list();

	//l1.add_node_at_first_position(5);

	l1.delete_node_at_first_position();

	l1.display_list();



	return 0;
}








