/*
 * main.cpp
 *
 *  Created on: 24-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<vector>
#include<list>


class graph
{
private:
	vector<list<int>> gr;
	int vert_cnt;
	int edge_cnt;
public:
	graph(void)
	{
		this->vert_cnt = 0;
		this->edge_cnt = 0;
	}

	void accept_graph(void)
	{
		cout << "enter no. of vertices: ";
		cin >> vert_cnt;

		cout << "enter no. of edges: ";
		cin >> edge_cnt;

		//add vert_cnt no. of empty list objects into the vector "gr"
		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			list<int> empty_list;
			gr.push_back(empty_list);
		}

		for( int i = 0 ; i < edge_cnt ; i++ )
		{
			int from, to;
			cout << "enter an edge: from to to: ";
			cin >> from >> to;
			gr[from].push_back(to);
			gr[to].push_back(from);//this line will be in comment for digraph
		}
	}

	void display_graph(void)
	{
		cout << endl;
		cout << "no. of vertices are: " << vert_cnt << endl;
		cout << "no. of edges are: " << edge_cnt << endl;
		cout << endl << "input graph is: " << endl;

		list<int>::iterator itr;

		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			cout << "[ " << i << " ] => ";
			for( itr = gr[i].begin() ; itr != gr[i].end() ; itr++ )
			{
				cout << *itr << " -> ";
			}
			cout << "null" << endl;
		}
	}
};

int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	return 0;
}


