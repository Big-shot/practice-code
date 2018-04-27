#ifndef __SLISTNODE_H__
#define __SLISTNODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct SListNode 
{ 
    struct SListNode* _next; 
    DataType _data; 
}SListNode; 

typedef struct ComplexNode
{
    int data;
    struct ComplexNode *next;
    struct ComplexNode *random;
}ComplexNode;


SListNode* BuySListNode(DataType x); //�����½ڵ� 
void SListPrint(SListNode* pHead);  //��ӡ����
void SListDestory(SListNode** ppHead);  //��������
void SListPushFront(SListNode** ppHead, DataType x); //ͷ��
void SListPushBack(SListNode** ppHead, DataType x); //β��
void SListPopBack(SListNode** ppHead); //βɾ
void SListPopFront(SListNode** ppHead);  //ͷɾ
SListNode* SListFind(SListNode* pHead, DataType x); //����
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x);  //���� 
void SListChange(SListNode**pphead,SListNode *pos,DataType x);  //������޸�
void SListErase(SListNode** ppHead, SListNode* pos); //�������

void EndToFirstPrintNode(SListNode*ps); //��β��ͷ������ӡ����
void EndToFirstPrintSListNode(SListNode *ps);  //��β��ͷ�ö�̬˳����ӡ����
void EndToFirstPrintSListNodeR(SListNode *ps);  //�õݹ��ӡ
void EndToFirstPrintSListNodeNon(SListNode *ps);  //��������,�ٴ�ӡ
void NoHeadSeqListDelete(SListNode *pos);  //ɾ��һ����ͷ����ķ�β�ڵ㣨���ܱ�������
void NoHeadSeqListInsert(SListNode *pos,DataType x); //����ͷ�����һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
SListNode* JosephCircle(SListNode*ps);  //Լɪ������
SListNode* ReverseSeqList(SListNode *Seq);  //��������
void SeqListSort(SListNode *Seq);  //ð������
SListNode* SListMerge(SListNode *list1,SListNode *list2); //�ϲ�������������,�ϲ�����Ȼ���� 
SListNode* SListFindMidNode(SListNode* list);  //���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
SListNode* SListFindTailKNode(SListNode *list, size_t k); //���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
void DeleteKNode(SListNode *list,size_t k);//ɾ������ĵ�����K�����

SListNode *CircleSListNode(SListNode *list);//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ 
int IsCross(SListNode* list1, SListNode* list2);//�жϵ������Ƿ����
size_t CircleLengthSListNode(SListNode *ps);//�󻷳�
SListNode *CircleEntrySListNode(SListNode *list,SListNode *meet); //�󻷵���ڵ�ַ
//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
int IsCross(SListNode *list1,SListNode *list2); //�ж� ���������Ƿ��ཻ
SListNode *SListCrossNode(SListNode *list1,SListNode *list2); //�󽻵��ַ��
//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 
SListNode *SListIsCross(SListNode *list1,SListNode *list2);
ComplexNode* BuyComplexNode(int x);
ComplexNode *CopyComplexList(ComplexNode *list);
void SListUnionData(SListNode *list1,SListNode *list2);//��������������������ͬ�����ݡ�
#endif //__SLISTNODE_H__
//��β��ͷ��ӡ������ 
//ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ������� 
//����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ������� 
//������ʵ��Լɪ��(JosephCircle) 
//����/��ת������ 
//����������ð������&�������� 
//�ϲ�������������,�ϲ�����Ȼ���� 
//���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
//ɾ������ĵ�����K����� 

//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ 
//ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ� 
//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 
//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 
//��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ�� 
//��һ���ڵ㣬����һ��randomָ��ָ����������е�һ������ڵ� 
//����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ�������� 
//��������������������ͬ�����ݡ� 