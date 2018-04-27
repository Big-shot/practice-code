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

void InitList(SeqList *Seq);  //初始化顺序表
void PrintList(SeqList *Seq);  //打印顺序表
void ListCheckFull(SeqList *Seq);  //检查是否满了，并扩容
void ListInsert(SeqList *Seq,size_t pos,DateType x);  //随机插入（包括头插和尾插）
void SeqListDelete(SeqList *Seq,size_t pos);  //删除（包括头删和尾删）
DateType SeqListSearch(SeqList *Seq,DateType x);  //顺序查找
DateType SeqListBinarySearch(SeqList *Seq,DateType x);  //二分查找
void SeqListChange(SeqList *Seq,DateType pos,DateType x);  //修改顺序表
void SeqListBubbleSort(SeqList *Seq);  //冒泡排序顺序表
void SeqListSelectSort(SeqList *Seq);  //选择排序顺序表

#endif 
