#include "pch.h"
#include "graph.h"

Graph::Graph(int** graph, int numberVertices, int startVertex)
{
	_graph = graph;
	_numberVertices = numberVertices;
	_startVertex = startVertex;
	_numberEdges = 0;
}

Graph::Graph(int numberVertices, int startVertex)
{
	_numberVertices = numberVertices;
	_startVertex = startVertex;
	_numberEdges = 0;
	Initialize();
}

void Graph::AddEdge(int from, int to, int weight, bool undirected)
{
	_graph[from][to] = weight;
	_numberEdges++;
	
	if (undirected) {
		_graph[to][from] = weight;
		_numberEdges++;
	}
}

void Graph::Initialize()
{
	_numberEdges = 0;
	_graph = new int*[_numberVertices];
	for (int i = 0; i < _numberVertices; i++)
	{
		_graph[i] = new int[_numberVertices];
	}

	for (int i = 0; i < _numberVertices; i++)
	{
		for (int j = 0; j < _numberVertices; j++)
		{
			_graph[i][j] = NULL;
		}
	}
}

int * Graph::RunPrim()
{
	Prim<int>* prim = new Prim<int>(_graph, _numberVertices, _startVertex);
	return prim->Run();
}

void Graph::TestPrim()
{
	cout << "==== Test Prim ====" << endl;

	// class example
	/*this->_graphSize = 8;
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
	Prim<int>(NULL, 0, 0).Print(vResult);*/

	string vSparseDense[2] = { "dense", "sparse" };
	string vDirectionalUndirectional[2] = { "directional", "undirectional" };
	int runTimes = 10;
	int runEachTimes = 500;
	std::chrono::time_point<chrono::steady_clock> tStart;
	this->_numberVertices = 200;

	for (int d = 0; d < 2; d++) // directional and undirectional
	{
		for (int s = 0; s < 2; s++) // sparse and dense
		{
			cout << vSparseDense[s] << " graph - " << vDirectionalUndirectional[d] << endl;

			for (int i = 0; i < runTimes; i++)
			{
				// start build graph
				this->_numberVertices += 200;
				Initialize();
				for (int r = 0; r < this->_numberVertices; r++)
				{
					for (int c = 0; c < this->_numberVertices; c++)
					{
						if (d == 0) { // directional
							if (s == 0) { // sparse
								if (r % 3 == 0 || r % 2 != 0) { // add if r % 3 = 0 and if is odd
									AddEdge(r, c, Random().generate(1, 1000), false);
								}
							}
							else { // dense
								AddEdge(r, c, Random().generate(1, 1000), false);
							}
						}
						else { // undirectional
							if (_graph[r][c] == NULL) {
								if (s == 0) { // sparse
									if (r % 3 == 0 || r % 2 != 0) { // add if r % 3 = 0 and if is odd
										AddEdge(r, c, Random().generate(1, 1000), true);
									}
								}
								else { // dense
									AddEdge(r, c, Random().generate(1, 1000), true);
								}
							}
						}
					}
				}
				// end build graph

				tStart = std::chrono::high_resolution_clock::now();
				for (int j = 0; j < runEachTimes; j++)
				{
					RunPrim();
				}
				cout << i << " - " << _numberVertices << " - " << _numberEdges << " - "<< std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - tStart).count() << endl;
			}
		}
	}

	cout << endl << endl;
}

int * Graph::RunDijkstra()
{
	Dijkstra<int>* djk = new Dijkstra<int>(_graph, _numberVertices, _startVertex);
	return djk->Run();
}

void Graph::TestDijkstra()
{
	cout << "==== Test Dijkstra ====" << endl;
	// class example
	/*this->_graphSize = 5;
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
	Dijkstra<int>(NULL, 0, 0).Print(vResult);*/

	string vSparseDense[2] = { "dense", "sparse" };
	string vDirectionalUndirectional[2] = { "directional", "undirectional" };
	int runTimes = 10;
	int runEachTimes = 500;
	std::chrono::time_point<chrono::steady_clock> tStart;
	this->_numberVertices = 200;

	for (int d = 0; d < 2; d++) // directional and undirectional
	{
		for (int s = 0; s < 2; s++) // sparse and dense
		{
			cout << vSparseDense[s] << " graph - " << vDirectionalUndirectional[d] << endl;

			for (int i = 0; i < runTimes; i++)
			{
				// start build graph
				this->_numberVertices += 200;
				Initialize();
				for (int r = 0; r < this->_numberVertices; r++)
				{
					for (int c = 0; c < this->_numberVertices; c++)
					{
						if (d == 0) { // directional
							if (s == 0) { // sparse
								if (r % 3 == 0 || r % 2 != 0) { // add if r % 3 = 0 and if is odd
									AddEdge(r, c, Random().generate(1, 1000), false);
								}
							}
							else { // dense
								AddEdge(r, c, Random().generate(1, 1000), false);
							}
						}
						else { // undirectional
							if (_graph[r][c] == NULL) {
								if (s == 0) { // sparse
									if (r % 3 == 0 || r % 2 != 0) { // add if r % 3 = 0 and if is odd
										AddEdge(r, c, Random().generate(1, 1000), true);
									}
								}
								else { // dense
									AddEdge(r, c, Random().generate(1, 1000), true);
								}
							}
						}
					}
				}
				// end build graph

				tStart = std::chrono::high_resolution_clock::now();
				for (int j = 0; j < runEachTimes; j++)
				{
					RunDijkstra();
				}
				cout << i << " - " << _numberVertices << " - " << _numberEdges << " - " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - tStart).count() << endl;
			}
		}
	}

	cout << endl << endl;
}