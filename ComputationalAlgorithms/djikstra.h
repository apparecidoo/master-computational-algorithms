#include <iostream>

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

using namespace std;

template <class T>
class Dijkstra {
private:
	T** _graph;
	int _startVertex;
	int _graphSize;

	int MinDistance(T vDistance[], bool vExplored[]);

public:
	Dijkstra(T** graph, int graphSize, int startVertex = 0);

	T* Run();
	void Print(T vDistance[]);
};

#endif

template<class T>
inline int Dijkstra<T>::MinDistance(T vDistance[], bool vExplored[])
{
	T minValue = INT_MAX;
	int minIndex;

	for (int v = 0; v < _graphSize; v++) {
		if (!vExplored[v] && vDistance[v] <= minValue) {
			minValue = vDistance[v];
			minIndex = v;
		}
	}

	return minIndex;
}

template<class T>
inline Dijkstra<T>::Dijkstra(T ** graph, int graphSize, int startVertex)
{
	_graph = graph;
	_graphSize = graphSize;
	_startVertex = startVertex;
}

template<class T>
inline T * Dijkstra<T>::Run()
{
	T* vDistance = new T[_graphSize]; // The final solution with the shortest distance
	bool* vExplored = new bool[_graphSize]; // array of vertices are part explored or finalized

	for (int i = 0; i < _graphSize; i++) {
		vDistance[i] = INT_MAX;
		vExplored[i] = false;
	}

	vDistance[_startVertex] = 0;

	for (int i = 0; i < _graphSize - 1; i++) { // each vertex
		int u = MinDistance(vDistance, vExplored);
		vExplored[u] = true;

		for (int j = 0; j < _graphSize; j++) { // update each vertex value that has connection
			// check if has connection, if is not explored yet and if is the mininum distance
			if (_graph[u][j] && !vExplored[j] && vDistance[u] != INT_MAX
				&& vDistance[u] + _graph[u][j] < vDistance[j]) {
				vDistance[j] = vDistance[u] + _graph[u][j];
			}
		}
	}

	return vDistance;
}

template<class T>
inline void Dijkstra<T>::Print(T vDistance[])
{
	cout << "Vertex \t\t Distance" << endl;
	for (int i = 0; i < _graphSize; i++) {
		cout << i << " \t\t " << vDistance[i] << endl;
	}
}
