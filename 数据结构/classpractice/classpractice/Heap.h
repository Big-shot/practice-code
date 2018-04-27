#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include<string.h>

typedef int DataType; 

//������С��
void AdjustDown(DataType* a, size_t n, int root);
void MakeBigHeap(DataType* a, size_t n);
void MakeSmallHeap(DataType* a, size_t n);
void AdjustUp(DataType* a,int child);

// topk ����ǰK 
void TopK(DataType* a, size_t n, size_t k);

//���ȼ���������
#define N 1000 

typedef struct PriorityQueue 
{ 
    DataType _a[N]; 
    size_t _size; 

}PriorityQueue; 

void PriorityQueueInit(PriorityQueue* q);  //��ʼ��
void PriorityQueuePush(PriorityQueue* q, DataType x); //���
void PriorityQueuePop(PriorityQueue* q); //����
DataType PriorityQueueTop(PriorityQueue* q); 
size_t PriorityQueueSize(PriorityQueue* q); 
size_t PriorityQueueEmpty(PriorityQueue* q); 

void HeapSort(DataType* a, size_t n); //������



#endif //__HEAD_H__


