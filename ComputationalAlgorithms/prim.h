#include <iostream>

#ifndef PRIM_H
#define PRIM_H

using namespace std;

template <class T>
class Prim {
private:
	T** _graph;
	int _startVertex;
	int _graphSize;

	int MinKey(T vKey[], bool vExplored[]);

public:
	Prim(T** graph, int graphSize, int startVertex = 0);

	T* Run();
	void Print(T vDistance[]);
};

#endif

template<class T>
inline int Prim<T>::MinKey(T vKey[], bool vExplored[])
{
	int minValue = INT_MAX;
	int minIndex;

	for (int v = 0; v < _graphSize; v++) {
		if (!vExplored[v] && vKey[v] < minValue) {
			minValue = vKey[v];
			minIndex = v;
		}
	}

	return minIndex;
}

template<class T>
inline Prim<T>::Prim(T ** graph, int graphSize, int startVertex)
{
	_graph = graph;
	_graphSize = graphSize;
	_startVertex = startVertex;
}

template<class T>
inline T * Prim<T>::Run()
{
	T* vResult = new T[_graphSize]; // array of final solution
	T* vKey = new T[_graphSize]; // array of minimium edge
	bool* vExplored = new bool[_graphSize]; // array of vertices are explored

	for (int i = 0; i < _graphSize; i++) {
		vKey[i] = INT_MAX;
		vExplored[i] = false;
	}

	vKey[0] = 0;
	vResult[0] = NULL;

	for (int i = 0; i < _graphSize - 1; i++) // each vertex
	{
		int u = MinKey(vKey, vExplored);
		vExplored[u] = true;

		for (int j = 0; j < _graphSize; j++) { // update each value vertex
			// check if has connection, if is not explored yet and if is the mininum weight
			if (_graph[u][j] && !vExplored[j] && _graph[u][j] < vKey[j]) {
				vResult[j] = u;
				vKey[j] = _graph[u][j];
			}
		}
	}

	return vResult;
}

template<class T>
inline void Prim<T>::Print(T vDistance[])
{
	cout << "Edge (from to) \t\tWeight" << endl;
	for (int i = 0; i < _graphSize; i++) {
		cout << vDistance[i] << " - " << i << " \t\t\t " << _graph[i][vDistance[i]] << endl;
	}
}
