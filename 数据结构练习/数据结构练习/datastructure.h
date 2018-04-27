
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct Node
{
	struct Node* _next;
	DataType _data;
}LinkNode;

LinkNode* BuyNode(DataType x);
void LinkNodeInit(LinkNode **list);
void LinkNodeInsert(LinkNode **list, DataType x);
void LinkNodeDelete(LinkNode **list, DataType x);
void LinkNodeDestory(LinkNode *list);

