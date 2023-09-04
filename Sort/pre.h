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




#endif //SORT_PRE_H
