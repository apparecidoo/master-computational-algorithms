#include <iostream>
#include "djikstra.h"
#include "prim.h"
#include "helper.h"
#include "random.h"
#include <chrono>
#include <string>

#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

class Graph {
private:
	int** _graph;
	int _startVertex;
	int _numberVertices;
	int _numberEdges;

	void Initialize();

public:
	Graph(int** graph, int graphSize, int startVertex = 0);
	Graph(int graphSize, int startVertex = 0);
	void AddEdge(int from = 0, int to = 0, int weight = 0, bool undirected = true);

	int* RunPrim();
	void TestPrim();
	
	int* RunDijkstra();
	void TestDijkstra();
};

#endif