#pragma once
#include<iostream>
using namespace std;
void print(int arr[], const int n);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* incert(int arr[], int& n, int value, int mesto);

int* push_front2(int* arr, int& n, int value);
int* incert2(int arr[], int& n, int value, int mesto);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n, int mesto);
//_______________________________________????????????????????????????//////
template < typename T >void FillRand(T** Arr, const int m, const int n);
template < typename T >void print(T** Arr, const int m, const int n);
/////////////////////////////////////////////////////////
template < typename T >T** push_row_back(T** arr, int& m, int n);
template < typename T >T** push_row_front(T** arr, int& m, int n);
template < typename T >T** insert_row(T** arr, int& m, int n, int index);
template < typename T >T** pop_row_back(T** arr, int& m, int n);
template < typename T >T** pop_row_front(T** arr, int& m, int n);
template < typename T >T** erase_row(T** arr, int& m, int n, int index);
////////////////////////////////////////////////////////
template < typename T >T** push_row_back22(T** Arr, int& m, int n);
template < typename T >T** push_row_front22(T** Arr, int& m, int n);
template < typename T >T** incert22(T** Arr, int& m, int n, int index);
template < typename T >T** pop_row_back22(T** Arr, int& m, int n);
template < typename T >T** pop_row_front22(T** Arr, int& m, int n);
template < typename T >T** erase_row22(T** Arr, int& m, int n, int index);
/////////////////////////////////////////////////////
template < typename T >void push_col_back(T** Arr, int m, int& n);
template < typename T >void push_col_front(T** Arr, int m, int& n);
template < typename T >void insert_col(T** Arr, int m, int& n, int index);
template < typename T >void pop_col_back(T** Arr, int m, int& n);
template < typename T >void pop_col_front(T** Arr, int m, int& n);
template < typename T >void erase_col(T** Arr, int m, int& n, int index);
template < typename T >void clear(T** Arr, int m);
template < typename T >T** allocate(const int m, const int n);