/*
 * node.h
 *
 *  Created on: 21-Sep-2019
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_

//forward declaration
class list;

class node
{
private:
	int data;//4 bytes
	node *next;//4 bytes
public:
	node(int data);
	friend class list;
};

#endif /* NODE_H_ */
