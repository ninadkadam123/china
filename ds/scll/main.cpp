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
#include"list.h"


enum menu_options{ EXIT, ADDLAST, ADDFIRST, ADDATPOS, DELFIRST, DELLAST,
DELATPOS, DISP };

int menu(void)
{
	int choice;

	cout << "SINGLY CIRCULAR LINKED LIST" << endl;
	cout << "0. EXIT" << endl;
	cout << "1. ADDLAST" << endl;
	cout << "2. ADDFIRST" << endl;
	cout << "3. ADDATPOS" << endl;
	cout << "4. DELFIRST" << endl;
	cout << "5. DELLAST" << endl;
	cout << "6. DELATPOS" << endl;
	cout << "7. DISP" << endl;

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

			//l1.add_node_at_specific_pos(data, pos);
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
			//l1.delete_node_at_specific_position(pos);
			break;

		case DISP:
			l1.display_list();
			break;
		}//end of switch control block
	}//end of while loop
	return 0;
}





