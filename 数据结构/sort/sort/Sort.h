#pragma once

#include <stdio.h>
#include <assert.h>

typedef int DataType;

//��������
void InsertSort(DataType *a,size_t n);
void ShellSort(DataType *a,size_t n);

//ѡ������
void SelectSort(DataType *a,size_t n);
void HeadSort(DataType *a,size_t n);

//��������
void BubbleSort(DataType *a,size_t n);
void QSortR(DataType *a,int left,int right);
void QSort(DataType *a, int left, int right);


//�鲢����
void Sort( );

