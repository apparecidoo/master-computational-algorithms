#include "pch.h"
#include <iostream>
#include <chrono>
#include "random.h"
#include <iomanip>
#include "greatest_common_divisor.h"
#include "sort.h"
#include "graph.h"

using namespace std;

int main()
{
	Graph* test = new Graph(0);
	test->TestPrim();

	Graph* test2 = new Graph(0);
	test2->TestDijkstra();

	system("pause");
}