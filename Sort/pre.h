#ifndef SORT_PRE_H
#define SORT_PRE_H


#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void InsertSort(int *a,int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
void BubbleSort(int* a, int n);
void QuickSort(int *a,int left,int right);
int PartSort1(int* a, int left, int right);
int PartSort2(int* a, int left, int right);
int PartSort3(int* a, int left, int right);
void Swap(int *a,int *b);

#endif //SORT_PRE_H
