#include"practice.h"

void SeqListInit(SeqList *list)
{
    assert(list);
    list->_capacity = 0;
    list->_size = 0;
    list->_data = NULL;
}

void PrintSeqList(SeqList *list) //��ӡ˳���
{
    int i = 0;
    assert(list);
    for(i=0; i<list->_size; i++)
        printf("%d ",list->_data[i]);
    printf("\n");
}

void PushSeqlist(SeqList* list,Datatype pos,Datatype x) //����Ԫ��
{
    int i = list->_size;
    assert(list);
    if (pos>list->_size)
        return;
    CheckSeqCapacity(list);
    while (i != pos)
    {
        list->_data[i] = list->_data[i-1];
        i--;
    }
    list->_data[i] = x;
    list->_size++;
}

void CheckSeqCapacity(SeqList *list)
{
    assert(list);
    if (list->_capacity == list->_size)
    {
        Datatype *tmp = (Datatype*)realloc(list->_data,(list->_capacity * 2+3)*sizeof(Datatype));
        assert(tmp);
        list->_data = tmp;
        list->_capacity = list->_capacity*2+3;
    }
}

void DeleteSeqlist(SeqList *list,Datatype x) //ɾ��Ԫ��
{
    int pos = SearchSeqlist(list,x);
    assert(list);
    if (pos>=0)
    {
        int i = pos;
        while (i < list->_size-1)
        {
            list->_data[i] = list->_data[i+1];
            i++;
        }
        list->_size--;
    }
}

size_t SeqlistSize(SeqList *list)//��˳���Ԫ�ظ���
{
    assert(list);
    return list->_size;
}

Datatype SearchSeqlist(SeqList *list,Datatype x) //��˳����в���Ԫ��
{
    int i = 0;
    assert(list);
    for(i=0; i<list->_size; i++)
    {
        if (list->_data[i] == x)
            return i;
    }
    return -1;
}

void ChangeSeqlist(SeqList *list,Datatype x,Datatype dst) //�޸�Ԫ��
{
    int  pos = SearchSeqlist(list,x);
    assert(list);
    if (pos>=0)
        list->_data[pos] = dst;
}

void ClearSeqlist(SeqList *list) //���˳���
{
    assert(list);
    list->_size = 0;
    list->_capacity = 0;
    free(list->_data);
    list->_data = NULL;
}

//////////////////////////////////////////////////////////////////////////

LinkList* BuyListNode(Datatype x) //�����ڵ�
{
    LinkList *newNode = (LinkList *)malloc(sizeof(LinkList));
    assert(newNode);
    newNode->_next = NULL;
    newNode->_data = x;
    return newNode;
}

void PrintLinkList(LinkList *phead) //�����ӡ
{
    assert(phead);
    while (phead)
    {
        printf("%d ",phead->_data);
        phead = phead->_next;
    }
    printf("\n");
}

void LinkListInsert(LinkList **pphead,LinkList *pos,Datatype x) //����Ĳ��루����ͷ��,������룩
{
    LinkList *newNode = BuyListNode(x);
    assert(pphead);
    if (*pphead == NULL)
    {
        newNode->_next = *pphead;
        *pphead = newNode;
    }
    else
    {
        pos->_data ^= newNode->_data;
        newNode->_data ^= pos->_data;
        pos->_data ^= newNode->_data;
        newNode->_next = pos->_next;
        pos->_next = newNode;
    }
}

void LinkListDelete(LinkList **pphead,Datatype x)//����Ԫ�ص�ɾ��
{
    LinkList *tmp =LinkListSearch(*pphead,x);
    LinkList *phead = *pphead;
    assert(pphead);
    if (tmp == *pphead) //ͷɾ
        *pphead = tmp->_next;
    else if (tmp)
    {
        if (tmp->_next)  //�м�ɾ��
        {
            LinkList *cur = tmp->_next;
            tmp->_data = cur->_data;
            tmp->_next = cur->_next;
            free(cur);
            cur = NULL;
        }
        else //βɾ
        {
            LinkList * cur = NULL;
            while (phead->_next)
            {
                cur = phead;
                phead = phead->_next;
            }
            cur->_next = NULL;
            free(tmp);
            tmp = NULL;
        }
    }
}

LinkList *LinkListSearch(LinkList *phead,Datatype x) //����Ԫ�ز���
{
    assert(phead);
    while (phead)
    {
        if (phead->_data == x)
        {
            return phead;
        }
        phead = phead->_next;
    }
    return NULL;
}

void LinkListChange(LinkList *phead,Datatype x,Datatype y) //����Ԫ���޸�
{
    LinkList *tmp = LinkListSearch(phead,x);
    assert(phead);
    if (tmp)
        tmp->_data = y;
}

void LinkListSort(LinkList *phead)//��������ѡ������
{
    int len = 0;
    int i = 0;
    LinkList *tmp = phead,*flag = NULL;
    assert(phead);
    while(tmp) //Ԫ�ظ���
    {
        len++;
        tmp = tmp->_next;
    }
    while(--len)
    {
        int num = 0;
        LinkList *cur = NULL;
        tmp = phead;
        flag = tmp;
        for (i = 0; i<len; i++)
        {
            cur = tmp->_next;
            if (flag->_data > cur->_data)
                flag = cur;  //��¼�����
            tmp = tmp->_next;
        }
        num = flag->_data;  //��������������
        flag->_data = tmp->_data;
        tmp->_data  = num;
    }
}

LinkList *LinkListReverse(LinkList *pphead) //�����������
{
    assert(pphead);
    if (pphead->_next) //��1�����Ͻڵ�
    {
        LinkList *cur = pphead;
        LinkList *next = cur->_next;
        cur->_next = NULL;
        while (next)  //���ù���
        {
            LinkList *tmp = next->_next;
            next->_next = cur;
            cur = next;
            next = tmp;
        }
        return cur; //�����µ�ͷ�ڵ�
    }
    else
        return pphead;
}

void PrintLinkListrR(LinkList *phead) //�ݹ��ӡ
{
    if (phead == NULL)
        return;
    PrintLinkListrR(phead->_next);
    printf("%d ",phead->_data);
}

void PrintLinkListTail(LinkList *phead)  //����βָ��ǰ�����δ�ӡ
{
    LinkList *tail = NULL;
    LinkList *tmp = phead;
    assert(phead);
    while (tail != phead)
    {
        tmp = phead;
        while (tmp->_next != tail)
            tmp = tmp->_next;
        printf("%d ",tmp->_data);
        tail = tmp;
    }
}

//2��ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ������� 
void LinkListNoHead(LinkList *pos)
{
    LinkList *tmp = pos->_next; //����pos��һ��λ��
    assert(pos);
    pos->_data = tmp->_data;
    pos->_next = tmp->_next;
    free(tmp);
    tmp = NULL;
}

//3������ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ������� 
void LinkListNoHeadInsert(LinkList *pos,Datatype x)
{
    LinkList *newNode = BuyListNode(x);
    assert(pos);
    newNode->_next = pos->_next; //����ڵ�
    pos->_next = newNode;
    //��������
    pos->_data ^= newNode->_data;
    newNode->_data ^= pos->_data;
    pos->_data ^= newNode->_data;
}

//4��������ʵ��Լɪ��(JosephCircle)
void LinkListJosephCircle(LinkList *phead,Datatype x)
{
    LinkList *tail = phead;
    int count = 0;
    assert(phead);
    while (tail->_next)
        tail = tail->_next;
    tail->_next = phead; //���ɻ�
    while (phead != phead->_next)
    {
        if (count == (x-1)) //����ָ��Ԫ�ؾ�ɾ����Ԫ��
        {
            LinkList *tmp = phead->_next;
            phead->_next = tmp->_next;
            count = 0;
            free(tmp);
            tmp = NULL;
        }
        phead = phead->_next;
        count++;
    }
    printf("%d \n",phead->_data); //���ʣ�µ�һ��Ԫ��
}

//6������������ð������ 
void Swap(int* p1,int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void LinkListBubbleSort(LinkList *phead)
{
    int flag = 1;
    LinkList *tail =NULL;
    LinkList *tmp = phead;
    assert(phead);
    while (tmp->_next != tail) //ð���ܴ���
    {
        LinkList *cur = phead;
        while (cur->_next != tail) //ÿ��ð�ݶ��ٸ���
        {
            if (cur->_data > cur->_next->_data)
            {
                flag = 0;
                Swap(&cur->_data,&cur->_next->_data);
            }
            cur = cur->_next;
        }
        tail = cur; //��ָ��ǰ��
        if (flag) //�Ż�ð�ݴ���
            return;
    }
}

//7���ϲ�������������,�ϲ�����Ȼ���� 
LinkList *CombineDoublelinklist(LinkList *list1,LinkList *list2)
{
    LinkList *list = NULL;
    LinkList *tail = NULL;
    assert(list1 && list2);
    if(list1->_data < list2->_data)  //�ҳ�С��һ������ͷ
    {
        list = list1;
        list1 = list1->_next;
    }
    else
    {
        list = list2;
        list2 = list2->_next;
    }
    tail = list;
    while (list1->_next && list2->_next)
    {
        if(list1->_data < list2->_data) //��С��һ������tail����
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
    if (list1->_next) //�Ѳ�Ϊ�յ�������������
        tail->_next = list1;
    else
        tail->_next = list2;
    return list; 
}


//8�����ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
LinkList *SearchMidNode(LinkList *phead)
{
    LinkList *fast = phead;
    LinkList *slow = phead;
    assert(phead);
    while (fast && fast->_next )  //��ָ����ٶ�����ָ��Ķ�����
    {
        fast = fast->_next->_next;
        slow = slow->_next;
    }
    return slow;
}

//9�����ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
LinkList *SearchKNode(LinkList *phead,Datatype k)
{
    LinkList *fast = phead;
    LinkList *slow = phead;
    assert(phead);
    while (k--) //����k��
        fast = fast->_next;
    while (fast) //��ͬʱ��
    {
        fast = fast->_next;
        slow = slow->_next;
    }
    return slow;
}

//10��ɾ������ĵ�����K����� 
void DeleteKNode(LinkList *phead,Datatype k)
{
    LinkList *fast = phead;
    LinkList *slow = phead;
    LinkList *tmp = slow;
    assert(phead);
    while (k--) //����k��
        fast = fast->_next;
    while (fast) //��ͬʱ��
    {
        tmp = slow;
        fast = fast->_next;
        slow = slow->_next;
    }
    tmp->_next = slow->_next;
    free(slow);
    slow = NULL;
}

// 1���жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿
void CreateCircle(LinkList *list,LinkList *entry) //����һ�������ڲ���
{
    assert(list);
    while (list->_next)
    {
        list = list->_next;
    }
    list->_next = entry;  //���ɻ�
}
LinkList *CheckIsCircle(LinkList *phead) //�������ػ��������㣬��ֹ����null
{
    LinkList *fast = phead;
    LinkList *slow = phead;
    assert(phead);
    do
    {
        fast = fast->_next->_next;
        slow = slow->_next;
    }while(fast != slow && fast);
    if (fast)
        return slow;
    return NULL;
}

int CircleSize(LinkList *phead,LinkList *meet)
{
    int size = 0;
    LinkList *tmp = meet;
    assert(phead);
    do
    {
        tmp = tmp->_next;
        size++;
    }while (meet != tmp);
    return size;
}

LinkList *CircleEntry(LinkList *phead,LinkList* meet)
{
    LinkList *start = phead;
    assert(phead);
    while (start != meet)
    {
        start = start->_next;
        meet = meet->_next;
    }
    return meet;
}

// 2���ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
void CreateTogetherNode(LinkList *list1,LinkList *list2,LinkList *node1,LinkList *node2) //�����ཻ�������ڲ���
{
    assert(list1 && list2);
    node2->_next = node1;
}
static LinkList *LinkListtTogetherNode(LinkList *list1,LinkList *list2)  //�󽻵��ַ
{
    int m1 = 0;
    int m2 = 0;
    LinkList *tmp1 = list1;
    LinkList *tmp2 = list2;
    while (tmp1 || tmp2) //������������ܳ��� 
    {
        if (tmp1)
        {
            m1++;
            tmp1 = tmp1->_next;
        }
        if (list2)
        {
            m2++;
            tmp2 = tmp2->_next;
        }
    }
    tmp1 = list1;
    tmp2 = list2;
    if (m1>m2) //��������
    {
        int len = m1 - m2;
        while (len--)
            tmp1 = tmp1->_next;
    }
    else
    {
        int len = m2 - m1;
        while (len--)
            tmp2 = tmp2->_next;
    }
    while (tmp1 != tmp2) //һ������ͬʱ�ߣ��ߵ����㴦ͣ�¡�
    {
        tmp1 = tmp1->_next;
        tmp2 = tmp2->_next;
    }
    return tmp1; //���ؽ����ַ
}

LinkList *LinkListSameNode(LinkList*list1,LinkList *list2)  //�ж��Ƿ��ཻ���ཻ���ؽ��㣬���򷵻ؿ�
{
    LinkList *m1 = list1;
    LinkList *m2 = list2;
    assert(m1 && list2);
    while (m1->_next)
        m1 = m1->_next;
    while (m2->_next)
        m2 = m2->_next;
    if(m1 == m2) //�ཻ
    {
        return LinkListtTogetherNode(list1,list2);
    }
    return NULL;
}

// 3���ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 
//(1�����ཻ 2���ཻ������ 3���ཻ������a�������ཻ b�������ཻ�� )
static LinkList *LinkListCircleNode(LinkList *list1,LinkList *meet1,LinkList *list2,LinkList *meet2) //������ཻ�Ľ���
{
    LinkList *m1 = CircleEntry(list1,meet1); //�����ڵ�ַ
    LinkList *m2 = CircleEntry(list2,meet2);
    assert(list1 && list2 && meet1 && meet2);
    if (m1 != m2)//�����ཻ
        return m1;  
    else  //�����ཻ
    {
        m1 = NULL;
        m2 = NULL;
        return LinkListtTogetherNode(list1,list2);
    }
}
LinkList *LinkListSameNodeCircle(LinkList *list1,LinkList *list2)
{
    LinkList *node = NULL;
    LinkList *meet1 =  CheckIsCircle(list1);
    LinkList *meet2 =  CheckIsCircle(list2);
    assert(list1 && list2);
    if (meet1 && meet2) //������
    {
        LinkList *tmp1 = meet1->_next;
        LinkList *tmp2 = meet2;
        while (tmp1 != meet1)
        {
            if (tmp1 == tmp2) //�����ཻ
            {
                node = LinkListCircleNode(list1,meet1,meet2,list2);
                return node;
            }
            tmp1 = tmp1->_next;
        }
        return NULL; //�������ཻ

    }
    else if (meet1 == NULL && meet2 == NULL) //������������
    {
        node = LinkListSameNode(list1,list2);
        if(node) //�������ཻ
            return node;
        return NULL;   //���������ཻ
    }
    else //�������ཻ�����
        return NULL;
}

// 4����������������������ͬ�����ݡ�
void TwoListSamedata(LinkList *list1,LinkList *list2)
{ 
    assert(list1 && list2);
    LinkListBubbleSort(list1);  //����������
    LinkListBubbleSort(list2);
    while (list1 && list2)
    {
        if (list1->_data < list2->_data)
            list1 = list1->_next;
        else if(list2->_data< list1->_data)
            list2 = list2->_next;
        else
        {
            printf("%d ",list2->_data); //��Ⱦʹ�ӡ��������Ȼ����Ҳ���԰���ȵ����ݱ���������������ӡ
            list1 = list1->_next;
            list2 = list2->_next;
        }
    }
    printf("\n");
}

void DestoryLinkList(LinkList *list) //���������
{
    LinkList *tmp = list;
    while (list)
    {
        list = tmp;
        tmp = tmp->_next;
        free(list);
        list = NULL;
    }
}
 
 //////////////////////////////////////////////////////////////////////////
  //˫����Ĵ��������룬��ӡ��
  doublelist * BuyListDouNode(Datatype x)
  {
       doublelist *newNode = (doublelist*)malloc(sizeof(doublelist));
       assert(newNode);
       newNode->_data = x;
       newNode->_next = NULL;
       newNode->_prev = NULL;

       return newNode;
  }
  
void InsertData(doublelist **list,Datatype x)
{
   doublelist *newNode = BuyListDouNode(x);
   if (*list== NULL)
   {
       newNode->_next = *list;
       *list = newNode;
       newNode->_prev = *list;
    
   }
   else
   {
       newNode->_next = (*list)->_next;
       (*list)->_next = newNode;
       newNode->_prev = *list;
   }
}
   
void PrintList(doublelist *list)
{
  doublelist* tmp = list;
  do
  {
      if(list)
           printf("%d ",list->_data);
       else
           return;
      list = list->_next;
  }while(list != tmp);
}
