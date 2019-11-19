#include"functions.h"

int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i]; //копируем элементы —ќќ“¬≈“—“¬≈ЌЌќ.
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 1; i <= n; i++)
	{
		buffer[i] = arr[i - 1]; //копируем элементы со —ћ≈ў≈Ќ»≈ћ.
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* incert(int arr[], int& n, int value, int mesto)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < mesto; i++)
	{
		buffer[i] = arr[i]; //копируем элементы до выбранного места.
	}
	for (int i = mesto; i < n; i++)
	{
		buffer[i + 1] = arr[i]; //копируем элементы после.
	}
	delete[] arr;
	arr = buffer;
	arr[mesto] = value;
	n++;
	return arr;
}

int* push_front2(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i]; //копируем элементы со смешеннием на 1 элемент вправо.
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* incert2(int arr[], int& n, int value, int mesto)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		if (i < mesto) buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[mesto] = value;
	n++;
	return arr;
}
int* pop_back(int* arr, int& n) //удал¤ет последнюю строку
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int* arr, int& n) //удал¤ет первую строку
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* erase(int* arr, int& n, int mesto) //удал¤ет  строку по индексу (выбраному месту)
{
	if (mesto > n) return arr;
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < mesto; i++) buffer[i] = arr[i];
	for (int i = mesto; i < n; i++) {
		if (i == n - 1) break;
		buffer[i] = arr[i + 1];
	}

	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
