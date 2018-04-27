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

typedef struct Stack   //栈结构
{
    DataType* data;
    size_t top;
    size_t end;
}Stack;

typedef struct  LinkStack  //链式栈
{
    DataType data;
    struct LinkStack *next;
}LinkStack;

typedef struct QueueNode   //队列结构
{ 
    DataType _data; 
    struct QueueNode* _next; 
}QueueNode; 

typedef struct Queue   
{ 
    QueueNode* _head; //队头节点
    QueueNode* _tail; //队尾节点
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
 //栈的基本操作（动态顺序栈）
 void StackInit(Stack *s);//栈的初始化
 void StackPush(Stack* s, DataType x);   //入栈
 void StackPop(Stack* s);   //出栈
 DataType StackTop(Stack* s);   //获取栈顶元素
 size_t StackSize(Stack* s);   //栈长
 int StackEmpty(Stack* s);   //判断是否是空栈

//栈的基本操作（链式栈）
//void LinkStackInit(LinkStack *s);//栈的初始化
//void LinkStackPush(LinkStack **s, DataType x);   //入栈
//void LinkStackPop(LinkStack** s);   //出栈
//DataType LinkStackTop(LinkStack** s);   //获取栈顶元素
//size_t LinkStackSize(LinkStack** s);   //栈长
//int LinkStackEmpty(LinkStack* s);   //判断是否是空栈

////栈的简单应用（数制转换，括号匹配和表达式的计算与优先级处理）
//void HexTran(DataType x,DataType k);  //任意进制转换
//DataType BracketsMatch(char *p); //括号匹配
//int RPNExpression(Cell *rpn,size_t n);  //逆波兰表达式

//队列的基本操作
void QueueInit(Queue* q);  //队列初始化
void QueuePush(Queue* q, DataType x);   //入队
void QueuePop(Queue* q);   //出队
DataType QueueFront(Queue* q); //取队头
DataType QueueBack(Queue* q);   //取队尾
size_t QueueSize(Queue* q); //求队长
int QueueEmpty(Queue* q);  //判断队列是否空了

////队列的简单应用
//void BinomialCoefficient(DataType n); //二项式系数
//void Hanoi(DataType n,char A,char B,char C);  //汉诺塔问题
//
////迷宫问题
//
//void MazePrint();   //打印迷宫
//void MazeGetPath(Pos entry);  //迭代寻找迷宫通路
//void MazeGetPathR(Pos entry);  //递归寻找迷宫通路
//Stack shortPath; 
//void MazeGetShortPath(Pos entry,Stack* path);  //求取最短路径

#endif
