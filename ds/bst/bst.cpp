/*
 * bst.cpp
 *
 *  Created on: 10-Oct-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include"bst.h"
#include<stack>
#include<queue>

bst :: bst(void)
{
	this->root = NULL;
}

bool bst :: bst_empty(void)
{
	return ( this->root == NULL );
}

void bst :: rec_add_node(int data, node *trav)
{
	if( data < trav->data )
	{
		if( trav->left == NULL )
			trav->left = new node(data);
		else
			rec_add_node(data, trav->left);
	}
	else
	{
		if( trav->right == NULL )
			trav->right = new node(data);
		else
			rec_add_node(data, trav->right);
	}
}

void bst :: rec_add_node(int data)
{
	if( bst_empty())
		root = new node(data);
	else
		rec_add_node(data, root);
}

void bst :: add_node(int data)
{
	//create a newnode
	node *newnode = new node(data);

	//if bst is empty -- attach newly created node to the root pointer
	if( bst_empty() )
	{
		this->root = newnode;
	}
	else
	{
		//find an appropriate position of the node
		//start traversal from the root node
		node *trav = root;

		while(1)
		{
			if( data < trav->data )//data will be a part of its left sub tree
			{
				if( trav->left == NULL )//if left sub tree of the cur node is empty
				{
					trav->left = newnode;//attach newly created node as its left child
					break;
				}
				else
					trav = trav->left;//goto its left sub tree
			}
			else//data will be a part of its right sub tree
			{
				if( trav->right == NULL )//if right sub tree of the cur node is empty
				{
					trav->right = newnode;//attach newly created node as its right child
					break;
				}
				else
					trav = trav->right;//goto its right sub tree
			}
		}//end of while loop
	}//end of else
}

void bst :: preorder(void)
{
	if( !bst_empty())
	{
		cout << "PREORDER : ";
		preorder(root);
		cout << endl;
	}
}

void bst :: preorder(node *trav)
{
	if( trav == NULL )
		return;
	//VLR
	cout << setw(4) << left << trav->data;
	preorder(trav->left);
	preorder(trav->right);
}

void bst :: inorder(void)
{
	if( !bst_empty())
	{
		cout << "INORDER  : ";
		inorder(root);
		cout << endl;
	}

}

void bst :: inorder(node *trav)
{
	if( trav == NULL )
		return;
	//LVR
	inorder(trav->left);
	cout << setw(4) << left << trav->data;
	inorder(trav->right);
}

void bst :: postorder(void)
{
	if( !bst_empty())
	{
		cout << "POSTORDER: ";
		postorder(root);
		cout << endl;
	}
}

void bst :: postorder(node *trav)
{
	if( trav == NULL )
		return;
	//LRV
	postorder(trav->left);
	postorder(trav->right);
	cout << setw(4) << left << trav->data;
}

bst :: ~bst(void)
{
	if( !bst_empty())
	{
		clear(root);
		cout << "BST freed sucessfully..." << endl;
	}
}

void bst :: clear(node *trav)
{
	if( trav == NULL )
		return;

	clear(trav->left);
	clear(trav->right);
	delete trav;
}


void bst :: nonrec_preorder(void)
{
	node *trav = root;

	if( trav == NULL )
		return;

	stack<node *> s;
	cout << "PREORDER : ";
	while( trav != NULL || !s.empty() )
	{
		while( trav != NULL )
		{
			//visit the node
			cout << setw(4) << left << trav->data;

			//if the cur node is having right child push it into the stack
			if( trav->right != NULL )
				s.push(trav->right);

			//goto its left subtree
			trav = trav->left;
 		}

		//if stack is not empty
		if( !s.empty() )
		{
			//pop ele i.e. addr of the node from the stack
			trav = s.top(); s.pop();
		}
	}//end of outer while loop
	cout << endl;
}

void bst :: nonrec_inorder(void)
{
	node *trav = root;

	if( trav == NULL )
		return;

	stack<node *> s;
	cout << "INORDER  : ";
	while( trav != NULL || !s.empty() )
	{
		while( trav != NULL )
		{
			//push cur node into the stack
			s.push(trav);

			//goto its left subtree
			trav = trav->left;
 		}

		//if stack is not empty
		if( !s.empty() )
		{
			//pop ele i.e. addr of the node from the stack
			trav = s.top(); s.pop();

			//visit the node
			cout << setw(4) << left << trav->data;

			//goto its right sub tree
			trav = trav->right;
		}
	}//end of outer while loop
	cout << endl;
}

void bst :: nonrec_postorder(void)
{
	node *trav = root;

	if( trav == NULL )
		return;

	stack<node *> s;
	cout << "POSTORDER: ";
	while( trav != NULL || !s.empty() )
	{
		while( trav != NULL )
		{
			//push cur node into the stack
			s.push(trav);

			//goto its left subtree
			trav = trav->left;
 		}

		//if stack is not empty
		if( !s.empty() )
		{
			//pop ele i.e. addr of the node from the stack
			trav = s.top(); s.pop();

			//if the cur node is having right sub tree and is not visited
			if( trav->right != NULL && trav->right->visited == false )
			{
				//push the cur node into the stack
				s.push(trav);
				//goto its right sub tree
				trav = trav->right;
			}
			else
			{
				//visit the node
				cout << setw(4) << left << trav->data;
				//mark the node as visited
				trav->visited = true;
				trav = NULL;
			}
		}
	}//end of outer while loop
	cout << endl;
}

void bst :: dfs_traversal(void)
{
	node *trav = root;
	if( trav == NULL )
		return;

	stack<node *> s;
	//step1: push the root node into the stack
	s.push(root);

	cout << "DFS TRAVERSAL IS: ";
	while( !s.empty() )
	{
		//step2: pop the node from the stack and visit it
		trav = s.top(); s.pop();
		cout << setw(4) << left << trav->data;
		//step3: if the cur node is having right child push it into the stack
		if( trav->right != NULL )
			s.push(trav->right);
		//step4: if the cur node is having left child push it into the stack
		if( trav->left != NULL )
			s.push(trav->left);
	}//step5: repeat step2, step3 & step4 till stack not becomes empty
	cout << endl;
}

void bst :: bfs_traversal(void)
{
	node *trav = root;

	if( trav == NULL )
		return;

	queue<node *> q;
	//step1: push the root node into the queue
	q.push(root);

	cout << "BFS TRAVERSAL IS: ";
	while( !q.empty() )
	{
		//step2: pop the node from the queue and visit it
		trav = q.front(); q.pop();
		cout << setw(4) << left << trav->data;

		//step3: if the cur node is having left child push it into the queue
		if( trav->left != NULL )
			q.push(trav->left);

		//step4: if the cur node is having right child push it into the queue
		if( trav->right != NULL )
			q.push(trav->right);

	}//step5: repeat step2, step3 & step4 till queue not becomes empty
	cout << endl;

}

node *bst :: search_node(int key, node **parent)
{
	node *trav = root;

	*parent = NULL;

	while( trav != NULL )
	{
		if( key == trav->data )
			return trav;

		*parent = trav;

		if( key < trav->data )
			trav = trav->left;
		else
			trav = trav->right;
	}

	*parent = NULL;
	return NULL;
}

bool bst :: delete_node(int key)
{
	node *parent = NULL;
	//search node -- on success this function returns addr of node to be deleted
	//as well as addr of its parent node
	node *temp = search_node(key, &parent);

	//if node not found return false
	if( temp == NULL )
		return false;

	//if node is found/exists =>
	//node is having left sub tree as well as right subtree
	if( temp->left != NULL && temp->right != NULL )
	{
		//traverse till its inorder succ
		node *succ = temp->right;
		parent = temp;

		while( succ->left != NULL )
		{
			parent = succ;
			succ = succ->left;
		}
		//copy data of succ into temp
		temp->data = succ->data;
		temp = succ;
	}

	//if temp->left == NULL
	if( temp->left == NULL )
	{
		if( temp == root )
			root = temp->right;
		else
		if( temp == parent->left )
			parent->left = temp->right;
		else
			parent->right = temp->right;
	}
	else//if( temp->right == NULL )
	{
		if( temp == root )
			root = temp->left;
		else
		if( temp == parent->left )
			parent->left = temp->left;
		else
			parent->right = temp->left;
	}

	delete temp;
	return true;
}

/*
bool bst :: delete_node(int key)
{
	node *parent = NULL;
	node *temp = search_node(key, &parent);

	if( temp == NULL )
		return false;

	if( parent == NULL )
		cout << "temp->data: " << temp->data << endl;
	else
		cout << "parent->data: " << parent->data << "\t" << "temp->data: " << temp->data << endl;
}
*/

int bst :: height(void)
{
	if( !bst_empty() )
		return ( height(root) );
}

int bst :: height(node *trav)
{
	if( trav == NULL )
		return 0;

	return ( max( height(trav->left), height(trav->right) ) + 1 );
}

void bst :: balance(void)
{
	if( !bst_empty() )
		balance(root, NULL);
}

node *bst :: left_rotation(node *axis, node *parent)
{
	if( axis == NULL || axis->right == NULL )
		return NULL;

	node *newaxis = axis->right;
	axis->right = newaxis->left;
	newaxis->left = axis;

	if( axis == root )
		root = newaxis;
	else
	if( axis == parent->left )
		parent->left = newaxis;
	else
		parent->right = newaxis;

	return newaxis;
}

node *bst :: right_rotation(node *axis, node *parent)
{
	if( axis == NULL || axis->left == NULL )
		return NULL;

	node *newaxis = axis->left;
	axis->left = newaxis->right;
	newaxis->right = axis;

	if( axis == root )
		root = newaxis;
	else
	if( axis == parent->left )
		parent->left = newaxis;
	else
		parent->right = newaxis;

	return newaxis;
}

void bst :: balance(node *trav, node *parent)
{
	if( trav == NULL )
		return;

	int bf = height(trav->left) - height(trav->right);
	//cur node is not balanced
	while( bf < -1 || bf > +1 )
	{
		if( bf < -1 )//node is left imbalanced
		{
			trav = left_rotation(trav, parent);
			bf += 2;
		}
		else//node is right imbalanced
		{
			trav = right_rotation(trav, parent);
			bf -= 2;
		}
	}

	balance(trav->left, trav);
	balance(trav->right, trav);
}
















