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

class edge
{
private:
	int v;
	int w;
public:
	edge(int v=0, int w=0)
	{
		this->v = v;
		this->w = w;
	}

	friend ostream& operator<<( ostream& out, edge& other )
	{
		out << other.v << " : " << other.w;
		return out;
	}

};

class graph
{
private:
	vector<list<edge>> gr;
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
			list<edge> empty_list;
			gr.push_back(empty_list);
		}

		for( int i = 0 ; i < edge_cnt ; i++ )
		{
			int from, to, weight;
			cout << "enter an edge: from to to & weight: ";
			cin >> from >> to >> weight;

			edge ed1(to, weight);
			gr[from].push_back(ed1);

			edge ed2(from, weight);
			gr[to].push_back(ed2);
		}
	}

	void display_graph(void)
	{
		cout << endl;
		cout << "no. of vertices are: " << vert_cnt << endl;
		cout << "no. of edges are: " << edge_cnt << endl;
		cout << endl << "input graph is: " << endl;

		list<edge>::iterator itr;

		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			cout << "[ " << i << " ] => ";
			for( itr = gr[i].begin() ; itr != gr[i].end() ; itr++ )
			{
				cout << " | " << *itr << " | " << " -> ";
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






