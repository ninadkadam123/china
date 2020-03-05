/*
 * main.cpp
 *
 *  Created on: 24-Sep-2019
 *      Author: sunbeam
 */

//undirected unweighted
#include<iostream>
using namespace std;
#include<iomanip>
#include<cstring>

#define MAX 10


class graph
{
private:
	int mat[MAX][MAX];
	int vert_cnt;
	int edge_cnt;
public:
	graph(void)
	{
		this->vert_cnt = 0;
		this->edge_cnt = 0;
		memset(mat, 0, sizeof(mat));
		/*
		for( int i = 0 ; i < MAX ; i++ )
			for( int j = 0 ; j < MAX ; j++ )
				mat[i][j]=0;
		*/
	}

	void accept_graph(void)
	{
		cout << "enter no. of vertices: ";
		cin >> this->vert_cnt;

		cout << "enter no. of edges: ";
		cin >> this->edge_cnt;

		//accept edge_cnt no. of pairs of vertices from user
		for( int i = 0 ; i < edge_cnt ; i++ )
		{
			int from, to;

			cout << "enter an edge: from to to: ";
			cin >> from >> to;

			mat[from][to] = 1;
			mat[to][from] = 1;//this line will be in comment for digraph
		}
	}

	void display_graph(void)
	{
		cout << endl << "input graph is: " << endl;
		cout << "no. of vertices are 	: " << vert_cnt << endl;
		cout << "no. of edges are		: " << edge_cnt << endl;

		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			for( int j = 0 ; j < vert_cnt ; j++ )
			{
				cout << setw(4) << left << mat[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	return 0;
}




