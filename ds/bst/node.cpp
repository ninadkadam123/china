/*
 * node.cpp
 *
 *  Created on: 10-Oct-2019
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;

#include"node.h"

node :: node(int data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
	this->visited = false;//are not visited
}


