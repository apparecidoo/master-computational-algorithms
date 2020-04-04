#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <iomanip>
#include "random.h"
#include "helper.h"

#ifndef SORT_H
#define SORT_H

using namespace std;

template <class T>
class Sort {
private:
	static void Swap(T arr[], int a, int b);
	static void QuickSort(T arr[], int left, int right);
	static void QuickSortRandom(T arr[], int left, int right);
	static int QuickSortDivide(T arr[], int left, int right, bool pivotRandom = false);
public:
	static void Print(T arr[], int size);
	static void BubbleSort(T arr[], int size);
	static void QuickSort(T arr[], int size);
	static void QuickSortRandom(T arr[], int size);
	static void Test();
};

#endif

template<class T>
inline void Sort<T>::Swap(T arr[], int a, int b)
{
	T aux = arr[a];
	arr[a] = arr[b];
	arr[b] = aux;
}

template<class T>
inline void Sort<T>::QuickSort(T arr[], int left, int right)
{
	if (left < right) {
		int pivot = QuickSortDivide(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

template<class T>
inline void Sort<T>::QuickSortRandom(T arr[], int left, int right)
{
	if (left < right) {
		int pivot = QuickSortDivide(arr, left, right, true);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

template<class T>
inline int Sort<T>::QuickSortDivide(T arr[], int left, int right, bool pivotRandom)
{
	int i = left + 1;
	int j = right;
	int pivot = pivotRandom ? arr[Random().generate(left, right)] : arr[left];
	while (i <= j)
	{
		if (arr[i] <= pivot) {
			i++;
		}
		else {
			if (arr[j] > pivot) {
				j--;
			}
			else {
				if (i <= j) {
					Swap(arr, i, j);
					i++;
					j--;
				}
			}
		}
	}

	Swap(arr, left, j);
	
	return j;
}

template<class T>
inline void Sort<T>::Print(T arr[], int size)
{
	cout << "Array: [ ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i != size - 1) {
			cout << ", ";
		}
		else {
			cout << " ]" << endl;
		}
	}
}

template<class T>
inline void Sort<T>::BubbleSort(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				Swap(arr, j, j + 1);
			}
		}
	}
}

template<class T>
inline void Sort<T>::QuickSort(T arr[], int size)
{
	QuickSort(arr, 0, size - 1);
}

template<class T>
inline void Sort<T>::QuickSortRandom(T arr[], int size)
{
	QuickSortRandom(arr, 0, size - 1);
}

template<class T>
inline void Sort<T>::Test()
{
	const int size = 3000;
	int arr[size];
	int arrAux[size];
	std::chrono::time_point<chrono::steady_clock> tStart;
	cout.setf(ios::fixed);

	for (int j = 0; j < 20; j++)
	{
		cout << "===== Attemp " << j << " =====" << endl;
		Random().generate(arr, size, 0, 99999);
		//Sort<int>().Print(arr, size);
		Helper<int>().Copy(arr, arrAux, size);

		for (int i = 0; i < 3; i++)
		{
			if (i == 0) {
				//cout << endl << "BubbleSort: " << endl;
				tStart = std::chrono::high_resolution_clock::now();
				Sort<int>().BubbleSort(arr, size);
				//cout << " TimeExecution: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - tStart).count() << " microseconds" << endl;
				cout << " " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - tStart).count();
			}
			if (i == 1) {
				Helper<int>().Copy(arrAux, arr, size);
				//cout << endl << "QuickSort: " << endl;
				tStart = std::chrono::high_resolution_clock::now();
				Sort<int>().QuickSort(arr, size);
				//cout << " TimeExecution: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - tStart).count() << " microseconds" << endl;
				cout << " " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - tStart).count();
			}
			if (i == 2) {
				Helper<int>().Copy(arrAux, arr, size);
				//cout << endl << "QuickSortRandom: " << endl;
				tStart = std::chrono::high_resolution_clock::now();
				Sort<int>().QuickSortRandom(arr, size);
				//cout << " TimeExecution: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - tStart).count() << " microseconds" << endl;
				cout << " " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - tStart).count();
			}
		}

		cout << endl;
	}
}
