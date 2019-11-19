#include"functions.h"

template < typename T >void FillRand(T** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)  //строчки
	{
		for (int j = 0; j < n; j++) //Количество элементов
		{
			Arr[i][j] = rand() % 100;
			Arr[i][j] /= 10;
		}
	}
}
template < typename T >void print(T** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << Arr[i][j] << "\t";
		}
		std::cout << endl;
	}
	std::cout << endl;
}
///////////////////////////////////////////////////////
void print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << endl;
}