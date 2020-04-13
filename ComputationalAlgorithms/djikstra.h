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

	int MinDistance(T vDistance[], bool vDjkSolution[]);

public:
	Dijkstra(T** graph, int graphSize, int startVertex = 0);

	T* Run();
	void Print(T vDistance[]);
};

#endif

template<class T>
inline int Dijkstra<T>::MinDistance(T vDistance[], bool vDjkSolution[])
{
	T minValue = INT_MAX;
	int minIndex;

	for (int v = 0; v < _graphSize; v++) {
		if (!vDjkSolution[v] && vDistance[v] <= minValue) {
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
	bool* vDjkSolution = new bool[_graphSize]; // array of vertices are part of final solution or finalized

	for (int i = 0; i < _graphSize; i++) {
		vDistance[i] = INT_MAX;
		vDjkSolution[i] = false;
	}

	vDistance[_startVertex] = 0;

	for (int i = 0; i < _graphSize - 1; i++) {
		int u = MinDistance(vDistance, vDjkSolution);
		vDjkSolution[u] = true;

		for (int v = 0; v < _graphSize; v++) {
			// check if has connection, if is not solution yet and if is the mininum distance
			if (_graph[u][v] && !vDjkSolution[v] && vDistance[u] != INT_MAX
				&& vDistance[u] + _graph[u][v] < vDistance[v]) {
				vDistance[v] = vDistance[u] + _graph[u][v];
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
