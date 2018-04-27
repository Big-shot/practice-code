
#include "stack.h"

//  int maze[N][N] = 
//  { 
//      {0,0,0,0,0,0}, 
//      {0,0,1,1,1,1}, 
//      {0,0,1,0,0,0}, 
//      {0,0,1,0,0,0}, 
//      {0,0,1,1,1,1}, 
//      {0,0,1,0,0,0}, 
//  }; 
  
//ջ�Ļ�������
void StackInit(Stack *s)  //ջ�ĳ�ʼ��
{
    assert(s);
    s->data=NULL;
    s->end=0;
    s->top=0;
}

void ExpandStack(Stack *s)  //��ջ����
{ 
    DataType* tmp;
    assert(s);
    tmp = (DataType*)realloc(s->data,(s->end*2+3)*sizeof(DataType));
    if (NULL == tmp)
    {
        printf("����ʧ�ܣ�\n");
        return;
    }
    s->data= tmp;
    s->end=s->end*2+3;
}

void StackPush(Stack *s,DataType x)  //��ջ
{
    assert(s);
    if (s->top==s->end)
    {
        ExpandStack(s);
    }
    s->data[s->top++]=x;
}

void StackPop(Stack* s)  //��ջ
{
    assert(s);
    if (s->top>0)
        s->top--;
}

DataType StackTop(Stack* s)   //��ȡջ��Ԫ��
{
    assert(s);
    if (s->top>0)
       return s->data[s->top-1];
    else
        return NULL;
}

size_t StackSize(Stack* s)  //���ջ��С
{
    assert(s);
    return s->top;
}

int StackEmpty(Stack* s)  //�ж��Ƿ��ջ
{
    assert(s);
    if (s->top>0)
    {
        return 1;
    }
    return 0;
}
 
// ��ʽջ�Ļ�������
  void LinkStackInit(LinkStack *s)//ջ�ĳ�ʼ��
  {
      s = NULL;
  }
  
  void LinkStackPush(LinkStack** s, DataType x)   //��ջ
  {
      LinkStack *tmp = (LinkStack *)malloc(sizeof(LinkStack));
      assert(tmp);
      tmp->data = x;
      tmp->next = *s;
      *s = tmp;
  }
  
  void LinkStackPop(LinkStack** s)   //��ջ
  {
      LinkStack *tmp = *s;
      if (*s)
      {
          *s = (*s)->next;
          free(tmp);
          tmp = NULL;
      }
  }
  
  DataType LinkStackTop(LinkStack** s)   //��ȡջ��Ԫ��
  {
      if (*s)
      {
          return (*s)->data;
      }
  }
  
  size_t LinkStackSize(LinkStack** s)   //ջ��
  {
      size_t lenth = 0;
      if (*s)
      {
          LinkStack *tmp = *s;
          while (tmp)
          {
              tmp = tmp->next;
              lenth++;
          }
          return lenth;
      }
  }
  
  int LinkStackEmpty(LinkStack* s)   //�ж��Ƿ��ǿ�ջ
  {
      if (s)
      {
          return 1;
      }
      return 0;
  }
 
 //���л�������
QueueNode* BuyQueueNode(DataType x)  //�������нڵ�
{

    QueueNode *newNode;
    QueueNode *tmp = (QueueNode *)malloc(sizeof(QueueNode));
    if (NULL == tmp)
    {
        return NULL;
    }
    tmp->_data = x;
    tmp->_next = NULL;
    newNode = tmp;
    return newNode;
}

void QueueInit(Queue* q)  //���г�ʼ��
{
    assert(q);
    q->_head = NULL;
    q->_tail = NULL;  
}

void QueuePush(Queue* q, DataType x) //������
{
    QueueNode *tmp;
    assert(q);
    tmp = BuyQueueNode(x);
    if (NULL == q->_tail)
    {
        q->_head = tmp;
        q->_tail = tmp;
    }
    else
    {
        q->_tail->_next = tmp;
        q->_tail = tmp;
    }
}

void QueuePop(Queue* q) //����
{
    assert(q);
    if (q->_tail == q->_head && NULL != q->_head) //ֻ��һ���ڵ�
    {
        free(q->_head);
        q->_head = NULL;
        q->_tail = NULL;
    }
    else if(q->_head != q->_tail)  //����ڵ�
    {
        QueueNode *tmp = q->_head->_next;
        free(q->_head);

        q->_head = tmp;
    }
}

DataType QueueFront(Queue* q) //��ȡ��ͷ����
{
    assert(q);
    
    return q->_head->_data;
}

DataType QueueBack(Queue* q) //��ȡ��β����
{
    assert(q);
    
    return q->_tail->_data;
}

size_t QueueSize(Queue* q) //���еĳ���
{
    size_t size = 0;
    QueueNode *tmp;
    assert(q);
    tmp = q->_head;
    while(tmp)
    {
        size++;
        tmp = tmp->_next;
    }
    return size;
}

int QueueEmpty(Queue* q) //�ж��Ƿ��Ƿ��ǿն���
{
    assert(q);
    if (NULL == q->_head)
    {
        return 0;  //�ն�
    }
    return 1;
}

 ////���еļ�Ӧ��
 //void BinomialCoefficient(DataType n) //����ʽչ����ϵ��
 //{
 //    DataType i,j,sum=0;
 //    Queue q;
 //    QueueInit(&q);
 //    QueuePush(&q,1);  //һ����ʱϵ����Ϊ1�����������1
 //    QueuePush(&q,1);
 //    for (i = 1; i<= n; i++)
 //    {
 //        printf("(a+b)^%d: ",i);
 //        QueuePush(&q,0);  
 //        for (j = 1; j <= i+2; j++) //���д���
 //        {
 //            DataType front = QueueFront(&q);
 //            QueuePop(&q);
 //            QueuePush(&q,sum+front); //��ͷ���ݺ���һ�εĶ�ͷ��ӣ��������ӡ�
 //            sum = front;
 //            if(j != i+2)
 //              printf("%2d ",front);
 //        }
 //        printf("\n\n");
 //    }
 //    printf("\n");
 //}

 //void Hanoi(DataType n,char A,char B,char C)  //��ŵ������
 //{
 //    if (n==1)
 //    {
 //        printf("%c->%c ",A,C);
 //    }
 //    else
 //    {
 //        Hanoi(n-1,A,C,B);
 //        printf("%c->%c ",A,C);
 //        Hanoi(n-1,B,A,C);
 //    }
 //}


// // �Թ�����
//    void MazePrint()  //��ӡ�Թ�
//     {
//         size_t i =0,j=0;
//         for (i = 0; i<N; i++)
//         {
//             for (j=0; j<N; j++)
//             {
//                 printf("%d ",maze[i][j]);
//             }
//             printf("\n");
//         }
//         printf("\n");
//     }
//     
//     int CheckMazeAssess(Pos pos)  //���������Ƿ��ͨ
//     {
//         if (pos.row>=0 && pos.row<N 
//             && pos.col>=0 && pos.col<N
//             && maze[pos.row][pos.col]==1)
//         {
//             return 1;
//         }
//         return 0;
//     }
//     
//     void MazeGetPath(Pos entry) //���������Թ�ͨ·
//     {
//         Pos cur = entry;
//         Pos next = cur;
//         Stack s;
//         StackInit(&s);
//         StackPush(&s,cur);
//     
//         while (StackEmpty(&s))
//         {
//             cur = StackTop(&s); //ջ��Ϊ��ǰλ��
//             maze[cur.row][cur.col]=2; //ע�͵���ǰ����
//             if (cur.col==N-1)  //�Թ�����
//             {
//                 printf("��������:(%d,%d)\n",cur.row,cur.col);
//                 //return 1;
//             }
//     
//             next = cur; //next�õ���ǰλ��
//             next.row+=1;  //������̽
//             if(CheckMazeAssess(next))
//             {
//                 StackPush(&s,next);
//                 continue;
//             }
//     
//             next = cur;//next�õ���ǰλ��  
//             next.row-=1; //������̽
//             if(CheckMazeAssess(next))
//             {
//                 StackPush(&s,next);
//                 continue;
//             }
//     
//             next = cur;  //next�õ���ǰλ��
//             next.col+=1;  //������̽
//             if(CheckMazeAssess(next))
//             {
//                 StackPush(&s,next);
//                 continue;
//             }
//     
//             next = cur;   //next�õ���ǰλ��
//             next.col-=1;  //������̽
//             if(CheckMazeAssess(next))
//             {
//                 StackPush(&s,next);
//                 continue;
//     
//             }
//             StackPop(&s);  //��������ͬ������
//         }
//         return 0;  //���Թ�û�г���
//     }
//   
//    void MazeGetPathR(Pos entry)  //�ݹ鷨������Թ�����
//     {
//         Pos cur = entry;
//         Pos next = cur;
//         if (next.col>N-1)  //�ݹ��������
//         {
//             printf("�ҵ�����:%d,%d \n",next.row,next.col);
//             return;
//         }
//         maze[entry.row][entry.col] = 2;
//     
//         next = cur;
//         next.row-=1; //��
//         if (CheckMazeAssess(next))
//         {
//             MazeGetPathR(next); //������
//         }
//   
//         next = cur;
//         next.row+=1;  //��
//         if (CheckMazeAssess(next))  
//         {
//             MazeGetPathR(next);  //������
//         }
//     
//         next = cur;
//         next.col-=1;  //��
//         if (CheckMazeAssess(next))
//         {
//             MazeGetPathR(next);  //������
//         }
//     
//         next = cur;
//         next.col+=1; //��
//         if (CheckMazeAssess(next))
//         {
//             MazeGetPathR(next);  //������
//         }
//     }
//     
//     int CheckMazeShortAssess(Pos next,Pos cur)  //���������Ƿ��ͨ
//     {
//         if (next.row>=0 && next.row<N 
//             && next.col>=0 && next.col<N
//             && (maze[next.row][next.col]==1 || 
//             maze[next.row][next.col]>maze[cur.row][cur.col]))
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//   
//     void MazeGetShortPath(Pos entry,Stack* path)  //��ȡ���·��
//     {
//         Pos cur = entry;
//         Pos next = cur;
//         if (0==StackEmpty(path)) //��ڴ�
//         {
//             maze[next.row][next.col] = 2; 
//         }
//         else  //������Ժ�ÿ�α�ǵ�����һ��
//         {
//             Pos prev = StackTop(path);
//             maze[next.row][next.col]=maze[prev.row][prev.col]+1; 
//         }
//   
//         StackPush(path,next);  
//         if (next.col==N-1)
//         {
//             printf("�ҵ�����:%d,%d \n",next.row,next.col);  
//             if(!StackEmpty(&shortPath) || StackSize(path)<StackSize(&shortPath))  //ʼ�ձ������·����shortPathջ��
//             {
//                 if(shortPath.data)
//                    free(shortPath.data);
//   
//                 shortPath.data = (DataType *)malloc(sizeof(DataType)*path->top);
//                 memcpy(shortPath.data,path->data,sizeof(DataType)*path->top);
//                 shortPath.top = path->top;
//                 shortPath.end = path->top;
//             }
//         }
//         next = entry;
//         next.row-=1; //��
//         if (CheckMazeShortAssess(next,cur))
//         {
//             MazeGetShortPath(next,path);
//         }
//   
//         next = entry;
//         next.row+=1;  //��
//         if (CheckMazeShortAssess(next,cur))
//         {
//             MazeGetShortPath(next,path);
//         }
//   
//         next = entry;
//         next.col-=1;  //��
//         if (CheckMazeShortAssess(next,cur))
//         {
//             MazeGetShortPath(next,path);
//         }
//   
//         next = entry;
//         next.col+=1; //��
//         if (CheckMazeShortAssess(next,cur))
//         {
//             MazeGetShortPath(next,path);
//         }
//   
//         StackPop(path);
//     }

// //ջ�ļ�Ӧ�ã�����ת�������沨�����ʽ��
// void HexTran(DataType x,DataType k)  //�������ת��
// {
//     DataType result = 0;
//     Stack s;
//     DataType i;
//     StackInit(&s);
//     while (x) 
//     {
//         i = x%k; //ȡ��
//         x = x/k;
//         StackPush(&s,i); //��ת�������ջ
//     }
//     while (StackEmpty(&s))  
//     {
//         DataType top = StackTop(&s);
//         printf("%d ",top);
//         StackPop(&s);
//     }
// }
// 
// DataType BracketsMatch(char *p) //����ƥ��
// {
//     Stack s1,s2,s3;
//     StackInit(&s1);
//     StackInit(&s2);
//     StackInit(&s3);
//     assert(p);
//     while (*p)  //ѭ�����ÿһ������
//     {
//         if (*p == '(')
//         {
//             StackPush(&s1,'(');  //��������ջ
//         }
//         else if (*p == '{')
//         {
//             StackPush(&s2,'{');
//         }
//         else if (*p == '[')
//         {
//             StackPush(&s3,'[');
//         }
//         if (*p==')')
//         {
//             if (0 == StackEmpty(&s1)) //��������ջΪ����ƥ��
//             {
//                 return 0;
//             }
//             StackPop(&s1); //��������ջ��Ϊ����ƥ��
//         }
//         else if (*p == '}')
//         {
//             if (0 == StackEmpty(&s2))
//             {
//                 return 0;
//             }
//             StackPop(&s2);
//         }
//         else if (*p == ']')
//         {
//             if (0 == StackEmpty(&s3))
//             {
//                 return 0;
//             }
//             StackPop(&s3);
//         }
//         p++;
//     }
//     if (0 == StackEmpty(&s1) && 0 == StackEmpty(&s2) && 0 == StackEmpty(&s3))  //ջΪ����ƥ��
//     {
//         return 1; //ƥ��
//     }
//     return 0;  //��ƥ��
// }

// int RPNExpression(Cell *rpn,size_t n)  //�沨�����ʽ
// {
//     Stack s;
//     size_t i = 0;
//     assert(rpn);
//     StackInit(&s);
//     while (i<n)
//     {
//         if (rpn[i].type == NUM)  //��ֵ��ջ
//         {
//             StackPush(&s,rpn[i].num);
//             i++;
//         }
//         else  //����������ž�ȡ��ջ��ֵ����
//         {
//             DataType right = StackTop(&s);
//             DataType left;
//             StackPop(&s);
//             left = StackTop(&s);
//             StackPop(&s);
// 
//             switch (rpn[i].num)
//             {
//             case ADD: StackPush(&s,left + right);
//             	break;
//             case SUB: StackPush(&s,left - right);
//                 break;
//             case MUL: StackPush(&s,left * right);
//                 break;
//             case DIV: StackPush(&s,left / right);
//                 break;
//             default:
//                 break;
//             }
//             i++;
//         }
//     }
//     return StackTop(&s);
// }

