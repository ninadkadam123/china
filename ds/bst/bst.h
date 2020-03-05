/*
 * bst.h
 *
 *  Created on: 10-Oct-2019
 *      Author: sunbeam
 */

#ifndef BST_H_
#define BST_H_

#include"node.h"

class bst
{
private:
	node *root;
public:
	bst(void);
	bool bst_empty(void);
	void add_node(int data);
	void rec_add_node(int data, node *trav);
	void rec_add_node(int data);
	void preorder(void);
	void preorder(node *trav);
	void inorder(void);
	void inorder(node *trav);
	void postorder(void);
	void postorder(node *trav);
	void nonrec_preorder(void);
	void nonrec_inorder(void);
	void nonrec_postorder(void);
	void dfs_traversal(void);
	void bfs_traversal(void);
	bool delete_node(int key);
	node *search_node(int key, node **parent);
	int height(void);
	int height(node *trav);
	void balance(void);
	void balance(node *trav, node *parent);
	node *left_rotation(node *axis, node *parent);
	node *right_rotation(node *axis, node *parent);
	~bst(void);
private:
	void clear(node *trav);
};



#endif /* BST_H_ */
