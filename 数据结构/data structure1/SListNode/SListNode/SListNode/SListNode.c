#include "SListNode.h"

SListNode* BuySListNode(DataType x)  //�����½ڵ�
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

void SListPrint(SListNode* pHead)  //��ӡ����
{
    if (NULL==pHead)
    {
        printf("������\n");
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


void SListPushFront(SListNode** ppHead, DataType x)  //ͷ��
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

void SListPushBack(SListNode** ppHead, DataType x)  //β��
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

void SListPopBack(SListNode** ppHead)  //βɾ
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

void SListPopFront(SListNode** ppHead)  //ͷɾ
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

SListNode* SListFind(SListNode* pHead, DataType x)  //����
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

 void SListInsest(SListNode** ppHead, SListNode* pos, DataType x)  //������� 
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

 void SListErase(SListNode** ppHead, SListNode* pos) //���ɾ��
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

 void SListChange(SListNode**pphead,SListNode *pos,DataType x)  //������޸�
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

 void SListDestory(SListNode** ppHead)  //��������
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


void EndToFirstPrintNode(SListNode*ps) //������ͷ��β��ӡ
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

  typedef struct SeqList  //˳���
  {
      DataType *data;
      size_t size;
      size_t capicity;
  }SeqList;
  SeqList List;
 
  void CheckFullSeqlist(SeqList *Seq)  //˳�������ݺ�����
  {
      DataType *tmp;
      if (Seq->size==Seq->capicity)
      {
          tmp=(DataType*)realloc(Seq->data,2*Seq->capicity*sizeof(DataType)+3*sizeof(DataType));
          if (NULL==tmp)
          {
              printf("����ʧ�ܣ�");
          }
          else
          {
              Seq->capicity=Seq->capicity*2+3;
              Seq->data=tmp;
          }
      }
  }
 
  void PrintSList(SeqList *Seq)  //��ӡ˳���
  {
      DataType i=0;
      for (i=Seq->size-1;i>=0;i--)
      {
          printf("%d ",Seq->data[i]);
      }
  }
 
 void EndToFirstPrintSListNode(SListNode *ps)  //����Ĵ�β��ͷ��ӡ���ö�̬˳��������ݡ�
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

void EndToFirstPrintSListNodeR(SListNode *ps)//�ݹ��ӡ
{
    if (NULL != ps->_next) //�ݹ��������
        EndToFirstPrintSListNodeR(ps->_next);  //������
    printf("%d ",ps->_data);
}

void EndToFirstPrintSListNodeNon(SListNode *ps)  //��������
{
    SListNode *prev;
    SListNode *cur;
    SListNode *tmp;
    cur=ps;  //����ͷ���
    prev=cur->_next;  //������һ���ڵ�
    cur->_next=NULL;  //ͷ����Ϊβ�ڵ㣬next=NULL
    while (NULL != prev)  
    {
        tmp=prev->_next;
        prev->_next=cur;
        cur=prev;
        prev=tmp;
    }
    ps=cur;  //β�ڵ��Ϊͷ�ڵ�
    SListPrint(ps);  //��ӡ����
}

void NoHeadSeqListDelete(SListNode *pos) //ɾ��һ����ͷ����ķ�β�ڵ㣨���ܱ�������
{
    SListNode*tmp; 
    assert(pos);
    tmp=pos->_next;  //����pos->_next��ֵ������һ������
    pos->_data=pos->_next->_data;
    pos->_next=pos->_next->_next;
    free(tmp);  //����pos->_next
    tmp=NULL;
}

//����һ���½ڵ㣬�滻ԭ���Ĳ���ڵ��ֵ���ٰѲ���ֵ����ԭ�ڵ�
void NoHeadSeqListInsert(SListNode*pos,DataType x) //����ͷ�����һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
{
    SListNode *newNode;
    newNode=BuySListNode(x);  //�����½ڵ�
    newNode->_next=pos->_next;  
    pos->_next=newNode;
    newNode->_data=pos->_data;
    pos->_data=x;
}

SListNode *JosephCircle(SListNode*ps)  //Լɪ������
{
    int k = 0;
    SListNode *tmp=ps;
    SListNode*cur=NULL;
    while (tmp->_next)
    {
        tmp=tmp->_next;
    }
    tmp->_next=ps;   //����Ϊһ����
    while (ps!=ps->_next)
    {
        ps=ps->_next;
        k++;
        if (k==2)  //ÿ������ɱһ��
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


SListNode* ReverseSeqList(SListNode *Seq) //����/��ת������ 
{
    SListNode *prev=Seq; //����ͷ�ڵ�
    SListNode *cur=prev->_next;  //����ڶ����ڵ�
    SListNode *tmp;
    assert(Seq);
    prev->_next=NULL;  //�ÿ�ͷ�ڵ��next,���β�ڵ�
    while (cur!=NULL)  //ѭ������ 
    {
        tmp=cur->_next;  
        cur->_next=prev;
        prev=cur;
        cur=tmp;
    }
    Seq=prev;  //���ú��ͷ
    return Seq;
}


void SeqListSort(SListNode *Seq)//����������ð������
{
    SListNode *tail,*tmp=Seq;
    DataType flag=0;
    assert(Seq);
    if (Seq->_next==NULL||Seq==NULL)  //��ֹ�ǿ��������ֻ��һ���ڵ�
    {
        return;
    }
    while (tmp!=NULL)  //��β�ڵ�
    {
        tmp=tmp->_next;
    }
    tail=tmp;  
    while (tail!=Seq)
    {
        tmp=Seq;  //����ͷ�ڵ�
        while (tmp->_next!=tail)
        {
            if (tmp->_data>tmp->_next->_data)    //ѭ��ð��
            {
                flag=1;
                tmp->_data^=tmp->_next->_data;
                tmp->_next->_data^=tmp->_data;
                tmp->_data^=tmp->_next->_data;
            }
            tmp=tmp->_next;  //ѭ������
        }
        if (flag==0)  //�Ż�ð�ݴ���
        {
            break;
        }
        tail=tmp; //βǰ��
    }
}


SListNode* SListMerge(SListNode *list1,SListNode *list2)//�ϲ�������������,�ϲ�����Ȼ���� 
{
    SListNode *list,*tmp;
    assert(list1&&list2);
    if (list1->_data<list2->_data)  //�ҵ�����������С��һ��ͷ�ڵ�
    {
        list=tmp=list1;
        list1=list1->_next;
    }
    else
    {
        list=tmp=list2;
        list2=list2->_next;
    }
    while (NULL!=list1 && NULL!=list2)  //ѭ���Ƚϣ�ȡ��������С�Ľڵ�����list
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
    if (NULL==list1)  //ȡ��ʣ��һ����������������Ӹ�list
    {
        tmp->_next=list2;
    }
    else
    {
        tmp->_next=list1;
    }
    return list; //�����������ͷ�ڵ��ַ
}

 
SListNode* SListFindMidNode(SListNode* list) //���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
{
    SListNode *fast;
    SListNode *slow;
    assert(list);
    fast=slow=list; 
    //�������û�ڵ㣬һ�����������ڵ㣬ֱ�ӷ���ͷ�ڵ�
    if (NULL==list || NULL==list->_next || NULL==list->_next->_next)      
    {
        return list;
    }
    while (fast) //��ָ���ߵ�β����ָ���ߵ��м䡣
    {
        fast=fast->_next->_next;  //��ָ��һ�������� 
        slow=slow->_next;  //��ָ��һ����һ��
    }
    return slow; //�����м�ڵ�ĵ�ַ
}

//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
SListNode* SListFindTailKNode(SListNode *list, size_t k) 
{
    SListNode *fast;
    SListNode *slow;
    assert(list);
    fast=slow=list;
    while (--k)  //��ָ����k-1��
    {
        if (NULL==fast) //����k���ڵ㣬ֱ�ӷ����׵�ַ
        {
            return list;
        }
        fast=fast->_next;  
    }
    while (fast->_next)  //����ָ��ѭ������
    {
        slow=slow->_next;
        fast=fast->_next;
    }
    return slow;//���ص�����k���ڵ�ĵ�ַ
}

 
void DeleteKNode(SListNode *list,size_t k)//ɾ������ĵ�����K�����
{
    SListNode *fast,*slow,*tmp;
    assert(list);
    fast=slow=list;
    while (--k)  //��ָ����k-1��
    {
        if (NULL==fast) //����k���ڵ㣬ֱ�ӷ����׵�ַ
        {
            return;
        }
        fast=fast->_next;  
    }
    while (fast->_next)  //����ָ��ѭ�����ƣ��ҵ���k���ڵ�
    {
        tmp=slow;  //�����k���ڵ��ǰ��
        slow=slow->_next;
        fast=fast->_next;
    }
    tmp->_next=slow->_next;  //�����ϵ�k���ڵ����Ľڵ�
    free(slow);  //�ͷŵ���k���ڵ�
    slow=NULL;
}
//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ�
SListNode *CircleSListNode(SListNode *list) //ʱ�临�Ӷ�ΪO(n) 
{
    SListNode *slow,*fast;
    assert(list);
    slow=fast=list;
    while (fast && fast->_next)  //��ָ������������ָ����һ��������������һ���ڻ�������
    {
        slow=slow->_next;
        fast=fast->_next->_next;
        if (fast == slow)
        {
            return slow;  //�����������ַ
        }}
    return NULL;
}

size_t CircleLengthSListNode(SListNode *ps) //�󻷳���ʱ�临�Ӷ�ΪO(n) 
{
    SListNode *tmp;
    size_t i=0;
    assert(ps);
    tmp =ps;
    do  //�ӻ��������㿪ʼ�ߣ���һȦ���ǻ���
    {
        tmp=tmp->_next; 
        ++i;
    } while (tmp!=ps);
    return i;
}

SListNode *CircleEntrySListNode(SListNode *list,SListNode *meet) //ʱ�临�Ӷ�ΪO(1) 
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

//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 

int IsCross(SListNode* list1, SListNode* list2)  //�ж��Ƿ��ཻ����β�ڵ��ַ������ཻ
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

SListNode *SListCrossNode(SListNode *list1,SListNode *list2)  //�����ַ
{
    SListNode *tmp1,*tmp2;
    DataType k=0;
    assert(list1 && list2);
    tmp1=list1;
    tmp2=list2;
    if(1 != (IsCross(list1,list2)))
        return NULL;
    while (tmp1->_next)    //�������������������ĳ��� 
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
    if (k>0)   //�����������ߵ�������ȴ�
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
    while (tmp1!=tmp2) //��������ͬʱ����ȴ���ʼ�ߣ��ߵ��е�ַ����Ҳ����ڿ����ཻ
    {
        tmp1=tmp1->_next;
        tmp2=tmp2->_next;
    }
    return tmp1;
}

//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 
SListNode* SListIsCross(SListNode *list1,SListNode *list2) 
{
    SListNode *meet1,*meet2;;
    assert(list1&&list2);
    meet1=CircleSListNode(list1);  //�ж� ���������Ƿ����
    meet2=CircleSListNode(list2);
    if (meet1 && meet2 )  //�����������
    {
        SListNode *tmp=meet1->_next;
        while (tmp!=meet1)  //�ж��Ƿ��ͬһ����
        {
            if (tmp==meet2) //��ͬһ����
            {
                SListNode *cur1,*cur2;
                cur1=CircleEntrySListNode(list1,meet1);
                cur2=CircleEntrySListNode(list2,meet2);
                if (cur1==cur2)  //�����ཻ
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
                    return SListCrossNode(list1,list2);  //���ؽ����ַ
                }
                else  //�����ཻ
                {
                    return cur1; //���ؽ����ַ
                }
            }
            tmp=tmp->_next;
        }
        return NULL;   //��������ͬ�Ļ� 
    }
    else if (NULL==meet1 && NULL==meet2) //��������������
    {
        return SListCrossNode(list1,list2); 
    }
    else  //����һ������
    return NULL;
}

//��������ĸ��ơ�\
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬\����һ��randomָ��ָ����������е�һ������ڵ�\
//����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ��������


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
    while (tmp)   //copyԭ���������
    {
        ComplexNode *cur=tmp->next;
        ComplexNode *node=BuyComplexNode(tmp->data);
        tmp->next=node;
        node->next=cur;

        tmp=cur;
    }

    tmp=list;
    while (tmp)  //copyԭ�ϱ��random 
    {
        ComplexNode *cur=tmp->next;
        if (tmp->random)
        {
            cur->random=tmp->random->next;
        }

        tmp=tmp->next->next;
    }
    
    tmp=list; 
    while (tmp)  //����������� 
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

//��������������������ͬ������
void SListUnionData(SListNode *list1,SListNode *list2)
{
    SListNode *tmp1,*tmp2;
    assert(list1 && list2);
    tmp1=list1;
    tmp2=list2;
    while (tmp1 && tmp2)
    {
        if (tmp1->_data<tmp2->_data)  //С��ָ����ǰ��һ��
        {
            tmp1=tmp1->_next;
        }
        else if(tmp1->_data>tmp2->_data)
        {
            tmp2=tmp2->_next;
        }
        else  //�������ʱͬʱ��
        {
            printf("%d ",tmp2->_data);
            tmp1=tmp1->_next;
            tmp2=tmp2->_next;
        }
    }
    printf("\n");
}