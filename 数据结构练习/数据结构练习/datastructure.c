#include"datastructure.h"

LinkNode* BuyNode(DataType x)
{
	LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;
	return node;
}

void LinkNodeInsert(LinkNode **list, DataType x)
{
	assert(list);

}

void LinkNodeDelete(LinkNode **list, DataType x);
void LinkNodeDestory(LinkNode *list);
