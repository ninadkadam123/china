/*
 * node.h
 *
 *  Created on: 10-Oct-2019
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_

class bst;

class node
{
private:
	int data;
	node *left;
	node *right;
	bool visited;
public:
	node(int data);

	friend class bst;
};



#endif /* NODE_H_ */
