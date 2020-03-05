/*
 * main.cpp
 *
 *  Created on: 21-Sep-2019
 *      Author: sunbeam
 */


#include"list.h"

int main(void)
{
	list l1;


	l1.add_node_at_last_position(10);
	l1.add_node_at_last_position(20);
	l1.add_node_at_last_position(30);
	l1.add_node_at_last_position(40);
	l1.add_node_at_last_position(50);
	l1.add_node_at_last_position(60);
	l1.add_node_at_last_position(70);
	l1.add_node_at_last_position(80);


	l1.display_list();

	//l1.delete_node_at_first_position();
	//l1.add_node_at_specific_position(99, 6);

	//l1.add_node_at_first_position(5);

	l1.delete_node_at_specific_position(5);

	l1.display_list();



	return 0;
}

