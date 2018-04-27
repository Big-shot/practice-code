#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

typedef int DataType;

typedef struct SListNode
{
	struct SListNode* _next;
	DataType _data;
}SListNode;


SListNode* BuySListNode(DataType x);
void SListPrint(SListNode* pHead);

void SListPushBack(SListNode** ppHead, DataType x);
void SListPopBack(SListNode** ppHead);
void SListPushFront(SListNode** ppHead, DataType x);
void SListPopFront(SListNode** ppHead);

SListNode* SListFind(SListNode* pHead, DataType x);

// 在pos的前面进行插入
void SListInsert(SListNode** ppHead, SListNode* pos, DataType x);
void SListErase(SListNode** ppHead, SListNode* pos);


///////////////////////////////////////////////////////////

void SListPrint(SListNode* pHead)
{
	SListNode* cur = pHead;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}

	printf("\n");
}

SListNode* BuySListNode(DataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->_data = x;
	node->_next = NULL;

	return node;
}

void SListPushBack(SListNode** ppHead, DataType x)
{
	assert(ppHead);

	if (*ppHead == NULL)
	{
		*ppHead = BuySListNode(x);
	}
	else
	{
		SListNode* tail = *ppHead;
		while (tail->_next)
		{
			tail = tail->_next;
		}

		tail->_next = BuySListNode(x);
	}
}

//void SListPopBack(SListNode** ppHead)
//{
//	assert(ppHead);
//
//	if (*ppHead == NULL)
//	{
//		return;
//	}
//	else
//	{
//		SListNode* prev = NULL;
//		SListNode* tail = *ppHead;
//		while (tail->_next)
//		{
//			prev = tail;
//			tail = tail->_next;
//		}
//
//		if (prev == NULL)
//			*ppHead = NULL;
//		else
//			prev->_next = NULL;
//
//		free(tail);
//	}
//}

void SListPopBack(SListNode** ppHead)
{
	assert(ppHead);

	// 1.空
	// 2.一个节点
	// 3.一个以上节点
	if (*ppHead == NULL)
	{
		return;
	}
	else if ((*ppHead)->_next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *ppHead;
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}

		prev->_next = NULL;
		free(tail);
	}
}

void SListPushFront(SListNode** ppHead, DataType x)
{
	//1.空
	//2.非空
	if(*ppHead == NULL)
	{
		*ppHead = BuySListNode(x);
	}
	else
	{
		SListNode* newNode = BuySListNode(x);
		newNode->_next = *ppHead;
		*ppHead = newNode;
	}
}

void SListPopFront(SListNode** ppHead)
{
	// 1.空
	// 2.一个
	// 3.一个以上
	/*if(*ppHead == NULL)
	{
		return;
	}
	else if ((*ppHead)->_next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		SListNode* next = (*ppHead)->_next;
		free(*ppHead);
		*ppHead = next;
	}*/

	if(*ppHead == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*ppHead)->_next;
		free(*ppHead);
		*ppHead = next;
	}
}


SListNode* SListFind(SListNode* pHead, DataType x)
{
	SListNode* cur = pHead;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}

		cur = cur->_next;
	}

	return NULL;
}

// 在pos的前面进行插入
void SListInsert(SListNode** ppHead, SListNode* pos, DataType x)
{
	// 1.正常中间插入（pos为尾是一样的）
	// 2.头
	assert(ppHead && pos);
	if (pos == *ppHead)
	{
		SListPushFront(ppHead, x);
	}
	else
	{
		SListNode* newNode = BuySListNode(x);
		SListNode* prev = *ppHead;
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}

		// prev newNode pos
		prev->_next = newNode;
		newNode->_next = pos;
	}
}

void SListErase(SListNode** ppHead, SListNode* pos)
{
	assert(ppHead && pos);

	if (*ppHead == pos)
	{
		SListPopFront(ppHead);
	}
	else
	{
		SListNode* prev = *ppHead;
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}

		prev->_next = pos->_next;
		free(pos);
	}
}

void Test1()
{
	SListNode* list = NULL;
	SListPushFront(&list, 0);
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushFront(&list, 0);
	SListPrint(list);

	SListPopBack(&list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPrint(list);
}

void Test2()
{
	SListNode* pos = NULL;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(list);

	pos = SListFind(list, 3);
	SListInsert(&list, pos, 30);
	SListPrint(list);
}

////////////////////////////////////////////////////////////
// 链表面试题

// O(N*N)  O(1)
void SLitsPrintTailToHead(SListNode* pHead)
{
	SListNode* tail = NULL;

	while (tail != pHead)
	{
		SListNode* cur = pHead;
		while (cur->_next != tail)
		{
			cur = cur->_next;
		}
		printf("%d ", cur->_data);

		tail = cur;
	}

	printf("\n");
}

// O(N) O(N)
void SListPrintTailToHeadR(SListNode* pHead)
{
	if(pHead == NULL)
		return;

	SListPrintTailToHeadR(pHead->_next);
	printf("%d ", pHead->_data);
}

void Test3()
{
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);

	SListPrintTailToHeadR(list);
}

void DelNonTailNode(SListNode* pos)
{
	SListNode* next;
	assert(pos && pos->_next);

	next = pos->_next;
	pos->_data = next->_data;
	pos->_next = next->_next;
	free(next);
}

void InsertFrontNode(SListNode* pos, DataType x)
{
	SListNode* next;
	SListNode* newNode;
	assert(pos);
	next = pos->_next;

	// pos newNode next 
	newNode = BuySListNode(pos->_data);
	pos->_next = newNode;
	newNode->_next = next;
	pos->_data = x;
}


// pHead是循环链表
SListNode* JosephCircle(SListNode* pHead, int k)
{
	SListNode* cur = pHead;
	SListNode* next;
	while (cur->_next != cur)
	{
		int count = k;
		while (--count)//count--
		{
			cur = cur->_next;
		}

		// 替换法
		next = cur->_next;
		cur->_data = next->_data;
		cur->_next = next->_next;
		free(next);
	}

	return cur;
}

void Test4()
{
	SListNode* list = NULL;
	SListNode* tail;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	
	tail = SListFind(list, 5);
	tail->_next = list;

	printf("最后的幸存者:%d\n", JosephCircle(list, 3)->_data);
}

//void ReverseList(SListNode** ppList)
//{
//	SListNode* n1, *n2, *n3;
//	if (*ppList == NULL || (*ppList)->_next == NULL)
//	{
//		//return list;
//		return;
//	}
//
//	n1 = *ppList;
//	n2 = n1->_next;
//	n3 = n2->_next;
//
//	n1->_next = NULL;
//	while (n2)
//	{
//		n2->_next = n1;
//
//		n1 = n2;
//		n2 = n3;
//
//		if(n3)
//			n3 = n3->_next;
//	}
//
//	*ppList = n1;
//	//return n1;
//}


SListNode* ReverseList(SListNode* list)
{
	SListNode* cur = list;
	SListNode* newList = NULL;
	while (cur)
	{
		SListNode* next = cur->_next;

		// 头插
		cur->_next = newList;
		newList = cur;

		cur = next;
	}

	return newList;
}

void Test5()
{
	SListNode* list = NULL;
	SListNode* newList;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);

	newList = ReverseList(list);
	SListPrint(newList);
}

void SListBubbleSort(SListNode* list)
{
	SListNode* tail = NULL;

	while (tail != list)
	{
		int exchange = 0;
		// 单趟冒泡
		SListNode* cur = list;
		SListNode* next = list->_next;
		while (next != tail)
		{
			if (cur->_data > next->_data)
			{
				DataType tmp = cur->_data;
				cur->_data = next->_data;
				next->_data = tmp;

				exchange = 1; 
			}

			cur = cur->_next;
			next = next->_next;
		}

		if (exchange == 0)
		{
			break;
		}

		tail = cur;
	}
}

void Test6()
{
	SListNode* list = NULL;
	SListPushBack(&list, 10);
	SListPushBack(&list, 22);
	SListPushBack(&list, 3);
	SListPushBack(&list, 40);
	SListPushBack(&list, 5);

	SListBubbleSort(list);	
	SListPrint(list);
}

// 升序
SListNode* SListMerge(SListNode* list1, SListNode* list2)
{
	SListNode* list, *tail;
	if (list1 == NULL)
		return list2;

	if (list2 == NULL)
		return list1;

	// 要尾插，先取一个节点下来做头
	if (list1->_data < list2->_data)
	{
		list = tail = list1;
		list1 = list1->_next;
	}
	else
	{
		list = tail = list2;
		list2 = list2->_next;
	}

	// 取小的尾插
	while (list1 && list2)
	{
		if (list1->_data < list2->_data)
		{
			tail->_next = list1;
			list1 = list1->_next;
		}
		else
		{
			tail->_next = list2;
			list2 = list2->_next;
		}

		tail = tail->_next;
	}

	if (list1)
		tail->_next = list1;
	
	if (list2)
		tail->_next = list2;

	return list;
}

void Test7()
{
	SListNode* list1, *list2, *list; 
	list1 = NULL;
	SListPushBack(&list1, 1);
	SListPushBack(&list1, 3);
	SListPushBack(&list1, 3);
	SListPushBack(&list1, 5);
	SListPushBack(&list1, 9);
	SListPrint(list1);

	list2 = NULL;
	SListPushBack(&list2, 2);
	SListPushBack(&list2, 3);
	SListPushBack(&list2, 4);
	SListPushBack(&list2, 6);
	SListPushBack(&list2, 8);
	SListPrint(list2);

	list = SListMerge(list1, list2);
	SListPrint(list);
}

SListNode* FindMidNode(SListNode* list)
{
	SListNode* fast, *slow;
	fast = slow = list;

	while (fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
	}

	return slow;
}

SListNode* FindTailKNode(SListNode* list, size_t k)
{
	SListNode* fast, *slow;
	slow = list;
	fast = list;

	while (k--)
	{
		if (fast == NULL)
			return NULL;

		fast = fast->_next;
	}

	while (fast)
	{
		slow = slow->_next;
		fast = fast->_next;
	}

	return slow;
}

SListNode* IsCycle(SListNode* list)
{
	SListNode* slow, * fast;
	slow = list;
	fast = list;

	while (fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;

		if (slow == fast)
		{
			return slow;
		}
	}

	return NULL;
}

int GetCycleLen(SListNode* meet)
{
	int n = 1;
	SListNode* cur = meet;
	while (cur->_next != meet)
	{
		++n;
		cur = cur->_next;
	}

	return n;
}

SListNode* GetEntryNode(SListNode* list, SListNode* meet)
{
	while (list != meet)
	{
		list = list->_next;
		meet = meet->_next;
	}

	return list;
}

void Test8()
{
	SListNode* entry, *tail, *meet;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPushBack(&list, 6);

	printf("IsCycle？:%p\n", IsCycle(list));

	// 构建成带环
	tail = SListFind(list, 6);
	entry = SListFind(list, 3);
	tail->_next = entry;

	meet = IsCycle(list);
	printf("IsCycle？:%d\n", meet->_data);
	printf("Cycle Len？:%d\n", GetCycleLen(meet));
	printf("Cycle Entry？:%d\n", GetEntryNode(list, meet)->_data);
}

int IsCross(SListNode* list1, SListNode* list2)
{
	while (list1 && list1->_next)
	{
		list1 = list1->_next;
	}

	while (list2 && list2->_next)
	{
		list2 = list2->_next;
	}

	if (list1 == list2 && list1 != NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

SListNode* GetCrossNode(SListNode* list1, SListNode* list2)
{
	int n1 = 0, n2 = 0, gap = 0;
	SListNode* cur1 = list1;
	SListNode* cur2 = list2;
	SListNode* longList, *shortList;
	while (cur1)
	{
		cur1 = cur1->_next;
		n1++;
	}

	while (cur2)
	{
		cur2 = cur2->_next;
		n2++;
	}

	longList = list1;
	shortList = list2;
	if (n1 < n2)
	{
		longList = list2;
		shortList = list1;
	}

	gap = abs(n1-n2);
	while (gap--)
		longList = longList->_next;

	while (shortList != longList)
	{
		shortList = shortList->_next;
		longList = longList->_next;
	}

	return shortList;
}


void Test9()
{
	SListNode* node11, *node22;
	SListNode* node1 = BuySListNode(1);
	SListNode* node2 = BuySListNode(2);
	SListNode* node3 = BuySListNode(3);
	SListNode* node4 = BuySListNode(4);
	SListNode* node5 = BuySListNode(5);
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	node4->_next = node5;

	node11 = BuySListNode(11);
	node22 = BuySListNode(22);
	node11->_next = node22;	
	node22->_next = node4;

	printf("Is Cross?%d\n", IsCross(node1, node11));
	printf("Cross Node?%d\n", GetCrossNode(node1, node11)->_data);
}

typedef struct ComplexNode
{
	int _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
}ComplexNode;

ComplexNode* BuyComplexNode(int x)
{	
	ComplexNode* node = (ComplexNode*)malloc(sizeof(ComplexNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;
	node->_random = NULL;

	return node;
}

ComplexNode* CopyComplexList(ComplexNode* list)
{
	// 拷贝链表，连接在原链表的后面
	ComplexNode* cur = list;
	ComplexNode* copyList = NULL, *tail = NULL;
	while (cur)
	{
		ComplexNode* next = cur->_next;
		ComplexNode* newNode = BuyComplexNode(cur->_data);

		cur->_next = newNode;
		newNode->_next = next;

		cur = next;
	}

	// 置random
	cur = list;
	while (cur)
	{
		ComplexNode* next = cur->_next;
		if (cur->_random)
			next->_random = cur->_random->_next;

		cur = cur->_next->_next;
	}

	// 拆解链表
	cur = list;
	while (cur)
	{
		ComplexNode* next = cur->_next;
		ComplexNode* nextNext = next->_next;

		cur->_next = nextNext;

		if (copyList == NULL)
		{
			copyList = tail = next;
		}
		else
		{
			tail->_next = next;
			tail = next;
		}

		cur = nextNext;
	}

	return copyList;
}

void PrintComplex(ComplexNode* list)
{
	while (list)
	{
		ComplexNode* random = list->_random;
		int data = random ? random->_data : 0;
		printf("%d:%d->", list->_data, data);

		list = list->_next;
	}

	printf("NULL\n");
}

void Test10()
{
	ComplexNode* copyList = NULL;
	ComplexNode* n1 = BuyComplexNode(1);
	ComplexNode* n2 = BuyComplexNode(2);
	ComplexNode* n3 = BuyComplexNode(3);
	ComplexNode* n4 = BuyComplexNode(4);
	n1->_next = n2;
	n2->_next = n3;
	n3->_next = n4;
	n4->_next = NULL;
	n1->_random = n4;
	n2->_random = n1;
	n3->_random = NULL;
	n4->_random = n4;

	copyList = CopyComplexList(n1);
	PrintComplex(n1);
	PrintComplex(copyList);
}


void UnionSet(SListNode* list1, SListNode* list2)
{
	while (list1 && list2)
	{
		if (list1->_data < list2->_data)
		{
			list1 = list1->_next;
		}
		else if (list1->_data > list2->_data)
		{
			list2 = list2->_next;
		}
		else
		{
			printf("%d ", list1->_data);
			list1 = list1->_next;
			list2=  list2->_next;
		}
	}

	printf("\n");
}

void Test11()
{
	SListNode* list1 = NULL, *list2 = NULL;
	SListPushBack(&list1, 1);
	SListPushBack(&list1, 3);
	SListPushBack(&list1, 4);
	SListPushBack(&list1, 5);
	SListPushBack(&list1, 6);

	SListPushBack(&list2, 2);
	SListPushBack(&list2, 3);
	SListPushBack(&list2, 5);
	SListPushBack(&list2, 7);
	SListPushBack(&list2, 9);

	UnionSet(list1, list2);
}