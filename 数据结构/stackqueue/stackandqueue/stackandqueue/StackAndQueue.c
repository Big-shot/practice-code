
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4715)

#include "StackAndQueue.h"

int Maze[ROW][COL] =
{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,1,1},
    {0,0,1,0,1,1,1,1,1,0},
    {0,0,1,0,0,1,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,1},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
};

 //˳��ջ��������
 void InitSequenceStack(SequenceStack *s) //��ʼ��
 {
     assert(s);
     s->_size = 0;
     s->_data = NULL;
     s->_top = 0;
 }
 void CheckSequenceStackCapacity(SequenceStack *s) //���ջ�Ƿ����ˣ������ݡ�
 {
     assert(s);
     if (s->_size == s->_top)
     {
         Datatype *tmp = NULL;
         tmp = (Datatype*)realloc(s->_data,sizeof(Datatype) * (s->_size * 2 + 3));
         assert(tmp);
         s->_data = tmp;
         s->_top += s->_top * 2+3;
     }
 }
 
 void PushSequenceStack(SequenceStack *s,Datatype x) //��ջ
 {
     assert(s);
     CheckSequenceStackCapacity(s);
     s->_data[s->_size++] = x;
 }
 
 void PopSequenceStack(SequenceStack*s) //��ջ
 {
     assert(s);
     if (EmptySequenceStack(s))
         s->_size-=1;
 }
 
 int SizeSequenceStack(SequenceStack*s)//��ջ�Ĵ�С
 {
     assert(s);
     return s->_size;
 }
 
 Datatype TopSequenceStack(SequenceStack*s) //ȡջ��Ԫ��
 {
     assert(s);
     if (EmptySequenceStack(s))
         return s->_data[s->_size-1];
 }
 int EmptySequenceStack(SequenceStack*s) //�ж�ջ�Ƿ��ǿ�ջ
 {
     assert(s);
     if (s->_size>0)
         return 1;
     else
         return 0;
 }

//////////////////////////////////////////////////////////////////////////
////��ʽջ��������
//Stack *BuyNode(Datatype x) //�����½ڵ�
//{
//    Stack *tmp = (Stack *)malloc(sizeof(Stack));
//    assert(tmp);
//    tmp->_next = NULL;
//    tmp->_data = x;
//    return tmp;
//}
//void PushStack(Stack **s,Datatype x)//��ջ
//{
//    Stack *newNode = BuyNode(x);
//    if (EmptyStack(*s))
//    {
//        newNode->_next = *s;
//        (*s) = newNode;
//    }
//    else
//        *s = newNode;
//}
//void PopStack(Stack **s)//��ջ
//{
//    if (*s)
//    {
//        Stack *tmp = (*s)->_next;
//        free(*s);
//        *s = NULL;
//        *s = tmp;
//    }
//}
//size_t SizeStack(Stack *s) //��ջ�Ĵ�С
//{
//    int size = 0;
//    while(s)
//    {
//        s = s->_next;
//        size+=1;
//    }
//    return size;
//}
//int EmptyStack(Stack *s)//�ж��Ƿ��ջ
//{
//    if (s)
//        return 1;
//    return 0;
//}
//Datatype TopStack(Stack *s)//ȡ��ջ��Ԫ��
//{
//    if (EmptyStack(s))
//        return s->_data;
//}

//////////////////////////////////////////////////////////////////////////
//�Թ�����
//void PrintMaze() //��ӡ�Թ�
//{
//    int i,j;
//    for (i=0; i<ROW; i++)
//    {
//        for (j=0; j<COL; j++)
//        {
//            printf("%2d ",Maze[i][j] );
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
//int CheckCoord(Pos pos)
//{
//    if (pos._x >= 0 && pos._x<ROW 
//        && pos._y >=0 && pos._y<COL  
//        && Maze[pos._x][pos._y] == 1)
//    {
//        return 1;
//    }
//    else
//        return 0;
//}
//
//void SearchMazePath(Pos entry) //��ȡͨ· ���ݷ���������
//{
//    Stack *s;
//    Pos next = entry;
//    PushStack(&s,next);
//    do
//    {
//        Maze[next._x][next._y] = 2;
//        next = TopStack(s);
//        next._x += 1;
//        if (CheckCoord(next))
//        {
//            PushStack(&s,next);
//            continue;
//        }
//
//        next = TopStack(s);
//        next._x -= 1;
//        if (CheckCoord(next))
//        {
//            PushStack(&s,next);
//            continue;
//        }
//
//        next = TopStack(s);
//        next._y += 1;
//        if (CheckCoord(next))
//        {
//            PushStack(&s,next);
//            continue;
//        }
//
//        next = TopStack(s);
//        next._y -= 1;
//        if (CheckCoord(next))
//        {
//            PushStack(&s,next);
//            continue;
//        }
//        
//        PopStack(&s);
//        next = TopStack(s);
//    }while (EmptyStack(s) && next._x != entry._x);
//}
//
//void SearchMazePathR(Pos entry) //��ȡͨ·���ݹ飩
//{
//    Pos next = entry;
//    Maze[next._x][next._y] = 2;
//    if (next._y == COL-1)  //���Բ�Ҫ����������õݹ�������е�ͨ·�ڽ���
//        return;
//
//    next = entry;
//    next._x -=1;
//    if (CheckCoord(next))
//        SearchMazePathR(next);
//
//    next = entry;
//    next._x +=1;
//    if (CheckCoord(next))
//        SearchMazePathR(next);
//
//    next = entry;
//    next._y -=1;
//    if (CheckCoord(next))
//        SearchMazePathR(next);
//
//    next = entry;
//    next._y +=1;
//    if (CheckCoord(next))
//        SearchMazePathR(next);
//}
//
//
//int CheckCoordS(Pos pos,Pos prev)
//{
//    if (pos._x >= 0 && pos._x<ROW 
//        && pos._y >=0 && pos._y<COL 
//        && (Maze[pos._x][pos._y] == 1 
//        || Maze[pos._x][pos._y] > Maze[prev._x][prev._y]))
//    {
//        return 1;
//    }
//    else
//        return 0;
//}
//
//void SearchShortPathR(Pos entry,Pos cur) //Ѱ�����·��
//{
//    Pos next = entry;
//    Pos prev = cur;
//    Maze[next._x][next._y] = Maze[prev._x][prev._y] + 1;
//    if (next._y == COL-1)
//        printf("Exit:(%d ,%d)\n",next._x,next._y);  //��ӡ����
//       
//    next = entry;
//    next._x += 1;
//    if (CheckCoordS(next,entry))
//        SearchShortPathR(next,entry);
//
//    next = entry;
//    next._x -= 1;
//    if (CheckCoordS(next,entry))
//        SearchShortPathR(next,entry);
//
//    next = entry;
//    next._y += 1;
//    if (CheckCoordS(next,entry))
//        SearchShortPathR(next,entry);
//
//    next = entry;
//    next._y -= 1;
//    if (CheckCoordS(next,entry))
//        SearchShortPathR(next,entry);
//}


//////////////////////////////////////////////////////////////////////////
//QueueNode *BuyQueueNode(Datatype x)//�������нڵ�
//{
//    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
//    assert(newNode);
//    newNode->_data = x;
//    newNode->_next = NULL;
//    return newNode;
//}
//
//void InitQueue(Queue *q) //��ʼ������
//{
//    q->_front = NULL;
//    q->_tail = NULL;
//}
//
//void PushQueue(Queue *q,Datatype x) //���
//{
//    QueueNode *newNode = BuyQueueNode(x);
//    if(EmptyQueue(q))
//    {
//        q->_tail->_next = newNode;
//        q->_tail = newNode;
//    }
//    else
//    {
//        q->_front = newNode;
//        q->_tail = newNode;
//    }
//}
//
//void PopQueue(Queue *q)//����
//{
//    if (q->_front && q->_front != q->_tail)
//    {
//        QueueNode * tmp = q->_front->_next;
//        free(q->_front);
//        q->_front = NULL;
//        q->_front = tmp;
//    }
//    else
//    {
//        free(q->_front);
//        q->_front = q->_tail = NULL;
//    }
//}
//
//Datatype FrontQueue(Queue *q)//ȡ��ͷ����
//{
//    assert(q);
//    if (EmptyQueue(q))
//        return q->_front->_data;
//}
//
//Datatype TailQueue(Queue *q)//ȡ�ö�β����
//{
//    assert(q);
//    if (EmptyQueue(q))
//        return q->_tail->_data;
//}
//
//int EmptyQueue(Queue *q)//�ж϶����Ƿ�Ϊ��
//{
//    if (q->_front == NULL)
//        return 0;
//    else
//        return 1;
//}
//
//int SizeQueue(Queue *q)//��ȡ���г���
//{
//    int  size = 0;
//    QueueNode * tmp = q->_front;
//    while (tmp)
//    {
//        size+=1;
//        tmp = tmp->_next;
//    }
//    return size;
//}
//
//void DestoryQueue(Queue *q)//���ٶ���
//{
//    while (q->_front != q->_tail)
//    {
//        QueueNode *tmp = q->_front;
//        q->_front = q->_front->_next;
//        free(tmp);
//        tmp = NULL;
//    }
//}



