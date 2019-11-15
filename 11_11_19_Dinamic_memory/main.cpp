#include<iostream>
using namespace std;

void FillRand(int** Arr, const int m, const int n);
void print(int** Arr, const int m, const int n);
/////////////////////////////////////////////////////////
int** push_row_back(int** Arr, int& m, int n);
int** push_row_front(int** Arr, int& m, int n);
int** insert_row(int** Arr, int& m, int n, int index);
int** pop_row_back(int** Arr, int& m, int n);
int** pop_row_front(int** Arr, int& m, int n);
int** erase_row(int** Arr, int& m, int n, int index);
////////////////////////////////////////////////////////
int** push_row_back22(int** Arr, int& m, int n);
int** push_row_front22(int** Arr, int& m, int n);
int** incert22(int** Arr, int& m, int n, int index);
int** pop_row_back22(int** Arr, int& m, int n);
int** pop_row_front22(int** Arr, int& m, int n);
int** erase_row22(int** Arr, int& m, int n, int index);
/////////////////////////////////////////////////////
void push_col_back(int** Arr, int m, int& n);
void push_col_front(int** Arr, int m, int& n);
void insert_col(int** Arr, int m, int& n, int index);
void pop_col_back(int** Arr, int m, int& n);
void pop_col_front(int** Arr, int m, int& n);
void erase_col(int** Arr, int m, int& n, int index);
void clear(int** Arr, int m);
int** allocate(const int m, const int n);


void main()
{
	setlocale(LC_ALL, "");

	int m; //количество строк
	int n; //количество елементов в строке
	std::cout << "введите количество строк: "; std::cin >> m;
	std::cout << "введите количество елементов строки: "; std::cin >> n;
	// Обявление двумерного динамического массива
	int** Arr = allocate(m, n);
	cout << "Memory allocated" << endl;
	cout << "Filling array" << endl;
	//////////////////////////////////////////////////////////
	// Использование двумерного динамического массива
	FillRand(Arr, m, n);
	print(Arr, m, n);

	/*cout << "Добавляем строку в конец:" << endl;
	Arr = push_row_back(Arr, m, n);
	print(Arr, m, n);

	cout << "Добавляем строку в начало:" << endl;
	Arr = push_row_front(Arr, m, n);
	print(Arr, m, n);
	cout << "Добавляем строку по индексу:" << endl;
	*/
	int index;
	/*
	cout << "введите индекс: "; cin >> index;
	Arr = insert_row(Arr, m, n, index);
	cout << "Array added" << endl;
	print(Arr, m, n);

	cout << "Удаляем последнюю строку:" << endl;
	Arr = pop_row_back(Arr, m, n);
	print(Arr, m, n);

	cout << "Удаляем первую строку:" << endl;
	Arr = pop_row_front(Arr, m, n);
	print(Arr, m, n);

	cout << "Удаляем строку по индексу:" << endl;
	cout << "введите индекс: "; cin >> index;
	Arr = erase_row(Arr, m, n, index);
	print(Arr, m, n);*/

	/*cout << "\t" << "last 0  :" << endl;
	Arr = push_row_back22(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "first 0  :" << endl;
	Arr = push_row_front22(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "index 0  :" << endl;
	cout << "incert index: "; cin >> index;
	Arr = incert22(Arr, m, n, index);
	print(Arr, m, n);
	cout << "\t" << "Delete last  :" << endl;
	Arr = pop_row_back22(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "Delete first  :" << endl;
	Arr = pop_row_front22(Arr, m, n);
	print(Arr, m, n);
	cout << "\t" << "Delete index  :" << endl;
	cout << "incert index: "; cin >> index;
	Arr = erase_row22(Arr, m, n, index);
	print(Arr, m, n);*/
	////////
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


	//// delete ArrAy
	//for (int i = 0; i < m; i++)
	//{
	// delete[] Arr[i];
	//}
	//delete[] Arr;
}
//////////////---------------------------------/////////////////////////////
void FillRand(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)  //количество строк
	{
		for (int j = 0; j < n; j++) //количество елементов в строке
		{
			Arr[i][j] = rand() % 100;
		}
	}
}
void print(int** Arr, const int m, const int n)
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
int** push_row_back(int** Arr, int& m, int n)
{
	int** buffer = new int*[m + 1]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = Arr[i][j]; //копируем элементы СООТВЕТСТВЕННО.
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
int** push_row_front(int** Arr, int& m, int n)
{
	int** buffer = new int*[m + 1]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == m - 1) break;
			buffer[i + 1][j] = Arr[i][j]; //копируем элементы со здвигом +1(i).
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	Arr = buffer;
	Arr[m] = new int [n] {}; //я думал что нужно вставить в (0) строку
	m++;
	return Arr;
}
int** insert_row(int** Arr, int& m, int n, int index)
{
	if (index > m) return Arr;
	int** buffer = new int*[m + 1]{};
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
			if (i == m - 1) break;
			buffer[i + 1][j] = Arr[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	Arr = buffer;
	Arr[index] = new int [n] {};
	m++;
	return Arr;
}
int** pop_row_back(int** Arr, int& m, int n) //удаляет последнюю строку
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
			buffer[i][j] = Arr[i][j]; //копируем элементы СООТВЕТСТВЕННО.
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	return buffer;
}
int** pop_row_front(int** Arr, int& m, int n) //удаляет последнюю строку
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
			buffer[i][j] = Arr[i + 1][j]; //копируем элементы СООТВЕТСТВЕННО.
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	return buffer;
}
int** erase_row(int** Arr, int& m, int n, int index)
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

int** push_row_back22(int** Arr, int& m, int n)
{
	int** buffer = new int*[m + 1];
	for (int i = 0; i < m; i++) buffer[i] = Arr[i];
	delete[] Arr;
	Arr = buffer;
	Arr[m] = new int [n] {};
	m++;
	return Arr;
}
int** push_row_front22(int** Arr, int& m, int n)
{
	int** buffer = new int*[m + 1];
	for (int i = 0; i < m; i++) buffer[i + 1] = Arr[i];
	delete[] Arr;
	Arr = buffer;
	Arr[0] = new int [n] {};
	m++;
	return Arr;
}
int** incert22(int** Arr, int& m, int n, int index)
{
	int** buffer = new int*[m + 1];
	for (int i = 0; i < index; i++) buffer[i] = Arr[i];
	for (int i = index; i < m; i++) buffer[i + 1] = Arr[i];
	delete[] Arr;
	Arr = buffer;
	Arr[index] = new int [n] {};
	m++;
	return Arr;
}
int** pop_row_back22(int** Arr, int& m, int n)
{
	int** buffer = new int*[--m];
	for (int i = 0; i < m; i++) buffer[i] = Arr[i];
	delete[] Arr;
	return buffer;
}
int** pop_row_front22(int** Arr, int& m, int n)
{
	int** buffer = new int*[--m];
	for (int i = 0; i < m; i++) buffer[i] = Arr[i + 1];
	delete[] Arr;
	return buffer;
}
int** erase_row22(int** Arr, int& m, int n, int index)
{
	int** buffer = new int*[--m];
	for (int i = 0; i < index; i++) buffer[i] = Arr[i];
	for (int i = index; i < m; i++) buffer[i] = Arr[i + 1];
	delete[] Arr;
	return buffer;
}
////////
void push_col_back(int** Arr, int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < m; j++) buffer[j] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
	n++;
}
void push_col_front(int** Arr, int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < m; j++) buffer[j + 1] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
	n++;
}
void insert_col(int** Arr, int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < index; j++) buffer[j] = Arr[i][j];
		for (int j = index; j < n; j++) buffer[j + 1] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
	n++;
}
void pop_col_back(int** Arr, int m, int& n)
{
	--n;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n]{};
		for (int j = 0; j < n; j++) buffer[j] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = buffer;
	}
}
void pop_col_front(int** Arr, int m, int& n)
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
void erase_col(int** Arr, int m, int& n, int index)
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
void clear(int** Arr, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}
int** allocate(const int m, const int n)
{
	int** Arr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		Arr[i] = new int[n] {};
	}
	return Arr;
}
