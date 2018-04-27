#ifndef __STACK_H__
#define __STACK_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

// #define N 6 
// 
// typedef struct Pos
// {
//     size_t row;
//     size_t col;
// }Pos;

typedef struct BTNode 
{
    int data;
    struct BTNode *left;
    struct BTNode *right;
}BTNode;

typedef int DataType;

typedef struct Stack   //ջ�ṹ
{
    DataType* data;
    size_t top;
    size_t end;
}Stack;

typedef struct  LinkStack  //��ʽջ
{
    DataType data;
    struct LinkStack *next;
}LinkStack;

typedef struct QueueNode   //���нṹ
{ 
    DataType _data; 
    struct QueueNode* _next; 
}QueueNode; 

typedef struct Queue   
{ 
    QueueNode* _head; //��ͷ�ڵ�
    QueueNode* _tail; //��β�ڵ�
}Queue; 

// typedef enum RPN_TYPE
// {
//     NUM,
//     SYMBOL,
//     ADD,
//     SUB,
//     MUL,
//     DIV
// }RPN_TYPE;
// 
// typedef struct Cell
// {
//     RPN_TYPE type;
//     int num;
// }Cell;

// 
 //ջ�Ļ�����������̬˳��ջ��
 void StackInit(Stack *s);//ջ�ĳ�ʼ��
 void StackPush(Stack* s, DataType x);   //��ջ
 void StackPop(Stack* s);   //��ջ
 DataType StackTop(Stack* s);   //��ȡջ��Ԫ��
 size_t StackSize(Stack* s);   //ջ��
 int StackEmpty(Stack* s);   //�ж��Ƿ��ǿ�ջ

//ջ�Ļ�����������ʽջ��
//void LinkStackInit(LinkStack *s);//ջ�ĳ�ʼ��
//void LinkStackPush(LinkStack **s, DataType x);   //��ջ
//void LinkStackPop(LinkStack** s);   //��ջ
//DataType LinkStackTop(LinkStack** s);   //��ȡջ��Ԫ��
//size_t LinkStackSize(LinkStack** s);   //ջ��
//int LinkStackEmpty(LinkStack* s);   //�ж��Ƿ��ǿ�ջ

////ջ�ļ�Ӧ�ã�����ת��������ƥ��ͱ��ʽ�ļ��������ȼ�����
//void HexTran(DataType x,DataType k);  //�������ת��
//DataType BracketsMatch(char *p); //����ƥ��
//int RPNExpression(Cell *rpn,size_t n);  //�沨�����ʽ

//���еĻ�������
void QueueInit(Queue* q);  //���г�ʼ��
void QueuePush(Queue* q, DataType x);   //���
void QueuePop(Queue* q);   //����
DataType QueueFront(Queue* q); //ȡ��ͷ
DataType QueueBack(Queue* q);   //ȡ��β
size_t QueueSize(Queue* q); //��ӳ�
int QueueEmpty(Queue* q);  //�ж϶����Ƿ����

////���еļ�Ӧ��
//void BinomialCoefficient(DataType n); //����ʽϵ��
//void Hanoi(DataType n,char A,char B,char C);  //��ŵ������
//
////�Թ�����
//
//void MazePrint();   //��ӡ�Թ�
//void MazeGetPath(Pos entry);  //����Ѱ���Թ�ͨ·
//void MazeGetPathR(Pos entry);  //�ݹ�Ѱ���Թ�ͨ·
//Stack shortPath; 
//void MazeGetShortPath(Pos entry,Stack* path);  //��ȡ���·��

#endif
