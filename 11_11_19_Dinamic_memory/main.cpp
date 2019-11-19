#include<iostream>
using namespace std;

#define ROWS
//#define COLS

template < typename T >T** allocate(const int m, const int n);
template < typename T >void FillRand(T** Arr, const int m, const int n);
template < typename T >void print(T** Arr, const int m, const int n);
template < typename T >void clear(T** Arr, int m);
#ifdef ROWS
template < typename T >void push_row_back(T**& Arr, int& m, int n);
template < typename T >void push_row_front(T**& Arr, int& m, int n);
template < typename T >void incert(T**& Arr, int& m, int n, int index);
template < typename T >void pop_row_back(T**& Arr, int& m, int n);
template < typename T >void pop_row_front(T**& Arr, int& m, int n);
template < typename T >void erase_row(T**& Arr, int& m, int n, int index);

#endif // ROWS
#ifdef COLS
template < typename T >void push_col_back(T** Arr, int m, int& n);
template < typename T >void push_col_front(T** Arr, int m, int& n);
template < typename T >void insert_col(T** Arr, int m, int& n, int index);
template < typename T >void pop_col_back(T** Arr, int m, int& n);
template < typename T >void pop_col_front(T** Arr, int m, int& n);
template < typename T >void erase_col(T** Arr, int m, int& n, int index);

#endif // COLS

void main()
{
	setlocale(LC_ALL, "");

	int m; // Количество строк
	int n; // Количество элементов строки
	int index; // Кудо что добавлять и удалять
	std::cout << "Incert nomber of STROK: "; std::cin >> m;
	std::cout << "Incert nomber of ELEMENTOV: "; std::cin >> n;
	// Обявление двумерного динамического массива
	int** Arr = allocate<int>(m, n);
	cout << "Memory allocated" << endl;
	cout << "Filling array" << endl;
	//////////////////////////////////////////////////////////
	// Использование двумерного динамического массива
	FillRand(Arr, m, n);
	print(Arr, m, n);

#ifdef ROWS
	cout << "\t" << "last 0  :" << endl;
	push_row_back(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "first 0  :" << endl;
	push_row_front(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "index 0  :" << endl;
	cout << "incert index: "; cin >> index;
	incert(Arr, m, n, index);
	print(Arr, m, n);
	cout << "\t" << "Delete last  :" << endl;
	pop_row_back(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "Delete first  :" << endl;
	pop_row_front(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "Delete index  :" << endl;
	cout << "incert index: "; cin >> index;
	erase_row(Arr, m, n, index);
	print(Arr, m, n);
	
#endif // ROWS
#ifdef COLS
	cout << "\t" << "Add last Column  :" << endl;
	push_col_back(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "Add first Column  :" << endl;
	push_col_front(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "Add column by index  :" << endl;
	cout << "incert index: "; cin >> index;
	insert_col(Arr, m, n, index);
	print(Arr, m, n);
	cout << "\t" << "Delete last Column  :" << endl;
	pop_col_back(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "Delete first Column  :" << endl;
	pop_col_front(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "Delete column by index  :" << endl;
	cout << "incert index: "; cin >> index;
	erase_col(Arr, m, n, index);
	print(Arr, m, n);
	clear(Arr, m);

#endif // COLS

}
///////////////////////////////////////////
template < typename T >T** allocate(const int m, const int n)
{
	T** Arr = new T*[m];
	for (int i = 0; i < m; i++)
	{
		Arr[i] = new T[n] {};
	}
	return Arr;
}
template < typename T >void FillRand(T** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)  //строчки
	{
		for (int j = 0; j < n; j++) //êîëè÷åñòâî åëåìåíòîâ â ñòðîêå
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
template < typename T >void clear(T** Arr, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}
////////////____________________________________///////////////////////////
template < typename T >void push_row_back(T**& Arr, int& m, int n)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < m; i++) buffer[i] = Arr[i];
	delete[] Arr;
	Arr = buffer;
	Arr[m] = new int [n] {};
	m++;
}
template < typename T >void push_row_front(T**& Arr, int& m, int n)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < m; i++) buffer[i + 1] = Arr[i];
	delete[] Arr;
	Arr = buffer;
	Arr[0] = new T[n] {};
	m++;
}
template < typename T >void incert(T**& Arr, int& m, int n, int index)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < index; i++) buffer[i] = Arr[i];
	for (int i = index; i < m; i++) buffer[i + 1] = Arr[i];
	delete[] Arr;
	Arr = buffer;
	Arr[index] = new int [n] {};
	m++;
}
template < typename T >void pop_row_back(T**& Arr, int& m, int n)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < m; i++) buffer[i] = Arr[i];
	Arr = buffer;
}
template < typename T >void pop_row_front(T**& Arr, int& m, int n)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < m; i++) buffer[i] = Arr[i + 1];
	Arr = buffer;
}
template < typename T >void erase_row(T**& Arr, int& m, int n, int index)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < index; i++) buffer[i] = Arr[i];
	for (int i = index; i < m; i++) buffer[i] = Arr[i + 1];
	Arr = buffer;
}
////////
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
		int* buffer = new int[n]{};
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
		int* buffer = new int[n]{};
		for (int j = 0; j < index; j++) buffer[j] = Arr[i][j];
		for (int j = index; j < n; j++) buffer[j] = Arr[i][j + 1];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
}
