#pragma once

#include <stdio.h>
#include <assert.h>

typedef int DataType;

//≤Â»Î≈≈–Ú
void InsertSort(DataType *a,size_t n);
void ShellSort(DataType *a,size_t n);

//—°‘Ò≈≈–Ú
void SelectSort(DataType *a,size_t n);
void HeadSort(DataType *a,size_t n);

//Ωªªª≈≈–Ú
void BubbleSort(DataType *a,size_t n);
void QSortR(DataType *a,int left,int right);
void QSort(DataType *a, int left, int right);


//πÈ≤¢≈≈–Ú
void Sort( );

