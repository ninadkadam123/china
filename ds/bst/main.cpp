/*
 * main.cpp
 *
 *  Created on: 10-Oct-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include"bst.h"

int main(void)
{
	bst t1;
	//50 20 90 85 10 45 30 100 15 75 95 120 5 50
	/*
	t1.add_node(50);
	t1.add_node(20);
	t1.add_node(90);
	t1.add_node(85);
	t1.add_node(10);
	t1.add_node(45);
	t1.add_node(30);
	t1.add_node(100);
	t1.add_node(15);
	t1.add_node(75);
	t1.add_node(95);
	t1.add_node(120);
	t1.add_node(5);
	t1.add_node(50);
	*/

	t1.rec_add_node(10); t1.rec_add_node(20); t1.rec_add_node(30);
	t1.rec_add_node(40); t1.rec_add_node(50); t1.rec_add_node(60);
	t1.rec_add_node(70);


	t1.preorder();
	//t1.nonrec_preorder();
	t1.inorder();
	//t1.nonrec_inorder();

	t1.postorder();
	//t1.nonrec_postorder();

	t1.dfs_traversal();
	t1.bfs_traversal();

	cout << "height of of t1 is: " << t1.height() << endl;
	/*
	int key;
	cout << "enter the key to delete: ";
	cin >> key;

	if( t1.delete_node(key) )
		cout << key << " deleted from the BST ..." << endl;
	else
		cout << key << " not found in a BST !!!" << endl;

	t1.preorder();
	t1.inorder();
	t1.postorder();
	*/
	cout << "---------- after balance()-------------" << endl;
	t1.balance();	cout << "height of of t1 is: " << t1.height() << endl;
	t1.preorder();
	t1.inorder();
	t1.postorder();
	t1.dfs_traversal();
	t1.bfs_traversal();


	return 0;
}


