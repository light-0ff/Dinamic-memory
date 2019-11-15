#include"functions.h"

template < typename T >void clear(T** Arr, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}
template < typename T >T** allocate(const int m, const int n)
{
	T** Arr = new T*[m];
	for (int i = 0; i < m; i++)
	{
		Arr[i] = new T[n]{};
	}
	return Arr;
}
