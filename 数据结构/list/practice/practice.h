#ifndef __PRACTICE_H__
#define __PRACTICE_H__

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

#define MAXSIZE 100 

typedef int Datatype;

typedef struct SequenceTable //��̬˳���
{
    Datatype _data[MAXSIZE];
    Datatype _size;
}Seq;

typedef struct SeqList  //��̬˳���
{
    Datatype *_data;
    Datatype _size;
    size_t _capacity;
}SeqList;

typedef struct LinkList //������ṹ
{
    Datatype _data;
    struct LinkList *_next;
}LinkList;

 typedef struct doublelist
 {
     Datatype _data;
     struct doublelist *_next;
     struct doublelist *_prev;
 }doublelist;

//��̬˳�����ز���
void SeqListInit(SeqList *list); //��ʼ��
void PrintSeqList(SeqList *list); //��ӡ˳���
void PushSeqlist(SeqList* list,Datatype pos,Datatype x); //����Ԫ��
void DeleteSeqlist(SeqList *list,Datatype x); //ɾ��Ԫ��
void CheckSeqCapacity(SeqList *list); //���˳��������
void ChangeSeqlist(SeqList *list,Datatype x,Datatype dst); //�޸�Ԫ��
Datatype SearchSeqlist(SeqList *list,Datatype x); //��˳����в���Ԫ��
size_t SeqlistSize(SeqList *list);//��˳���Ԫ�ظ���
void ClearSeqlist(SeqList *list); //���˳���

//��������ز���
LinkList *BuyListNode(Datatype x); //�����ڵ�
void PrintLinkList(LinkList *phead); //��ӡ����
void LinkListInsert(LinkList **pphead,LinkList *pos,Datatype x); //����Ĳ��루����ͷ��,������룩
void LinkListDelete(LinkList **pphead,Datatype x);//����Ԫ�ص�ɾ��
LinkList *LinkListSearch(LinkList *phead,Datatype x); //����Ԫ�ز���
void LinkListChange(LinkList *phead,Datatype x,Datatype y); //����Ԫ���޸�
void LinkListSort(LinkList *phead);//��������ѡ������
LinkList *LinkListReverse(LinkList *pphead); //�����������
//�����������ӡ
void PrintLinkListrR(LinkList *phead); //�ݹ��ӡ
void PrintLinkListTail(LinkList *phead);  //����βָ��ǰ�����δ�ӡ
//��˳����������ڴ�ӡ
//�Ȱ����������ڴ�ӡ

//����������Ŀ 
//1����β��ͷ��ӡ������ (�����ַ���) 
//2��ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ������� 
void LinkListNoHead(LinkList *pos);
//3������ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ������� 
void LinkListNoHeadInsert(LinkList *pos,Datatype x);
//4��������ʵ��Լɪ��(JosephCircle)
void LinkListJosephCircle(LinkList *phead,Datatype x);
//5������/��ת������ 
//6������������ð������ 
void LinkListBubbleSort(LinkList *phead);
//7���ϲ�������������,�ϲ�����Ȼ���� 
LinkList *CombineDoublelinklist(LinkList *list1,LinkList *list2);
//8�����ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
LinkList *SearchMidNode(LinkList *phead);
//9�����ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
LinkList *SearchKNode(LinkList *phead,Datatype k);
//10��ɾ������ĵ�����K����� 
void DeleteKNode(LinkList *phead,Datatype k);
// 1���жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿
void CreateCircle(LinkList *list,LinkList *entry); //����һ�������ڲ���
LinkList *CheckIsCircle(LinkList *phead); //�������ػ��������㣬��ֹ����null
int CircleSize(LinkList *phead,LinkList *meet);
LinkList *CircleEntry(LinkList *phead,LinkList* meet);
// 2���ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
void CreateTogetherNode(LinkList *list1,LinkList *list2,LinkList *node1,LinkList *node2);// �����ཻ�������ڲ��ԡ�
LinkList *LinkListSameNode(LinkList*list1,LinkList *list2);
// 3���ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 
//(1�����ཻ 2���ཻ������ 3���ཻ������a�������ཻ b�������ཻ�� )
LinkList *LinkListSameNodeCircle(LinkList *list1,LinkList *list2);

// 4����������������������ͬ�����ݡ�
void TwoListSamedata(LinkList *list1,LinkList *list2);

//���������
void DestoryLinkList(LinkList *list);


  
 doublelist *BuyListDouNode(Datatype x);//create node
 void PrintList(doublelist *list); //output data to display
 void InsertData(doublelist **list,Datatype x); // insert data

#endif //__PRACTICE_H__
