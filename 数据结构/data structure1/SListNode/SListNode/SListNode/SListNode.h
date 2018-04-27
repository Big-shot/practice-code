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


SListNode* BuySListNode(DataType x); //创建新节点 
void SListPrint(SListNode* pHead);  //打印链表
void SListDestory(SListNode** ppHead);  //销毁链表
void SListPushFront(SListNode** ppHead, DataType x); //头插
void SListPushBack(SListNode** ppHead, DataType x); //尾插
void SListPopBack(SListNode** ppHead); //尾删
void SListPopFront(SListNode** ppHead);  //头删
SListNode* SListFind(SListNode* pHead, DataType x); //查找
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x);  //插入 
void SListChange(SListNode**pphead,SListNode *pos,DataType x);  //链表的修改
void SListErase(SListNode** ppHead, SListNode* pos); //清空链表

void EndToFirstPrintNode(SListNode*ps); //从尾到头正常打印链表
void EndToFirstPrintSListNode(SListNode *ps);  //从尾到头用动态顺序表打印链表
void EndToFirstPrintSListNodeR(SListNode *ps);  //用递归打印
void EndToFirstPrintSListNodeNon(SListNode *ps);  //逆置链表,再打印
void NoHeadSeqListDelete(SListNode *pos);  //删除一个无头链表的非尾节点（不能遍历链表）
void NoHeadSeqListInsert(SListNode *pos,DataType x); //在无头链表的一个节点前插入一个节点（不能遍历链表）
SListNode* JosephCircle(SListNode*ps);  //约瑟夫环问题
SListNode* ReverseSeqList(SListNode *Seq);  //逆置链表
void SeqListSort(SListNode *Seq);  //冒泡排序
SListNode* SListMerge(SListNode *list1,SListNode *list2); //合并两个有序链表,合并后依然有序 
SListNode* SListFindMidNode(SListNode* list);  //查找单链表的中间节点，要求只能遍历一次链表
SListNode* SListFindTailKNode(SListNode *list, size_t k); //查找单链表的倒数第k个节点，要求只能遍历一次链表 
void DeleteKNode(SListNode *list,size_t k);//删除链表的倒数第K个结点

SListNode *CircleSListNode(SListNode *list);//判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算 
int IsCross(SListNode* list1, SListNode* list2);//判断单链表是否带环
size_t CircleLengthSListNode(SListNode *ps);//求环长
SListNode *CircleEntrySListNode(SListNode *list,SListNode *meet); //求环的入口地址
//判断两个链表是否相交，若相交，求交点。（假设链表不带环）
int IsCross(SListNode *list1,SListNode *list2); //判断 两个链表是否相交
SListNode *SListCrossNode(SListNode *list1,SListNode *list2); //求交点地址。
//判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】 
SListNode *SListIsCross(SListNode *list1,SListNode *list2);
ComplexNode* BuyComplexNode(int x);
ComplexNode *CopyComplexList(ComplexNode *list);
void SListUnionData(SListNode *list1,SListNode *list2);//求两个已排序单链表中相同的数据。
#endif //__SLISTNODE_H__
//从尾到头打印单链表 
//删除一个无头单链表的非尾节点（不能遍历链表） 
//在无头单链表的一个节点前插入一个节点（不能遍历链表） 
//单链表实现约瑟夫环(JosephCircle) 
//逆置/反转单链表 
//单链表排序（冒泡排序&快速排序） 
//合并两个有序链表,合并后依然有序 
//查找单链表的中间节点，要求只能遍历一次链表 
//查找单链表的倒数第k个节点，要求只能遍历一次链表 
//删除链表的倒数第K个结点 

//判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算 
//每个算法的时间复杂度&空间复杂度。 
//判断两个链表是否相交，若相交，求交点。（假设链表不带环） 
//判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】 
//复杂链表的复制。一个链表的每个节点，有一个指向next指针指向 
//下一个节点，还有一个random指针指向这个链表中的一个随机节点 
//或者NULL，现在要求实现复制这个链表，返回复制后的新链表。 
//求两个已排序单链表中相同的数据。 