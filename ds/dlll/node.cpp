/*
 * node.cpp
 *
 *  Created on: 21-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<cstdlib>
#include"node.h"

node::node(int data)
{
	this->prev = NULL;
	this->data = data;
	this->next = NULL;
}




