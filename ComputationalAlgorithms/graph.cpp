#include "pch.h"
#include "graph.h"

Graph::Graph(int** graph, int graphSize, int startVertex)
{
	_graph = graph;
	_graphSize = graphSize;
	_startVertex = startVertex;
}

Graph::Graph(int graphSize, int startVertex)
{
	_graphSize = graphSize;
	_startVertex = startVertex;	
	Initialize();
}

void Graph::AddEdge(int from, int to, int weight, bool undirected)
{
	_graph[from][to] = weight;
	
	if (undirected) {
		_graph[to][from] = weight;
	}
}

void Graph::Initialize()
{
	_graph = new int*[_graphSize];
	for (int i = 0; i < _graphSize; i++)
	{
		_graph[i] = new int[_graphSize];
	}

	for (int i = 0; i < _graphSize; i++)
	{
		for (int j = 0; j < _graphSize; j++)
		{
			_graph[i][j] = NULL;
		}
	}
}

int * Graph::RunPrim()
{
	Prim<int>* prim = new Prim<int>(_graph, _graphSize, _startVertex);
	return prim->Run();
}

void Graph::TestPrim()
{
	// class example
	this->_graphSize = 8;
	Initialize();
	AddEdge(0, 1, 14);
	AddEdge(0, 2, 3);
	AddEdge(1, 3, 6);
	AddEdge(1, 2, 10);
	AddEdge(1, 4, 5);
	AddEdge(2, 5, 8);
	AddEdge(3, 4, 4);
	AddEdge(4, 5, 2);
	AddEdge(4, 6, 9);
	AddEdge(5, 7, 15);

	int* vResult = this->RunPrim();
	Prim<int>(NULL, 0, 0).Print(vResult);
}

int * Graph::RunDijkstra()
{
	Dijkstra<int>* djk = new Dijkstra<int>(_graph, _graphSize, _startVertex);
	return djk->Run();
}

void Graph::TestDijkstra()
{
	// class example
	this->_graphSize = 5;
	Initialize();
	AddEdge(0, 1, 10, false);
	AddEdge(0, 2, 5, false);
	AddEdge(1, 2, 2, false);
	AddEdge(1, 3, 1, false);
	AddEdge(2, 1, 3, false);
	AddEdge(2, 3, 9, false);
	AddEdge(2, 4, 2, false);
	AddEdge(3, 4, 4, false);
	AddEdge(4, 0, 7, false);
	AddEdge(4, 3, 6, false);
	
	int* vResult = this->RunDijkstra();
	Dijkstra<int>(NULL, 0, 0).Print(vResult);
}