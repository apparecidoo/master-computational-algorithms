#include <random>

#ifndef HELPER_H
#define HELPER_H

using namespace std;

template <class T>
class Helper {
public:
	static void Copy(T from[], T to[], int size);
};

#endif

template<class T>
inline void Helper<T>::Copy(T from[], T to[], int size)
{
	for (int i = 0; i < size; i++)
	{
		to[i] = from[i];
	}
}