#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int DateType;

typedef struct SeqList
{
    DateType *data;
    size_t size;
    size_t capicity;
}SeqList;

void InitList(SeqList *Seq);  //��ʼ��˳���
void PrintList(SeqList *Seq);  //��ӡ˳���
void ListCheckFull(SeqList *Seq);  //����Ƿ����ˣ�������
void ListInsert(SeqList *Seq,size_t pos,DateType x);  //������루����ͷ���β�壩
void SeqListDelete(SeqList *Seq,size_t pos);  //ɾ��������ͷɾ��βɾ��
DateType SeqListSearch(SeqList *Seq,DateType x);  //˳�����
DateType SeqListBinarySearch(SeqList *Seq,DateType x);  //���ֲ���
void SeqListChange(SeqList *Seq,DateType pos,DateType x);  //�޸�˳���
void SeqListBubbleSort(SeqList *Seq);  //ð������˳���
void SeqListSelectSort(SeqList *Seq);  //ѡ������˳���

#endif 
