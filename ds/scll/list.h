/*
 * list.h
 *
 *  Created on: 21-Sep-2019
 *      Author: sunbeam
 */

#ifndef LIST_H_
#define LIST_H_

#include"node.h"

class list
{
private:
	node *head;//4 bytes
	int cnt;
public:
	list(void);
	bool is_list_empty(void);
	int get_cnt(void);
	void add_node_at_last_position(int data);
	void add_node_at_first_position(int data);
	void delete_node_at_first_position(void);
	void delete_node_at_last_position(void);
	void display_list(void);
};

#endif /* LIST_H_ */
