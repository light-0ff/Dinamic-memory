#include"functions.h"
#include"Memory.cpp"
#include"BasseFunctions.cpp"
#include"SimpleArrays.cpp"
#include"MultidemensionalArrays.cpp"

//#define OneDimensionRows
//#define ROWS
//#define ALTERNATIVE_ROWS
#define COLS

typedef char DataType; // go to teacher and copy realisation of this

void main()
{
	setlocale(LC_ALL, "RUS");

	int m; // Количество строк
	int n; // Количество элементов строки
	int index; // Кудо что добавлять и удалять
#ifdef OneDimensionRows
	cout << "¬ведите размер массива: "; cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cout << (arr[i] = rand() % 100) << "\t";
	cout << endl;
	int value;
	cout << "¬ведите добавл¤емое значение: "; cin >> value;

	
	do
	{	cout << "¬ведите желаемое место: "; cin >> index;
	} while (index > n);
	arr = incert2(arr, n, value, index);
	print(arr, n);
	cout << "”дал¤ем последний элемент: " << endl;
	arr = pop_back(arr, n);
	print(arr, n);
	cout << "”дал¤ем первый элемент: " << endl;
	cout << "\t";
	arr = pop_front(arr, n);
	print(arr, n);

	int* old = arr;
	do {
		cout << "¬ыбирете удал¤ем  элемент: "; cin >> mesto;
	} while (index > n);

	cout << "\t";
	arr = erase(arr, n, index);
	print(arr, n);

	delete[] arr;
}
#endif // OneDimensionRows
	std::cout << "Введите количество строк: "; std::cin >> m;
	std::cout << "Введите количество элементов: "; std::cin >> n;
	// Îáÿâëåíèå äâóìåðíîãî äèíàìè÷åñêîãî ìàññèâà
	int** Arr = allocate<int>(m, n);
	cout << "Memory allocated" << endl;
	cout << "Filling array" << endl;
	//////////////////////////////////////////////////////////
	// Èñïîëüçîâàíèå äâóìåðíîãî äèíàìè÷åñêîãî ìàññèâà
	FillRand(Arr, m, n);
	print(Arr, m, n);


#ifdef ROWS
	cout << "Добавление строчки в конец:" << endl;
	Arr = push_row_back(Arr, m, n);
	print(Arr, m, n);

	cout << "Добавление строчки в начало:" << endl;
	Arr = push_row_front(Arr, m, n);
	print(Arr, m, n);
	cout << "Äîáàâëÿåì ñòðîêó ïî èíäåêñó:" << endl;
	
	
	cout << "Добавление строчки по индексу: "; cin >> index;
	Arr = insert_row(Arr, m, n, index);
	cout << "Array added" << endl;
	print(Arr, m, n);

	cout << "Óäàëÿåì ïîñëåäíþþ ñòðîêó:" << endl;
	Arr = pop_row_back(Arr, m, n);
	print(Arr, m, n);

	cout << "Óäàëÿåì ïåðâóþ ñòðîêó:" << endl;
	Arr = pop_row_front(Arr, m, n);
	print(Arr, m, n);

	cout << "Óäàëÿåì ñòðîêó ïî èíäåêñó:" << endl;
	cout << "ââåäèòå èíäåêñ: "; cin >> index;
	Arr = erase_row(Arr, m, n, index);
	print(Arr, m, n);
#endif // ROWS
#ifdef ALTERNATIVE_ROWS
	cout << "\t" << "last 0  :" << endl;
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
	print(Arr, m, n);


#endif // ALTERNATIVE_ROWS
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
#endif // COLS
	clear(Arr, m);



	//
	//// delete ArrAy
	//for (int i = 0; i < m; i++)
	//{
	// delete[] Arr[i];
	//}
	//delete[] Arr;
}
//////////////---------------------------------/////////////////////////////

