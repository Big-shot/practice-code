
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
  
//栈的基本操作
void StackInit(Stack *s)  //栈的初始化
{
    assert(s);
    s->data=NULL;
    s->end=0;
    s->top=0;
}

void ExpandStack(Stack *s)  //给栈增容
{ 
    DataType* tmp;
    assert(s);
    tmp = (DataType*)realloc(s->data,(s->end*2+3)*sizeof(DataType));
    if (NULL == tmp)
    {
        printf("扩容失败！\n");
        return;
    }
    s->data= tmp;
    s->end=s->end*2+3;
}

void StackPush(Stack *s,DataType x)  //入栈
{
    assert(s);
    if (s->top==s->end)
    {
        ExpandStack(s);
    }
    s->data[s->top++]=x;
}

void StackPop(Stack* s)  //出栈
{
    assert(s);
    if (s->top>0)
        s->top--;
}

DataType StackTop(Stack* s)   //获取栈顶元素
{
    assert(s);
    if (s->top>0)
       return s->data[s->top-1];
    else
        return NULL;
}

size_t StackSize(Stack* s)  //求得栈大小
{
    assert(s);
    return s->top;
}

int StackEmpty(Stack* s)  //判断是否空栈
{
    assert(s);
    if (s->top>0)
    {
        return 1;
    }
    return 0;
}
 
// 链式栈的基本操作
  void LinkStackInit(LinkStack *s)//栈的初始化
  {
      s = NULL;
  }
  
  void LinkStackPush(LinkStack** s, DataType x)   //入栈
  {
      LinkStack *tmp = (LinkStack *)malloc(sizeof(LinkStack));
      assert(tmp);
      tmp->data = x;
      tmp->next = *s;
      *s = tmp;
  }
  
  void LinkStackPop(LinkStack** s)   //出栈
  {
      LinkStack *tmp = *s;
      if (*s)
      {
          *s = (*s)->next;
          free(tmp);
          tmp = NULL;
      }
  }
  
  DataType LinkStackTop(LinkStack** s)   //获取栈顶元素
  {
      if (*s)
      {
          return (*s)->data;
      }
  }
  
  size_t LinkStackSize(LinkStack** s)   //栈长
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
  
  int LinkStackEmpty(LinkStack* s)   //判断是否是空栈
  {
      if (s)
      {
          return 1;
      }
      return 0;
  }
 
 //队列基本操作
QueueNode* BuyQueueNode(DataType x)  //创建队列节点
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

void QueueInit(Queue* q)  //队列初始化
{
    assert(q);
    q->_head = NULL;
    q->_tail = NULL;  
}

void QueuePush(Queue* q, DataType x) //入数据
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

void QueuePop(Queue* q) //出队
{
    assert(q);
    if (q->_tail == q->_head && NULL != q->_head) //只有一个节点
    {
        free(q->_head);
        q->_head = NULL;
        q->_tail = NULL;
    }
    else if(q->_head != q->_tail)  //多个节点
    {
        QueueNode *tmp = q->_head->_next;
        free(q->_head);

        q->_head = tmp;
    }
}

DataType QueueFront(Queue* q) //获取队头数据
{
    assert(q);
    
    return q->_head->_data;
}

DataType QueueBack(Queue* q) //获取队尾数据
{
    assert(q);
    
    return q->_tail->_data;
}

size_t QueueSize(Queue* q) //对列的长度
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

int QueueEmpty(Queue* q) //判断是否是否是空对列
{
    assert(q);
    if (NULL == q->_head)
    {
        return 0;  //空队
    }
    return 1;
}

 ////队列的简单应用
 //void BinomialCoefficient(DataType n) //二项式展开项系数
 //{
 //    DataType i,j,sum=0;
 //    Queue q;
 //    QueueInit(&q);
 //    QueuePush(&q,1);  //一次项时系数都为1，先入队两个1
 //    QueuePush(&q,1);
 //    for (i = 1; i<= n; i++)
 //    {
 //        printf("(a+b)^%d: ",i);
 //        QueuePush(&q,0);  
 //        for (j = 1; j <= i+2; j++) //逐行处理
 //        {
 //            DataType front = QueueFront(&q);
 //            QueuePop(&q);
 //            QueuePush(&q,sum+front); //队头数据和上一次的队头相加，结果在入队。
 //            sum = front;
 //            if(j != i+2)
 //              printf("%2d ",front);
 //        }
 //        printf("\n\n");
 //    }
 //    printf("\n");
 //}

 //void Hanoi(DataType n,char A,char B,char C)  //汉诺塔问题
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


// // 迷宫问题
//    void MazePrint()  //打印迷宫
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
//     int CheckMazeAssess(Pos pos)  //检测该坐标是否可通
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
//     void MazeGetPath(Pos entry) //迭代法找迷宫通路
//     {
//         Pos cur = entry;
//         Pos next = cur;
//         Stack s;
//         StackInit(&s);
//         StackPush(&s,cur);
//     
//         while (StackEmpty(&s))
//         {
//             cur = StackTop(&s); //栈顶为当前位置
//             maze[cur.row][cur.col]=2; //注释掉当前坐标
//             if (cur.col==N-1)  //迷宫出口
//             {
//                 printf("出口坐标:(%d,%d)\n",cur.row,cur.col);
//                 //return 1;
//             }
//     
//             next = cur; //next置到当前位置
//             next.row+=1;  //向下试探
//             if(CheckMazeAssess(next))
//             {
//                 StackPush(&s,next);
//                 continue;
//             }
//     
//             next = cur;//next置到当前位置  
//             next.row-=1; //向上试探
//             if(CheckMazeAssess(next))
//             {
//                 StackPush(&s,next);
//                 continue;
//             }
//     
//             next = cur;  //next置到当前位置
//             next.col+=1;  //向右试探
//             if(CheckMazeAssess(next))
//             {
//                 StackPush(&s,next);
//                 continue;
//             }
//     
//             next = cur;   //next置到当前位置
//             next.col-=1;  //向左试探
//             if(CheckMazeAssess(next))
//             {
//                 StackPush(&s,next);
//                 continue;
//     
//             }
//             StackPop(&s);  //遇到死胡同，回溯
//         }
//         return 0;  //此迷宫没有出口
//     }
//   
//    void MazeGetPathR(Pos entry)  //递归法解决简单迷宫问题
//     {
//         Pos cur = entry;
//         Pos next = cur;
//         if (next.col>N-1)  //递归结束条件
//         {
//             printf("找到出口:%d,%d \n",next.row,next.col);
//             return;
//         }
//         maze[entry.row][entry.col] = 2;
//     
//         next = cur;
//         next.row-=1; //上
//         if (CheckMazeAssess(next))
//         {
//             MazeGetPathR(next); //子问题
//         }
//   
//         next = cur;
//         next.row+=1;  //下
//         if (CheckMazeAssess(next))  
//         {
//             MazeGetPathR(next);  //子问题
//         }
//     
//         next = cur;
//         next.col-=1;  //左
//         if (CheckMazeAssess(next))
//         {
//             MazeGetPathR(next);  //子问题
//         }
//     
//         next = cur;
//         next.col+=1; //右
//         if (CheckMazeAssess(next))
//         {
//             MazeGetPathR(next);  //子问题
//         }
//     }
//     
//     int CheckMazeShortAssess(Pos next,Pos cur)  //检测该坐标是否可通
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
//     void MazeGetShortPath(Pos entry,Stack* path)  //求取最短路径
//     {
//         Pos cur = entry;
//         Pos next = cur;
//         if (0==StackEmpty(path)) //入口处
//         {
//             maze[next.row][next.col] = 2; 
//         }
//         else  //从入口以后，每次标记的数加一。
//         {
//             Pos prev = StackTop(path);
//             maze[next.row][next.col]=maze[prev.row][prev.col]+1; 
//         }
//   
//         StackPush(path,next);  
//         if (next.col==N-1)
//         {
//             printf("找到出口:%d,%d \n",next.row,next.col);  
//             if(!StackEmpty(&shortPath) || StackSize(path)<StackSize(&shortPath))  //始终保持最短路径在shortPath栈中
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
//         next.row-=1; //上
//         if (CheckMazeShortAssess(next,cur))
//         {
//             MazeGetShortPath(next,path);
//         }
//   
//         next = entry;
//         next.row+=1;  //下
//         if (CheckMazeShortAssess(next,cur))
//         {
//             MazeGetShortPath(next,path);
//         }
//   
//         next = entry;
//         next.col-=1;  //左
//         if (CheckMazeShortAssess(next,cur))
//         {
//             MazeGetShortPath(next,path);
//         }
//   
//         next = entry;
//         next.col+=1; //右
//         if (CheckMazeShortAssess(next,cur))
//         {
//             MazeGetShortPath(next,path);
//         }
//   
//         StackPop(path);
//     }

// //栈的简单应用（数制转换，和逆波兰表达式）
// void HexTran(DataType x,DataType k)  //任意进制转换
// {
//     DataType result = 0;
//     Stack s;
//     DataType i;
//     StackInit(&s);
//     while (x) 
//     {
//         i = x%k; //取余
//         x = x/k;
//         StackPush(&s,i); //把转换结果入栈
//     }
//     while (StackEmpty(&s))  
//     {
//         DataType top = StackTop(&s);
//         printf("%d ",top);
//         StackPop(&s);
//     }
// }
// 
// DataType BracketsMatch(char *p) //括号匹配
// {
//     Stack s1,s2,s3;
//     StackInit(&s1);
//     StackInit(&s2);
//     StackInit(&s3);
//     assert(p);
//     while (*p)  //循环检测每一个符号
//     {
//         if (*p == '(')
//         {
//             StackPush(&s1,'(');  //正括号入栈
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
//             if (0 == StackEmpty(&s1)) //反括号且栈为空则不匹配
//             {
//                 return 0;
//             }
//             StackPop(&s1); //反括号且栈不为空则匹配
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
//     if (0 == StackEmpty(&s1) && 0 == StackEmpty(&s2) && 0 == StackEmpty(&s3))  //栈为空则匹配
//     {
//         return 1; //匹配
//     }
//     return 0;  //不匹配
// }

// int RPNExpression(Cell *rpn,size_t n)  //逆波兰表达式
// {
//     Stack s;
//     size_t i = 0;
//     assert(rpn);
//     StackInit(&s);
//     while (i<n)
//     {
//         if (rpn[i].type == NUM)  //数值入栈
//         {
//             StackPush(&s,rpn[i].num);
//             i++;
//         }
//         else  //遇到计算符号就取出栈顶值计算
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

