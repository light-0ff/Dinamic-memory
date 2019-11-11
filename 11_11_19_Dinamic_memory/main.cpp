#include<iostream>
using namespace std;


void FillRand(int** Arr, const int m, const int n);
void print(int** Arr, const int m, const int n);
int** push_row_back(int** Arr, int& m, int n);
int** push_row_front(int** Arr, int& m, int n);
int** insert_row(int** Arr, int& m, int n, int index);
int** pop_row_back(int** Arr, int& m, int n);
int** pop_row_front(int** Arr, int& m, int n);
int** erase_row(int** Arr, int& m, int n, int index);

void main()
{
	setlocale(LC_ALL, "");

	int m; //���������� �����
	int n; //���������� ��������� � ������
	std::cout << "������� ���������� �����: "; std::cin >> m;
	std::cout << "������� ���������� ��������� ������: "; std::cin >> n;
	// ��������� ���������� ������������� �������
	int** Arr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		Arr[i] = new int[n] {};
	}
	cout << "Memory allocated" << endl;
	cout << "Filling array" << endl;
	//////////////////////////////////////////////////////////
	// ������������� ���������� ������������� �������
	FillRand(Arr, m, n);
	print(Arr, m, n);

	cout << "��������� ������ � �����:" << endl;
	Arr = push_row_back(Arr, m, n);
	print(Arr, m, n);

	cout << "��������� ������ � ������:" << endl;
	Arr = push_row_front(Arr, m, n);
	print(Arr, m, n);

	cout << "��������� ������ �� �������:" << endl;
	int index;
	cout << "������� ������: "; cin >> index;
	Arr = insert_row(Arr, m, n, index);
	cout << "Array added" << endl;
	print(Arr, m, n);

	cout << "������� ��������� ������:" << endl;
	Arr = pop_row_back(Arr, m, n);
	print(Arr, m, n);

	cout << "������� ������ ������:" << endl;
	Arr = pop_row_front(Arr, m, n);
	print(Arr, m, n);

	cout << "������� ������ �� �������:" << endl;
	cout << "������� ������: "; cin >> index;
	Arr = erase_row(Arr, m, n, index);
	print(Arr, m, n);

	// �������� ���������� ������������� �������
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}
//////////////---------------------------------/////////////////////////////
void FillRand(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)  //���������� �����
	{
		for (int j = 0; j < n; j++) //���������� ��������� � ������
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
			buffer[i][j] = Arr[i][j]; //�������� �������� ��������������.
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
			buffer[i + 1][j] = Arr[i][j]; //�������� �������� �� ������� +1(i).
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	Arr = buffer;
	Arr[m] = new int [n] {}; //� ����� ��� ����� �������� � (0) ������
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
	Arr[m] = new int [n] {}; //� ����� ��� ����� ������������������� (0) ������
	m++;
	return Arr;
}
int** pop_row_back(int** Arr, int& m, int n) //������� ��������� ������
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
			buffer[i][j] = Arr[i][j]; //�������� �������� ��������������.
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
	return buffer;
}
int** pop_row_front(int** Arr, int& m, int n) //������� ��������� ������
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
			buffer[i][j] = Arr[i + 1][j]; //�������� �������� ��������������.
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
