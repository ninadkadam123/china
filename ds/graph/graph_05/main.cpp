/*
 * main.cpp
 *
 *  Created on: 24-Sep-2019
 *      Author: sunbeam
 */

//undirected un-weighted
#include<iostream>
using namespace std;
#include<iomanip>
#include<cstring>
#include<stack>

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

	void dfs_traversal(int start)
	{
		stack<int> s;
		bool marked[MAX];
		//initially all the vertices are unmarked
		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			marked[v] = false;
		}

		//1. push starting vertex into the stack and mark it
		s.push(start);
		marked[start] = true;
		cout << "DFS TRAVERSAL IS: ";
		while( !s.empty() )
		{
			//2. pop vertex/ele from the stack and visit it
			int trav = s.top(); s.pop();
			cout << setw(4) << left << trav;

			//3. push all its adjacent but unmarked vertices into the stack and mark them
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
				}
			}
		}//4. repeat steps 2 & 3 till stack not becomes empty
		cout << endl;

	}
};

int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	g1.dfs_traversal(0);

	return 0;
}








