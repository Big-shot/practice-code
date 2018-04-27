#include "SListNode.h"


SListNode *SList,*list1,*list2;

void Test1()
{

    SListPushFront(&SList,5);  //头插
    SListPushFront(&SList,15);
    SListPushBack(&SList,10);  //尾插
    SListPushBack(&SList,1);
    SListPushBack(&SList,4);
    SListPushBack(&SList,11);
    SListPushBack(&SList,12);
    SListPushBack(&SList,18);
    SListPushFront(&SList,25);
    SListPushFront(&SList,35);
    SListInsest(&SList,SListFind(SList,18),69); //随机插入
//     printf("原链表:");
//     SListPrint(SList);
//  
}

void Test2()
{
    SList=BuySListNode(2);  //创建链表    
    SListPushFront(&SList,5);  //头插
    SListPushFront(&SList,15);
    SListPushBack(&SList,10);  //尾插
    SListPushBack(&SList,1);
    SListPushBack(&SList,4);
    SListPushBack(&SList,11);
    SListPushBack(&SList,12);
    SListPushBack(&SList,18);
    SListPushFront(&SList,25);
    SListPushFront(&SList,35);
    SListInsest(&SList,SListFind(SList,18),69); //随机插入
    printf("原链表:");
    SListPrint(SList);

    printf("正常从尾到头打印链表:");
    EndToFirstPrintNode(SList); //正常从尾到头打印
    printf("\n");
    printf("\n用动态顺序表保存数据:");
    EndToFirstPrintSListNode(SList); //用动态顺序表保存数据在打印
    printf("\n");
    printf("\n用递归方法从尾到头打印:");
    EndToFirstPrintSListNodeR(SList); //用递归方法从尾到头打印
    printf("\n");
    printf("\n先逆置链表在打印:");
    EndToFirstPrintSListNodeNon(SList);//先逆置链表在打印
    printf("\n");
    }

void Test3()
{
    SList=BuySListNode(2);  //创建链表    
    SListPushFront(&SList,5);  //头插
    SListPushFront(&SList,15);
    SListPushBack(&SList,10);  //尾插
    SListPushBack(&SList,1);
    SListPushBack(&SList,4);
    SListPushBack(&SList,11);
    SListPushBack(&SList,12);
    SListPushBack(&SList,18);
    SListPushFront(&SList,25);
    SListPushFront(&SList,35);
    SListInsest(&SList,SListFind(SList,18),69); //随机插入
    printf("原链表:");
    SListPrint(SList);

    NoHeadSeqListDelete(SListFind(SList,15)); //删除一个无头链表的非尾节点（不能遍历链表）
    printf("\n删除后的链表(删除15):");
    SListPrint(SList);
    printf("\n");
}

void Test4()
{
    printf("原链表:");
    SListPrint(SList);

    NoHeadSeqListInsert(SListFind(SList,12),0); //在无头链表的一个节点前插入一个节点（不能遍历链表）
    printf("\n插入后的链表(12前插0):");
    SListPrint(SList);
    printf("\n");
}

void Test5()
{
    SList=BuySListNode(2);  //创建链表    
    SListPushFront(&SList,5);  //头插
    SListPushFront(&SList,15);
    SListPushBack(&SList,10);  //尾插
    SListPushBack(&SList,1);
    SListPushBack(&SList,4);
    SListPushBack(&SList,11);
    SListPushBack(&SList,12);
    SListPushBack(&SList,18);
    SListPushFront(&SList,25);
    SListPushFront(&SList,35);
    SListInsest(&SList,SListFind(SList,18),69); //随机插入
    printf("原链表:");
    SListPrint(SList);

    printf("尾删:");
    SListPopBack(&SList);  //尾删
    SListPrint(SList);
   
    printf("头删:");
    SListPopFront(&SList);  //头删
    SListPrint(SList);
}

void Test6()
{
    printf("原链表:");
    SListPrint(SList);

    printf("查找(2,5,10,1,15)\n");
    printf("%p\n",SListFind(SList,2));  //查找
    printf("%p\n",SListFind(SList,5));
    printf("%p\n",SListFind(SList,10));
    printf("%p\n",SListFind(SList,1));
    printf("%p\n",SListFind(SList,15));

    printf("修改(5,56),(1,46),(2,36),(10,26)\n");
    SListChange(&SList,SListFind(SList,5),56);   //修改
    SListChange(&SList,SListFind(SList,1),46);
    SListChange(&SList,SListFind(SList,2),36);
    SListChange(&SList,SListFind(SList,10),26);
    SListPrint(SList);

}

void Test7()
{
    printf("原链表:");
    SListPrint(SList);
    SListErase(&SList,SListFind(SList,35)); //随机删除
    SListErase(&SList,SListFind(SList,18));
    SListErase(&SList,SListFind(SList,0));
    SListErase(&SList,SListFind(SList,2));
    printf("删除 (35,18,0,2):");
    SListPrint(SList);

    SListDestory(&SList);  //销毁链表
    printf("销毁链表:");
    SListPrint(SList);

}

void Test8()
{
    printf("原链表:");
    SListPrint(SList);

    printf("\n最后活下来的(每走三步杀一个):%d\n\n",JosephCircle(SList)->_data);//约瑟夫环
}

void Test9()
{
    printf("原链表:");
    SListPrint(SList);

    printf("逆置后的链表:");
    SListPrint(ReverseSeqList(SList));//逆置/反转单链表
}

void Test10()
{
    printf("原链表:");
    SListPrint(SList);

    printf("冒泡后的链表:");
    SeqListSort(SList);   //冒泡排序
    SListPrint(SList);
    printf("\n");
}

void Test11()
{
    SList=BuySListNode(2);  //创建链表    
    SListPushFront(&list1,5);  //头插
    SListPushFront(&list1,15);
    SListPushBack(&list1,10);  //尾插
    SListPushBack(&list1,12);
    SListPushBack(&list1,11);
    SListPushFront(&list1,25);
    SListPushFront(&list1,35);
    SListPushBack(&list1,28);
    SListPushFront(&list1,25);
    SListPushFront(&list1,35);

    SeqListSort(list1);   //冒泡排序
    printf("链表1:");
    SListPrint(list1);

    SListPushBack(&list2,444);  //尾插
    SListPushBack(&list2,56);
    SListPushBack(&list2,0);
    SListPushBack(&list2,15);
    SListPushBack(&list2,25);
    SListPushFront(&list2,18);
    SListPushFront(&list2,35);
    SeqListSort(list2);   //冒泡排序
    printf("链表2:");
    SListPrint(list2);

    printf("\n");
    printf("合并后的链表:");
    SListPrint(SListMerge(list1,list2));
}

void Test12()
{
    printf("原链表:");
    SListPrint(SList);

    printf("中间节点的地址:%p\n\n",SListFindMidNode(SList));
    printf("中间节点的数据:%d\n\n",SListFindMidNode(SList)->_data);  //查找单链表的中间节点，要求只能遍历一次链表

    printf("倒数第k个节点的地址:%p\n\n",SListFindTailKNode(SList,5));
    printf("倒数第k个节点数据:%d\n\n",SListFindTailKNode(SList,5)->_data); //查找单链表的倒数第k个节点，要求只能遍历一次链表 
    DeleteKNode(SList,5);
    printf("删除第k个节点后的链表:");
    SListPrint(SList);
}

void Test13()
{
   // 判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。
    SListNode *entry,*end;
    printf("原链表:");
    SListPrint(SList);
    entry=SListFind(SList,1);
    end=SListFind(SList,18);
    end->_next=entry;

    printf("\n快慢指针相遇点地址:");
    printf("%p\n",CircleSListNode(SList));
    printf("\n环长:");
    printf("%d\n",CircleLengthSListNode(CircleSListNode(SList)));  //环长
    printf("\n环入口地址:");
    printf("%p\n",CircleEntrySListNode(SList,CircleSListNode(SList))); //环入口地址
    printf("\n环入口地址处数据:");
    printf("%d\n",CircleEntrySListNode(SList,CircleSListNode(SList))->_data); //环入口地址
}

void Test14()
{
    SListNode *cross,*end,*entry;
    SListPushFront(&list1,5);  //头插
    SListPushFront(&list1,15);
    SListPushBack(&list1,10);  //尾插
    SListPushBack(&list1,12);
    SListPushBack(&list1,11);
    SListPushFront(&list1,25);
    SListPushFront(&list1,35);
    SListPushBack(&list1,28);
    SListPushFront(&list1,25);
    SListPushFront(&list1,35);
    printf("链表1:");
    SListPrint(list1);

    SListPushBack(&list2,444);  //尾插
    SListPushBack(&list2,56);
    SListPushBack(&list2,0);
    SListPushBack(&list2,15);
    SListPushBack(&list2,25);
    SListPushFront(&list2,18);
    SListPushFront(&list2,35);
    printf("链表2:");
    SListPrint(list2);
    
    cross=SListFind(list2,25);
    cross->_next=SListFind(list1,10);

    printf("\n交点:");
    printf("%p\n",SListCrossNode(list1,list2)); //两链表是否相交
    printf("\n交点处数据:");
    printf("%d\n",SListCrossNode(list1,list2)->_data); 

    entry=SListFind(list1,5);
    end=SListFind(list1,28);
    end->_next=entry;
    printf("\n交点:");
    printf("%p\n",SListIsCross(list1,list2));  //判断两链表相交（可能带环）
    printf("\n交点处数据:");
    printf("%d\n",SListIsCross(list1,list2)->_data);
}

void  Test15()
{
    SListPushFront(&list1,5);  //头插
    SListPushFront(&list1,15);
    SListPushBack(&list1,10);  //尾插
    SListPushBack(&list1,12);
    SListPushBack(&list1,11);
    SListPushFront(&list1,25);
    SListPushFront(&list1,3);
    SListPushBack(&list1,28);
    SListPushFront(&list1,2);
    SListPushFront(&list1,35);
    SeqListSort(list1);   //冒泡排序
    printf("链表1:");
    SListPrint(list1);
    
    SListPushBack(&list2,4);  //尾插
    SListPushBack(&list2,56);
    SListPushBack(&list2,0);
    SListPushBack(&list2,15);
    SListPushBack(&list2,25);
    SListPushFront(&list2,18);
    SListPushFront(&list2,35);
    SeqListSort(list2);
    printf("链表2:");
    SListPrint(list2);
    printf("相同的数据:");

    SListUnionData(list1,list2);//求两个已排序单链表中相同的数据。

}

void Test16()
{
    ComplexNode* n1 = BuyComplexNode(1);
    ComplexNode* n2 = BuyComplexNode(2);
    ComplexNode* n3 = BuyComplexNode(3);
    ComplexNode* n4 = BuyComplexNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    n1->random = n4;
    n2->random = n1;
    n3->random = NULL;
    n4->random = n4;
    
    //printf("%p",CopyComplexList(n1));
    ComplexPrint(CopyComplexList(n1));
}
int main()
{
    Test1();
//     Test2();
//     Test3();
//     Test4();
    //Test5();
    //Test6();
    //Test7();
    //Test8();
    //Test9();
    //Test10();
    //Test11();
    //Test12();
    //Test13();
    //Test14();
    Test15();
    //Test16();
    return 0;
}

