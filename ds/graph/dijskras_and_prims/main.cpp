/*
 * main.cpp
 *
 *  Created on: 24-Sep-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<cstring>

#define MAX 10
#define INF 9999


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

		for( int i = 0 ; i < MAX ; i++ )
			for( int j = 0 ; j < MAX ; j++ )
				mat[i][j]=INF;

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
			int from, to, weight;

			cout << "enter an edge: from to to & weight: ";
			cin >> from >> to >> weight;

			mat[from][to] = weight;
			mat[to][from] = weight;//this line will be in comment for digraph
		}
	}

	void display_graph(void)
	{
		cout << endl << "input graph is: " << endl;
		cout << "no. of vertices are : " << vert_cnt << endl;
		cout << "no. of edges are : " << edge_cnt << endl;

		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			for( int j = 0 ; j < vert_cnt ; j++ )
			{
				if( mat[i][j] == INF )
					cout << setw(4) << left << "#";
				else
					cout << setw(4) << left << mat[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	int get_min(int dist[], bool marked[])
	{
		int min_ind = 0;
		int min_dist = INF;

		//this function returns such a vertex having min key value and which
		//not yet added into MST set of vertices i.e. unmarked
		for( int i = 0 ; i < vert_cnt ; i++ )
		{
			if( marked[i] == false && dist[i] < min_dist )
			{
				min_ind = i;
				min_dist = dist[i];
			}
		}

		return min_ind;
	}
	//algo to find shortest distance of all vertices from the given source vertex
	void dijskras(int source)
	{
		int dist[MAX];
		bool marked[MAX];
		int mst_vert_cnt = 0;

		//initially distance of all vertices from the given source vertex is INF
		//and all the vertices are unmarked i.e. MST set of vertices is empty
		//vertex is not yet added into MST set of vertices
		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			marked[v] = false;
			dist[v] = INF;
		}

		//distance of source vertex from itself is 0
		dist[ source ] = 0;

		cout << "MST SET OF VERTICES IS: { ";
		while( mst_vert_cnt < vert_cnt )
		{
			int min_key_vert = get_min(dist, marked);
			//add min_key_vert into MST set of vertices and increment the counter
			marked[ min_key_vert ] = true;
			mst_vert_cnt++;
			cout << setw(4) << left << min_key_vert;

			//update distance of all its (min_key_vert) adjacent but unmarked
			//to the min distance
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[min_key_vert][v] != INF && marked[v] == false
						&& dist[min_key_vert] + mat[min_key_vert][v] < dist[v] )
				{
					dist[v] = dist[min_key_vert] + mat[min_key_vert][v];
				}
			}
		}//end of while loop
		cout << " } " << endl;

		cout << "distance of all the vertices from given source vertex is: " << endl;
		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			cout << source << "->" << v << " : " << dist[v] << endl;
		}
	}

	void prims(int root)
	{
		int vert_key[MAX];
		bool marked[MAX];
		int parent[MAX];
		int mst_vert_cnt = 0;

		//initially key values all vertices is INF
		//and all the vertices are unmarked i.e. MST set of vertices is empty
		//vertex is not yet added into MST set of vertices
		//and -1 is parent of all vertices
		for( int v = 0 ; v < vert_cnt ; v++ )
		{
			marked[v] = false;
			vert_key[v] = INF;
			parent[v] = -1;
		}

		//key value of root vertex is 0 and root is parent of itself
		vert_key[ root ] = 0;
		parent[root] = root;

		cout << "MST SET OF VERTICES IS: { ";
		while( mst_vert_cnt < vert_cnt )
		{
			int min_key_vert = get_min(vert_key, marked);
			//add min_key_vert into MST set of vertices and increment the counter
			marked[ min_key_vert ] = true;
			mst_vert_cnt++;
			cout << setw(4) << left << min_key_vert;

			//update key value of all its (min_key_vert) adjacent but unmarked
			//to to the min and update min_key_vert as its parent
			for( int v = 0 ; v < vert_cnt ; v++ )
			{
				if( mat[min_key_vert][v] != INF && marked[v] == false
						&& mat[min_key_vert][v] < vert_key[v] )
				{
					vert_key[v] = mat[min_key_vert][v];
					parent[v] = min_key_vert;
				}
			}
		}//end of while loop
		cout << " } " << endl;

		for( int i = 1 ; i < vert_cnt ; i++ )
			cout << parent[i] << "->" << i << " : " << mat[ parent[i] ][ i ] << endl;
	}
};

int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	/*
	int source;
	cout << "enter the source vertex: ";
	cin >> source;

	g1.dijskras(source);
	*/

	int root;
	cout << "enter the root vertex: ";
	cin >> root;

	g1.prims(root);

	return 0;
}











