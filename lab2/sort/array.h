#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdlib.h>
#include <stdbool.h>
bool input_array(int* arr,  int n);
bool merge_sort(int *arr, int n);
bool merge(int *arr, int l, int mid, int r);
void print_array(const int *arr, int n);
#endif //_ARRAY_H_