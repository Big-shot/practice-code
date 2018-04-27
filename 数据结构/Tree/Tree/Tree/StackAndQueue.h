
#ifndef __STACKANDQUEUE_H__
#define __STACKANDQUEUE_H__

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include <string.h>

#define ROW 10
#define COL 10

typedef struct Pos 
{
    int _x;
    int _y;
}Pos;
typedef char Datatype;

typedef struct SequenceStack  //˳��ջ
{
    int _size;
    int _top;
    Datatype *_data;
}SequenceStack;





 typedef struct Stack //��ʽջ
 {
     Datatype _data;
     struct Stack *_next;
 }Stack;

typedef struct QueueNode
{
    Datatype _data;
    struct QueueNode *_next;
}QueueNode;

typedef struct  Queue
{ 
    QueueNode *_front;
    QueueNode *_tail;
    
}Queue;




////˳��ջ�Ļ�������(��̬˳��ջ)
void InitSequenceStack(SequenceStack *s); //��ʼ��
void CheckSequenceStackCapacity(SequenceStack *s); //���ջ�Ƿ����ˣ������ݡ�
void PushSequenceStack(SequenceStack *s,Datatype x); //��ջ
void PopSequenceStack(SequenceStack*s); //��ջ
int SizeSequenceStack(SequenceStack*s);//��ջ�Ĵ�С
Datatype TopSequenceStack(SequenceStack*s); //ȡջ��Ԫ��
int EmptySequenceStack(SequenceStack*s); //�ж�ջ�Ƿ��ǿ�ջ

//��ʽջ��������
 Stack *BuyNode(Datatype x); //�����½ڵ�
 void PushStack(Stack **s,Datatype x);//��ջ
 void PopStack(Stack **s);//��ջ
 size_t SizeStack(Stack *s); //��ջ�Ĵ�С
 int EmptyStack(Stack *s);//�ж��Ƿ��ջ
 Datatype TopStack(Stack *s);//ȡ��ջ��Ԫ��

//�Թ�����
SequenceStack shortpath;
void PrintMaze(); //��ӡ�Թ�
void SearchMazePath(Pos entry); //��ȡͨ·��������
void SearchMazePathR(Pos entry); //��ȡͨ·���ݹ飩
void SearchShortPathR(Pos entry,Pos prev); //Ѱ�����·��


//���л�������

//void InitQueue(Queue *q); //��ʼ������
//void PushQueue(Queue *q,Datatype x); //���
//void PopQueue(Queue *q);//����
//Datatype FrontQueue(Queue *q);//ȡ��ͷ����
//Datatype TailQueue(Queue *q);//ȡ�ö�β����
//int SizeQueue(Queue *q);//��ȡ���г���
//void DestoryQueue(Queue *q);//���ٶ���
//int EmptyQueue(Queue *q);//�ж϶����Ƿ�Ϊ��





#endif //__STACKANDQUEUE_H__