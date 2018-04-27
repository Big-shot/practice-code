#include "stack.h"

LinkStack *s;

// void test1()
// {
//     Stack s;
// 
//     StackInit(&s);
// 
// //     printf("%d\n",StackTop(&s));
//     StackPush(&s,1);
//     printf("%d\n",StackTop(&s));
// 
//     StackPop(&s);
//     printf("%d\n",StackTop(&s));
//     StackPush(&s,2);
//     printf("%d\n",StackTop(&s));
//     StackPush(&s,3);
//     printf("%d\n",StackTop(&s));
//     StackPush(&s,4);
//     printf("%d\n",StackTop(&s));
//     StackPush(&s,6);
//     printf("%d\n",StackTop(&s));
// 
//     StackPop(&s);
//     StackPop(&s);
//     StackPop(&s);
//     StackPop(&s);
//     printf("%d\n",StackSize(&s));
// 
//     printf("%d\n",StackEmpty(&s));
//}

// void test2()
// {
//     LinkStackInit(s);
//     LinkStackPush(&s,5);
//     LinkStackPush(&s,6);
//     LinkStackPush(&s,7);
//     LinkStackPop(&s);
//     printf("%d\n",LinkStackTop(&s));
//     printf("%d\n",LinkStackSize(&s));
//     printf("%d\n",LinkStackEmpty(s));
// 
// }

// void test3()
// {
//     Queue q;
//     QueueInit(&q);
//     QueuePush(&q,1);
//     printf("%d ",QueueFront(&q));
//     QueuePush(&q,2);
//     printf("%d ",QueueFront(&q));
//     QueuePush(&q,3);
//     printf("%d ",QueueFront(&q));
//     QueuePush(&q,4);
//     printf("%d ",QueueFront(&q));
//     QueuePush(&q,5);
//     printf("%d ",QueueFront(&q));
//     QueuePush(&q,6);
//     printf("%d ",QueueFront(&q));
//     QueuePush(&q,7);
//     //QueuePop(&q);
//     printf("\n%d ",QueueSize(&q));
//     printf("\n%d\n",QueueBack(&q));
// 
//     printf("\n");
//     printf("%d ",QueueFront(&q));
//     QueuePop(&q);
//     printf("%d ",QueueFront(&q));
//     QueuePop(&q);
//     printf("%d ",QueueFront(&q));
//     QueuePop(&q);
//     printf("%d ",QueueFront(&q));
//     QueuePop(&q);
//     printf("%d ",QueueFront(&q));
//     QueuePop(&q);
//     printf("%d ",QueueFront(&q));
//     QueuePop(&q);
//     printf("%d ",QueueFront(&q));
//     QueuePop(&q);
//     printf("%d\n",QueueEmpty(&q));
//     printf("\n%d ",QueueSize(&q));
// 
// }

//  void test4()
//  {
//     Pos entry = {5,2};
//     Stack path;
//     StackInit(&path);
//     StackInit(&shortPath);
//     MazePrint();
//     MazeGetPath(entry);  //迭代法
//     MazeGetPathR(entry);   //递归法
//     MazeGetShortPath(entry,&path);
//     MazePrint();
//     while (StackEmpty(&shortPath))
//     {
//         printf("%d,%d<-", StackTop(&shortPath).row,StackTop(&shortPath).col);
//         
//         StackPop(&shortPath);
//     }
//     printf("entry\n");
//  }

//void Test5()
//{
//    Cell rpn[] =
//    {
//      {NUM, 12},
//      {NUM, 3},
//      {NUM, 4},
//      {SYMBOL, ADD},
//      {SYMBOL, MUL},
//      {NUM, 6},
//      {SYMBOL, SUB},
//      {NUM, 8},
//      {NUM, 2},
//      {SYMBOL, DIV},
//      {SYMBOL, ADD},
//
//    };
//    printf("转换结果:");
//    HexTran(1347,8);  //数制转换
//    printf("\n匹配问题:%d\n",BracketsMatch("{}{{((}}{)}[)[{]](a*}([b+c)]-d)")); //括号匹配问题
//    printf("计算结果:%d \n",RPNExpression(rpn,sizeof(rpn)/sizeof(Cell)));  //逆波兰表达式
//}

// void Test6()
// {
//     BinomialCoefficient(7); //二项式系数
//     Hanoi(5,'A','B','C');  //汉诺塔问题
// }

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    //Test5();
    //Test6();
    return 0;
}

