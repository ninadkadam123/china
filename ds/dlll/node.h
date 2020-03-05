/*
 * node.h
 *
 *  Created on: 21-Sep-2019
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_

class list;

class node
{
private:
	node *prev;
	int data;
	node *next;
public:
	node(int data);
	friend class list;

};


#endif /* NODE_H_ */
