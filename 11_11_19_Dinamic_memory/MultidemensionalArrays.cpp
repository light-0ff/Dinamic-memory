#include"functions.h"

template < typename T >T** push_row_back(T** Arr, int& m, int n)
{
	T** buffer = new T*[m + 1]{};
	for (int i = 0; i < m; i++)	buffer[i] = new int[n] {};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = Arr[i][j]; //êîïèðóåì ýëåìåíòû ÑÎÎÒÂÅÒÑÒÂÅÍÍÎ.
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	Arr = buffer;
	Arr[m] = new int [n] {};
	m++;
	return Arr;
}
template < typename T >T** push_row_front(T** Arr, int& m, int n)
{
	T** buffer = new T*[m + 1]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == m - 1) break;
			buffer[i + 1][j] = Arr[i][j]; //êîïèðóåì ýëåìåíòû ñî çäâèãîì +1(i).
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	Arr = buffer;
	Arr[m] = new int [n] {}; //ÿ äóìàë ÷òî íóæíî âñòàâèòü â (0) ñòðîêó
	m++;
	return Arr;
}
template < typename T >T** insert_row(T** Arr, int& m, int n, int index)
{
	if (index > m) return Arr;
	T** buffer = new T*[m + 1]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < n; j++)	buffer[i][j] = Arr[i][j];
	}
	for (int i = index; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == m - 1) break;
			buffer[i + 1][j] = Arr[i][j];
		}
	}
	for (int i = 0; i < m; i++)	delete[] Arr[i];

	delete[] Arr;
	Arr = buffer;
	Arr[index] = new int [n] {};
	m++;
	return Arr;
}
template < typename T >T** pop_row_back(T** Arr, int& m, int n) //óäàëÿåò ïîñëåäíþþ ñòðîêó
{
	T** buffer = new T*[--m]{};
	for (int i = 0; i < m; i++)	buffer[i] = new int[n] {};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = Arr[i][j]; //êîïèðóåì ýëåìåíòû ÑÎÎÒÂÅÒÑÒÂÅÍÍÎ.
		}
	}
	for (int i = 0; i < m; i++)	delete[] Arr[i];
	delete[] Arr;
	return buffer;
}
template < typename T >T** pop_row_front(T** Arr, int& m, int n) //óäàëÿåò ïîñëåäíþþ ñòðîêó
{
	int** buffer = new int*[--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = Arr[i + 1][j]; //êîïèðóåì ýëåìåíòû ÑÎÎÒÂÅÒÑÒÂÅÍÍÎ.
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	return buffer;
}
template < typename T >T** erase_row(T** Arr, int& m, int n, int index)
{
	if (index > m) return Arr;
	int** buffer = new int*[--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = Arr[i][j];
		}
	}
	for (int i = index; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = Arr[i + 1][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	return buffer;
}
////////////____________________________________///////////////////////////
template < typename T >T** push_row_back22(T** Arr, int& m, int n)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < m; i++) buffer[i] = Arr[i];
	delete[] Arr;
	Arr = buffer;
	Arr[m] = new int [n] {};
	m++;
	return Arr;
}
template < typename T >T** push_row_front22(T** Arr, int& m, int n)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < m; i++) buffer[i + 1] = Arr[i];
	delete[] Arr;
	Arr = buffer;
	Arr[0] = new T[n]{};
	m++;
	return Arr;
}
template < typename T >T** incert22(T** Arr, int& m, int n, int index)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < index; i++) buffer[i] = Arr[i];
	for (int i = index; i < m; i++) buffer[i + 1] = Arr[i];
	delete[] Arr;
	Arr = buffer;
	Arr[index] = new int [n] {};
	m++;
	return Arr;
}
template < typename T >T** pop_row_back22(T** Arr, int& m, int n)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < m; i++) buffer[i] = Arr[i];
	delete[] Arr;
	return buffer;
}
template < typename T >T** pop_row_front22(T** Arr, int& m, int n)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < m; i++) buffer[i] = Arr[i + 1];
	delete[] Arr;
	return buffer;
}
template < typename T >T** erase_row22(T** Arr, int& m, int n, int index)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < index; i++) buffer[i] = Arr[i];
	for (int i = index; i < m; i++) buffer[i] = Arr[i + 1];
	delete[] Arr;
	return buffer;
}
/////////////////////////////////////////////////////////////////////
template < typename T >void push_col_back(T** Arr, int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < m; j++) buffer[j] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
	n++;
}
template < typename T >void push_col_front(T** Arr, int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < m; j++) buffer[j + 1] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
	n++;
}
template < typename T >void insert_col(T** Arr, int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < index; j++) buffer[j] = Arr[i][j];
		for (int j = index; j < n; j++) buffer[j + 1] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
	n++;
}
template < typename T >void pop_col_back(T** Arr, int m, int& n)
{
	--n;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n]{};
		for (int j = 0; j < n; j++) buffer[j] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
}
template < typename T >void pop_col_front(T** Arr, int m, int& n)
{
	--n;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n] {};
		for (int j = 0; j < n; j++) buffer[j] = Arr[i][j + 1];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
}
template < typename T >void erase_col(T** Arr, int m, int& n, int index)
{
	--n;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n] {};
		for (int j = 0; j < index; j++) buffer[j] = Arr[i][j];
		for (int j = index; j < n; j++) buffer[j] = Arr[i][j + 1];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
}
