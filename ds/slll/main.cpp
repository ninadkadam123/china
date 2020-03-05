/*
 * main.cpp
 *
 *  Created on: 19-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<cstdlib>

//forward declaration
class list;

class node
{
private:
	int data;//4 bytes
	node *next;//4 bytes
public:
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	friend class list;
};

class list
{
private:
	node *head;//4 bytes
	int cnt;
public:
	list()
	{
		this->head = NULL;
		this->cnt = 0;
	}

	bool is_list_empty()
	{
		return ( this->head == NULL );
	}

	int get_cnt(void)
	{
		return ( this->cnt );
	}

	int count_nodes(void)
	{
		int cnt = 0;
		//start traversal from the first node
		node *trav = head;
		//travers the list till last node
		while( trav != NULL )
		{
			cnt++;//increment the cnt by 1
			trav = trav->next;//move to the next node
		}
		return cnt;//return the value of cnt to the calling function
	}

	void add_node_at_last_position(int data)
	{
		//create a newnode
		node *newnode = new node(data);

		//if list is empty -- attach newly created node to the head
		if( is_list_empty())
		{
			//store the addr of newly created node into the head
			head = newnode;
			this->cnt++;
		}
		else//if list is not empty
		{
			//start traversal from the first node
			node *trav = head;

			//traverse the list till last node
			while( trav->next != NULL )
			{
				trav = trav->next;//move trav pointer to its next node
			}

			//attach newly created to the last node i.e.
			//store the addr of newly created node into the next part of last node
			trav->next = newnode;
			this->cnt++;
		}
	}

	void add_node_at_first_position(int data)
	{
		//create a newnode
		node *newnode = new node(data);

		//if list is empty -- attach newly created node to the head
		if( is_list_empty())
		{
			//store the addr of newly created node into the head
			head = newnode;
			this->cnt++;
		}
		else//if list is not empty
		{
			//store the addr of cur first node into the next part of newly created node
			newnode->next = head;
			//attach newly created node to the head
			head = newnode;
			this->cnt++;
		}
	}

	void add_node_at_specific_pos(int data, int pos)
	{
		if( pos == 1 )
			add_node_at_first_position(data);
		else
		if( pos == get_cnt() + 1 )
			add_node_at_last_position(data);
		else//if pos is in between pos
		{
			//create a newnode
			node *newnode = new node(data);

			//start traversal from the first node
			node *trav = head;
			int i = 1;
			//traverse the list till (pos-1)th node
			while( i < pos-1 )
			{
				i++;
				trav = trav->next;
			}

			//store the addr of cur (pos)th node into the next part of newly created node
			newnode->next = trav->next;
			//store the addr of newly created node into the next part of (pos-1)th node
			trav->next = newnode;
			this->cnt++;
		}
	}

	void delete_node_at_first_position(void)
	{
		//if list is not empty
		if( !is_list_empty())
		{
			//if list contains only one node
			if( head->next == NULL )
			{
				//delete the node and make head as NULL & cnt as 0
				delete head;
				head = NULL;
				cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//store the addr of cur first node into the temp
				node *temp = head;
				//store the addr of cur second node into the head
				head = head->next;
				//delete the node
				delete temp;
				temp = NULL;
				cnt--;
			}
		}
		else
			cout << "list is empty !!!" << endl;
	}

	void delete_node_at_last_position(void)
	{
		//if list is not empty
		if( !is_list_empty())
		{
			//if list contains only one node
			if( head->next == NULL )
			{
				//delete the node and make head as NULL & cnt as 0
				delete head;
				head = NULL;
				cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//start traversal from the first node
				node *trav = head;
				//traverse list till second last node
				while( trav->next->next != NULL )
					trav = trav->next;

				//delete the last node
				delete trav->next;
				//make next part of cur second last node as NULL
				trav->next = NULL;
				this->cnt--;
			}
		}
		else
			cout << "list is empty !!!" << endl;
	}

	void display_list(void)
	{
		//if list is not empty
		if( !is_list_empty() )
		{
			//cout << "no. of nodes in a list are: " << count_nodes() << endl;
			cout << "no. of nodes in a list are: " << get_cnt() << endl;
			cout << "list is: head -> ";
			//start list traversal from the first node
			node *trav = head;
			//traverse the list till last node
			while( trav != NULL )
			{
				cout << trav->data << " -> ";
				trav = trav->next;
			}
			cout << "null" << endl;
		}
		else
		{
			cout << "list is empty !!!" << endl;
		}
	}

	void delete_node_at_specific_position(int pos)
	{
		if( pos == 1 )
			delete_node_at_first_position();
		else
		if( pos == get_cnt() )
			delete_node_at_last_position();
		else//pos is in between pos
		{
			//start traversal from first node
			node *trav = head;
			int i = 1;
			//traverse the list till (pos-1)th node
			while( i < pos-1 )
			{
				i++;
				trav = trav->next;
			}
			//store the addr of node which is to be deleted in a temp
			node *temp = trav->next;
			//store the addr of cur (pos+1)th into the next part of (pos-1)th node
			trav->next = trav->next->next;
			//delete the node
			delete temp;
			temp = NULL;
			this->cnt--;
		}
	}

	void display_reverse(node *trav)
	{
		if( trav == NULL )
			return;
		display_reverse(trav->next);
		cout << setw(4) << left << trav->data;
	}

	void display_reverse(void)//wrapper function
	{
		if( !is_list_empty())
		{
			cout << "list in reverse order is: ";
			display_reverse(head);
			cout << endl;
		}
		else
			cout << "list is empty !!!" << endl;
 	}

	void reverse_list(void)
	{
		node *t1 = head;
		node *t2 = t1->next;
		t1->next = NULL;

		while( t2 != NULL )
		{
			node *t3 = t2->next;
			t2->next = t1;
			t1 = t2;//move t1 pointer to its next node
			t2 = t3;//move t2 pointer to its next node
		}
		head = t1;
	}

private:
	void free_list(void)
	{
		if( !is_list_empty() )
		{
			while( !is_list_empty())
				delete_node_at_last_position();

				//delete_node_at_first_position();

			cout << "list freed successfully..." << endl;

		}
	}
public:
	~list()
	{
		cout << "inside dtor..." << endl;
		free_list();
	}
};


enum menu_options{ EXIT, ADDLAST, ADDFIRST, ADDATPOS, DELFIRST, DELLAST,
DELATPOS, DISP, DISPREV, REVERSE };

int menu(void)
{
	int choice;

	cout << "SINGLY LINEAR LINKED LIST" << endl;
	cout << "0. EXIT" << endl;
	cout << "1. ADDLAST" << endl;
	cout << "2. ADDFIRST" << endl;
	cout << "3. ADDATPOS" << endl;
	cout << "4. DELFIRST" << endl;
	cout << "5. DELLAST" << endl;
	cout << "6. DELATPOS" << endl;
	cout << "7. DISP" << endl;
	cout << "8. DISPREV" << endl;
	cout << "9. REVERSE" << endl;

	cout << "ENTER THE CHOICE: ";
	cin >> choice;
	return choice;
}

int main(void)
{
	list l1;
	int choice;
	int data;
	int pos;

	while(1)
	{
		choice = menu();
		switch(choice)
		{
		case EXIT:
			l1.~list();
			exit(0);
		case ADDLAST:
			cout << "enter the data: ";
			cin >> data;
			l1.add_node_at_last_position(data);
			break;
		case ADDFIRST:
			cout << "enter the data: ";
			cin >> data;
			l1.add_node_at_first_position(data);
			break;
		case ADDATPOS:
			while(1)
			{
				//accapt the pos
				cout << "enter the pos: ";
				cin >> pos;

				//check pos is valid or not
				if( pos >= 1 && pos <= l1.get_cnt() + 1 )
					break;

				cout << "invalid pos" << endl;
			}

			l1.add_node_at_specific_pos(data, pos);
			break;
		case DELFIRST:
			l1.delete_node_at_first_position();
			break;
		case DELLAST:
			l1.delete_node_at_last_position();
			break;
		case DELATPOS:
			while(1)
			{
				//accept the pos
				cout << "enter the pos: ";
				cin >> pos;

				//check pos is valid or not
				if( pos >= 1 && pos <= l1.get_cnt())
					break;

				cout << "invalid pos" << endl;
			}
			l1.delete_node_at_specific_position(pos);
			break;

		case DISP:
			l1.display_list();
			break;
		case DISPREV:
			l1.display_reverse();
			break;
		case REVERSE:
			l1.reverse_list();
			cout << "list reversed successfully..." << endl;
			break;
		}//end of switch control block
	}//end of while loop


	/*
	l1.add_node_at_last_position(10);
	l1.add_node_at_last_position(20);
	l1.add_node_at_last_position(30);
	l1.add_node_at_last_position(40);
	l1.add_node_at_last_position(50);
	l1.add_node_at_last_position(60);

	l1.display_list();

	//l1.delete_node_at_first_position();
	//l1.delete_node_at_last_position();

	//l1.add_node_at_first_position(5);
	int pos;


	l1.delete_node_at_specific_position(pos);

	//if pos is valid then only go for adding node at that pos
	//l1.add_node_at_specific_pos(99, pos);


	l1.display_list();
	*/

	return 0;
}

