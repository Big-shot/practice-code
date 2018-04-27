#include "SListNode.h"

SListNode* BuySListNode(DataType x)  //创建新节点
{
    SListNode* tmp;
    tmp=(SListNode*)malloc(sizeof(SListNode));
    if (NULL==tmp)
        return NULL;
    else
    {
        tmp->_data=x;
        tmp->_next=NULL;
        return tmp;
    }
}

void SListPrint(SListNode* pHead)  //打印链表
{
    if (NULL==pHead)
    {
        printf("空链表\n");
    }
    else
    {
        while (pHead)
        {
            printf("%d ",pHead->_data);
            pHead=pHead->_next;
        }
        printf("\n");
    }
    printf("\n");
}


void SListPushFront(SListNode** ppHead, DataType x)  //头插
{
    SListNode *newNode;
    newNode=BuySListNode(x);
    if (NULL==*ppHead)
    {
        newNode->_next=NULL;
        *ppHead=newNode;
    }
    else
    {
        newNode->_next=*ppHead;
        *ppHead=newNode;
    }
}

void SListPushBack(SListNode** ppHead, DataType x)  //尾插
{
    SListNode*newNode;
    SListNode*tmp;
    tmp=*ppHead;
    newNode=BuySListNode(x);
    if (NULL==*ppHead)
    {
        *ppHead=newNode;
       (*ppHead)->_next=NULL;
    }
    else
    {
        while (tmp->_next)
            tmp=tmp->_next;

        newNode->_next=NULL;
        tmp->_next=newNode;
    }
}

void SListPopBack(SListNode** ppHead)  //尾删
{
    SListNode *tmp=*ppHead;
    SListNode *cur;
    if (NULL==*ppHead || NULL==(*ppHead)->_next)
    {
        *ppHead=NULL;
        free(*ppHead);
    }
    else 
    {
        while (tmp->_next)
        {
            cur=tmp;
            tmp=tmp->_next;
        }

        tmp=NULL;
        cur->_next=tmp;
        free(tmp);
    }
}

void SListPopFront(SListNode** ppHead)  //头删
{
    SListNode *tmp;
    tmp=*ppHead;
    if (NULL==*ppHead || NULL==(*ppHead)->_next)
    {
        *ppHead=NULL;
        free(*ppHead);
        *ppHead=NULL;
    }
    else
    {
        *ppHead=(*ppHead)->_next;
        free(tmp);
        tmp=NULL;
    }
}

SListNode* SListFind(SListNode* pHead, DataType x)  //查找
{
    SListNode*tmp;
    tmp=pHead;
    if (NULL==tmp)
        return NULL;
    else
    {
       do
        {
            if (x==tmp->_data)
                return tmp;

            tmp=tmp->_next;
        }while(NULL!=tmp);
        return NULL;
    }
}

 void SListInsest(SListNode** ppHead, SListNode* pos, DataType x)  //随机插入 
 {
     SListNode*newNode;
     SListNode*tmp=*ppHead;
     newNode=BuySListNode(x);
     if (*ppHead==pos)
     {
         newNode->_next=*ppHead;
         *ppHead=newNode;
     }
     else
     {
         while (tmp->_next!=pos)
             tmp=tmp->_next;

         newNode->_next=pos;
         tmp->_next=newNode;
     }
 }

 void SListErase(SListNode** ppHead, SListNode* pos) //随机删除
 {
     SListNode*tmp;
     tmp=*ppHead;
     if (*ppHead==pos)
     {
         *ppHead=(*ppHead)->_next;
         free(tmp);
         tmp=NULL;
     }
     else
     {
         while (tmp->_next!=pos)
             tmp=tmp->_next;

         tmp->_next=pos->_next;
         free(pos);
         pos=NULL;
     }
 }

 void SListChange(SListNode**pphead,SListNode *pos,DataType x)  //链表的修改
 {
     SListNode *tmp;
     tmp=*pphead;
     if (NULL==*pphead)
         return;
     else if (NULL==tmp->_next)
         tmp->_data=x;
     else
     {
         while (pos->_next!= tmp->_next)
            tmp=tmp->_next;

         tmp->_data=x;
     }
 }

 void SListDestory(SListNode** ppHead)  //销毁链表
 {
     SListNode *tmp;
     while ((*ppHead))
     {
         tmp=(*ppHead);
         *ppHead=(*ppHead)->_next;
         free(tmp);
         tmp=NULL;
     }
 }


void EndToFirstPrintNode(SListNode*ps) //正常从头到尾打印
{
    SListNode *cur=NULL;
    SListNode *tail=NULL;
    while (ps != tail)
    {
        cur=ps;
        while (tail != cur->_next)
            cur=cur->_next;

        printf("%d ",cur->_data);
        tail=cur;
    }
}

  typedef struct SeqList  //顺序表
  {
      DataType *data;
      size_t size;
      size_t capicity;
  }SeqList;
  SeqList List;
 
  void CheckFullSeqlist(SeqList *Seq)  //顺序表的判容和扩容
  {
      DataType *tmp;
      if (Seq->size==Seq->capicity)
      {
          tmp=(DataType*)realloc(Seq->data,2*Seq->capicity*sizeof(DataType)+3*sizeof(DataType));
          if (NULL==tmp)
          {
              printf("扩容失败！");
          }
          else
          {
              Seq->capicity=Seq->capicity*2+3;
              Seq->data=tmp;
          }
      }
  }
 
  void PrintSList(SeqList *Seq)  //打印顺序表
  {
      DataType i=0;
      for (i=Seq->size-1;i>=0;i--)
      {
          printf("%d ",Seq->data[i]);
      }
  }
 
 void EndToFirstPrintSListNode(SListNode *ps)  //链表的从尾到头打印，用动态顺序表保存数据。
{
    size_t i = 0;
    while (ps)
    {
         CheckFullSeqlist(&List);
         List.data[i++]=ps->_data;
         List.size++;
         ps=ps->_next;
    }
    PrintSList(&List);
}

void EndToFirstPrintSListNodeR(SListNode *ps)//递归打印
{
    if (NULL != ps->_next) //递归结束条件
        EndToFirstPrintSListNodeR(ps->_next);  //子问题
    printf("%d ",ps->_data);
}

void EndToFirstPrintSListNodeNon(SListNode *ps)  //逆置链表
{
    SListNode *prev;
    SListNode *cur;
    SListNode *tmp;
    cur=ps;  //保存头结点
    prev=cur->_next;  //保存下一个节点
    cur->_next=NULL;  //头结点变为尾节点，next=NULL
    while (NULL != prev)  
    {
        tmp=prev->_next;
        prev->_next=cur;
        cur=prev;
        prev=tmp;
    }
    ps=cur;  //尾节点变为头节点
    SListPrint(ps);  //打印链表
}

void NoHeadSeqListDelete(SListNode *pos) //删除一个无头链表的非尾节点（不能遍历链表）
{
    SListNode*tmp; 
    assert(pos);
    tmp=pos->_next;  //保存pos->_next的值，方便一会销毁
    pos->_data=pos->_next->_data;
    pos->_next=pos->_next->_next;
    free(tmp);  //销毁pos->_next
    tmp=NULL;
}

//创建一个新节点，替换原来的插入节点的值，再把插入值赋给原节点
void NoHeadSeqListInsert(SListNode*pos,DataType x) //在无头链表的一个节点前插入一个节点（不能遍历链表）
{
    SListNode *newNode;
    newNode=BuySListNode(x);  //创建新节点
    newNode->_next=pos->_next;  
    pos->_next=newNode;
    newNode->_data=pos->_data;
    pos->_data=x;
}

SListNode *JosephCircle(SListNode*ps)  //约瑟夫环问题
{
    int k = 0;
    SListNode *tmp=ps;
    SListNode*cur=NULL;
    while (tmp->_next)
    {
        tmp=tmp->_next;
    }
    tmp->_next=ps;   //链接为一个环
    while (ps!=ps->_next)
    {
        ps=ps->_next;
        k++;
        if (k==2)  //每走三步杀一个
        {
            cur=ps->_next;
            ps->_next=ps->_next->_next;
            k=0;
            free(cur);
            cur=NULL;
        }
    }
    return ps;
}


SListNode* ReverseSeqList(SListNode *Seq) //逆置/反转单链表 
{
    SListNode *prev=Seq; //保存头节点
    SListNode *cur=prev->_next;  //保存第二个节点
    SListNode *tmp;
    assert(Seq);
    prev->_next=NULL;  //置空头节点的next,变成尾节点
    while (cur!=NULL)  //循环逆置 
    {
        tmp=cur->_next;  
        cur->_next=prev;
        prev=cur;
        cur=tmp;
    }
    Seq=prev;  //逆置后的头
    return Seq;
}


void SeqListSort(SListNode *Seq)//单链表排序（冒泡排序）
{
    SListNode *tail,*tmp=Seq;
    DataType flag=0;
    assert(Seq);
    if (Seq->_next==NULL||Seq==NULL)  //防止是空链表或者只有一个节点
    {
        return;
    }
    while (tmp!=NULL)  //找尾节点
    {
        tmp=tmp->_next;
    }
    tail=tmp;  
    while (tail!=Seq)
    {
        tmp=Seq;  //重置头节点
        while (tmp->_next!=tail)
        {
            if (tmp->_data>tmp->_next->_data)    //循环冒泡
            {
                flag=1;
                tmp->_data^=tmp->_next->_data;
                tmp->_next->_data^=tmp->_data;
                tmp->_data^=tmp->_next->_data;
            }
            tmp=tmp->_next;  //循环后移
        }
        if (flag==0)  //优化冒泡次数
        {
            break;
        }
        tail=tmp; //尾前移
    }
}


SListNode* SListMerge(SListNode *list1,SListNode *list2)//合并两个有序链表,合并后依然有序 
{
    SListNode *list,*tmp;
    assert(list1&&list2);
    if (list1->_data<list2->_data)  //找到两个链表中小的一个头节点
    {
        list=tmp=list1;
        list1=list1->_next;
    }
    else
    {
        list=tmp=list2;
        list2=list2->_next;
    }
    while (NULL!=list1 && NULL!=list2)  //循环比较，取两链表中小的节点链给list
    {
        if (list1->_data<list2->_data)
        {
            tmp->_next=list1;
            list1=list1->_next;
        }
        else
        {
            tmp->_next=list2;
            list2=list2->_next;
        }
        tmp=tmp->_next;
    }
    if (NULL==list1)  //取出剩下一个链表后面所有连接给list
    {
        tmp->_next=list2;
    }
    else
    {
        tmp->_next=list1;
    }
    return list; //返回新链表的头节点地址
}

 
SListNode* SListFindMidNode(SListNode* list) //查找单链表的中间节点，要求只能遍历一次链表
{
    SListNode *fast;
    SListNode *slow;
    assert(list);
    fast=slow=list; 
    //如果链表没节点，一个或者两个节点，直接返回头节点
    if (NULL==list || NULL==list->_next || NULL==list->_next->_next)      
    {
        return list;
    }
    while (fast) //快指针走到尾，慢指针走到中间。
    {
        fast=fast->_next->_next;  //快指针一次走两步 
        slow=slow->_next;  //慢指针一次走一步
    }
    return slow; //返回中间节点的地址
}

//查找单链表的倒数第k个节点，要求只能遍历一次链表
SListNode* SListFindTailKNode(SListNode *list, size_t k) 
{
    SListNode *fast;
    SListNode *slow;
    assert(list);
    fast=slow=list;
    while (--k)  //快指针走k-1步
    {
        if (NULL==fast) //少于k个节点，直接返回首地址
        {
            return list;
        }
        fast=fast->_next;  
    }
    while (fast->_next)  //快慢指针循环后移
    {
        slow=slow->_next;
        fast=fast->_next;
    }
    return slow;//返回倒数第k个节点的地址
}

 
void DeleteKNode(SListNode *list,size_t k)//删除链表的倒数第K个结点
{
    SListNode *fast,*slow,*tmp;
    assert(list);
    fast=slow=list;
    while (--k)  //快指针走k-1步
    {
        if (NULL==fast) //少于k个节点，直接返回首地址
        {
            return;
        }
        fast=fast->_next;  
    }
    while (fast->_next)  //快慢指针循环后移，找到第k个节点
    {
        tmp=slow;  //保存第k个节点的前继
        slow=slow->_next;
        fast=fast->_next;
    }
    tmp->_next=slow->_next;  //链接上第k个节点后面的节点
    free(slow);  //释放掉第k个节点
    slow=NULL;
}
//判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。
SListNode *CircleSListNode(SListNode *list) //时间复杂度为O(n) 
{
    SListNode *slow,*fast;
    assert(list);
    slow=fast=list;
    while (fast && fast->_next)  //快指针走两步，慢指针走一步，若带环，则一定在环内相遇
    {
        slow=slow->_next;
        fast=fast->_next->_next;
        if (fast == slow)
        {
            return slow;  //返回相遇点地址
        }}
    return NULL;
}

size_t CircleLengthSListNode(SListNode *ps) //求环长，时间复杂度为O(n) 
{
    SListNode *tmp;
    size_t i=0;
    assert(ps);
    tmp =ps;
    do  //从环的相遇点开始走，走一圈便是环长
    {
        tmp=tmp->_next; 
        ++i;
    } while (tmp!=ps);
    return i;
}

SListNode *CircleEntrySListNode(SListNode *list,SListNode *meet) //时间复杂度为O(1) 
{
    SListNode *start;
    assert(list);
    start=list;
    while (meet != start)
    {
        meet=meet->_next;
        start=start->_next;
    }
    return meet;
}

//判断两个链表是否相交，若相交，求交点。（假设链表不带环） 

int IsCross(SListNode* list1, SListNode* list2)  //判断是否相交，若尾节点地址相等则相交
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

SListNode *SListCrossNode(SListNode *list1,SListNode *list2)  //交点地址
{
    SListNode *tmp1,*tmp2;
    DataType k=0;
    assert(list1 && list2);
    tmp1=list1;
    tmp2=list2;
    if(1 != (IsCross(list1,list2)))
        return NULL;
    while (tmp1->_next)    //遍历两个链表，求出链表的长度 
    {
        tmp1=tmp1->_next;
        k++;
    }
    while (tmp2->_next)
    {
        tmp2=tmp2->_next;
        k--;
    }
    tmp1=list1;
    tmp2=list2;
    if (k>0)   //让两个链表走到长度相等处
    {
        while (k--)
        {
            tmp1=tmp1->_next;
        }
    }
    else
    {
        k=abs(k);
        while (k--)
        {
            tmp2=tmp2->_next;
        }
    }
    while (tmp1!=tmp2) //两个链表同时从相等处开始走，走到有地址相等且不等于空则相交
    {
        tmp1=tmp1->_next;
        tmp2=tmp2->_next;
    }
    return tmp1;
}

//判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】 
SListNode* SListIsCross(SListNode *list1,SListNode *list2) 
{
    SListNode *meet1,*meet2;;
    assert(list1&&list2);
    meet1=CircleSListNode(list1);  //判断 两个链表是否带环
    meet2=CircleSListNode(list2);
    if (meet1 && meet2 )  //两个链表带环
    {
        SListNode *tmp=meet1->_next;
        while (tmp!=meet1)  //判断是否带同一个环
        {
            if (tmp==meet2) //带同一个环
            {
                SListNode *cur1,*cur2;
                cur1=CircleEntrySListNode(list1,meet1);
                cur2=CircleEntrySListNode(list2,meet2);
                if (cur1==cur2)  //环外相交
                {
                    SListNode *tmp1,*tmp2;
                    tmp1=list1;
                    tmp2=list2;
                    while (tmp1 != cur1)
                    {
                        tmp1=tmp1->_next;
                    }
                    tmp1->_next=NULL;
                    while (tmp2 != cur2)
                    {
                        tmp2=tmp2->_next;
                    }
                    tmp2->_next=NULL;
                    return SListCrossNode(list1,list2);  //返回交点地址
                }
                else  //环内相交
                {
                    return cur1; //返回交点地址
                }
            }
            tmp=tmp->_next;
        }
        return NULL;   //带两个不同的环 
    }
    else if (NULL==meet1 && NULL==meet2) //两个链表都不带环
    {
        return SListCrossNode(list1,list2); 
    }
    else  //可能一个带环
    return NULL;
}

//复杂链表的复制。\
//一个链表的每个节点，有一个指向next指针指向下一个节点，\还有一个random指针指向这个链表中的一个随机节点\
//或者NULL，现在要求实现复制这个链表，返回复制后的新链表。


ComplexNode* BuyComplexNode(int x)
{
    ComplexNode *node=(ComplexNode *)malloc(sizeof(ComplexNode));
    assert(node);
    node->data=x;
    node->next=NULL;
    node->random=NULL;
    return node;
}

ComplexNode *CopyComplexList(ComplexNode *list)
{
    ComplexNode *tmp,*newList=NULL,*tail=NULL;
    assert(list);
    tmp=list;
    while (tmp)   //copy原链表的数据
    {
        ComplexNode *cur=tmp->next;
        ComplexNode *node=BuyComplexNode(tmp->data);
        tmp->next=node;
        node->next=cur;

        tmp=cur;
    }

    tmp=list;
    while (tmp)  //copy原料表的random 
    {
        ComplexNode *cur=tmp->next;
        if (tmp->random)
        {
            cur->random=tmp->random->next;
        }

        tmp=tmp->next->next;
    }
    
    tmp=list; 
    while (tmp)  //拆解下新链表 
    {
        ComplexNode *next=tmp->next;
        ComplexNode *nextNext=next->next;
        
        tmp->next=nextNext;
        if (NULL==newList)
        {
            newList=tail=next;
        }
        else
        {
            tail->next=next;
            tail=next;
        }
        tmp=nextNext;
    }
    return newList;
}

void ComplexPrint(ComplexNode *list)
{
    assert(list);
    while (list)
    {
        ComplexNode* random = list->random;
        int data = random ? random->data : 0;
        printf("%d:%d->", list->data, data);

        list = list->next;
    }

    printf("NULL\n");
}

//求两个已排序单链表中相同的数据
void SListUnionData(SListNode *list1,SListNode *list2)
{
    SListNode *tmp1,*tmp2;
    assert(list1 && list2);
    tmp1=list1;
    tmp2=list2;
    while (tmp1 && tmp2)
    {
        if (tmp1->_data<tmp2->_data)  //小的指针向前走一步
        {
            tmp1=tmp1->_next;
        }
        else if(tmp1->_data>tmp2->_data)
        {
            tmp2=tmp2->_next;
        }
        else  //数据相等时同时走
        {
            printf("%d ",tmp2->_data);
            tmp1=tmp1->_next;
            tmp2=tmp2->_next;
        }
    }
    printf("\n");
}