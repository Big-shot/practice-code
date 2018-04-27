#include "SListNode.h"


SListNode *SList,*list1,*list2;

void Test1()
{

    SListPushFront(&SList,5);  //ͷ��
    SListPushFront(&SList,15);
    SListPushBack(&SList,10);  //β��
    SListPushBack(&SList,1);
    SListPushBack(&SList,4);
    SListPushBack(&SList,11);
    SListPushBack(&SList,12);
    SListPushBack(&SList,18);
    SListPushFront(&SList,25);
    SListPushFront(&SList,35);
    SListInsest(&SList,SListFind(SList,18),69); //�������
//     printf("ԭ����:");
//     SListPrint(SList);
//  
}

void Test2()
{
    SList=BuySListNode(2);  //��������    
    SListPushFront(&SList,5);  //ͷ��
    SListPushFront(&SList,15);
    SListPushBack(&SList,10);  //β��
    SListPushBack(&SList,1);
    SListPushBack(&SList,4);
    SListPushBack(&SList,11);
    SListPushBack(&SList,12);
    SListPushBack(&SList,18);
    SListPushFront(&SList,25);
    SListPushFront(&SList,35);
    SListInsest(&SList,SListFind(SList,18),69); //�������
    printf("ԭ����:");
    SListPrint(SList);

    printf("������β��ͷ��ӡ����:");
    EndToFirstPrintNode(SList); //������β��ͷ��ӡ
    printf("\n");
    printf("\n�ö�̬˳���������:");
    EndToFirstPrintSListNode(SList); //�ö�̬˳����������ڴ�ӡ
    printf("\n");
    printf("\n�õݹ鷽����β��ͷ��ӡ:");
    EndToFirstPrintSListNodeR(SList); //�õݹ鷽����β��ͷ��ӡ
    printf("\n");
    printf("\n�����������ڴ�ӡ:");
    EndToFirstPrintSListNodeNon(SList);//�����������ڴ�ӡ
    printf("\n");
    }

void Test3()
{
    SList=BuySListNode(2);  //��������    
    SListPushFront(&SList,5);  //ͷ��
    SListPushFront(&SList,15);
    SListPushBack(&SList,10);  //β��
    SListPushBack(&SList,1);
    SListPushBack(&SList,4);
    SListPushBack(&SList,11);
    SListPushBack(&SList,12);
    SListPushBack(&SList,18);
    SListPushFront(&SList,25);
    SListPushFront(&SList,35);
    SListInsest(&SList,SListFind(SList,18),69); //�������
    printf("ԭ����:");
    SListPrint(SList);

    NoHeadSeqListDelete(SListFind(SList,15)); //ɾ��һ����ͷ����ķ�β�ڵ㣨���ܱ�������
    printf("\nɾ���������(ɾ��15):");
    SListPrint(SList);
    printf("\n");
}

void Test4()
{
    printf("ԭ����:");
    SListPrint(SList);

    NoHeadSeqListInsert(SListFind(SList,12),0); //����ͷ�����һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
    printf("\n����������(12ǰ��0):");
    SListPrint(SList);
    printf("\n");
}

void Test5()
{
    SList=BuySListNode(2);  //��������    
    SListPushFront(&SList,5);  //ͷ��
    SListPushFront(&SList,15);
    SListPushBack(&SList,10);  //β��
    SListPushBack(&SList,1);
    SListPushBack(&SList,4);
    SListPushBack(&SList,11);
    SListPushBack(&SList,12);
    SListPushBack(&SList,18);
    SListPushFront(&SList,25);
    SListPushFront(&SList,35);
    SListInsest(&SList,SListFind(SList,18),69); //�������
    printf("ԭ����:");
    SListPrint(SList);

    printf("βɾ:");
    SListPopBack(&SList);  //βɾ
    SListPrint(SList);
   
    printf("ͷɾ:");
    SListPopFront(&SList);  //ͷɾ
    SListPrint(SList);
}

void Test6()
{
    printf("ԭ����:");
    SListPrint(SList);

    printf("����(2,5,10,1,15)\n");
    printf("%p\n",SListFind(SList,2));  //����
    printf("%p\n",SListFind(SList,5));
    printf("%p\n",SListFind(SList,10));
    printf("%p\n",SListFind(SList,1));
    printf("%p\n",SListFind(SList,15));

    printf("�޸�(5,56),(1,46),(2,36),(10,26)\n");
    SListChange(&SList,SListFind(SList,5),56);   //�޸�
    SListChange(&SList,SListFind(SList,1),46);
    SListChange(&SList,SListFind(SList,2),36);
    SListChange(&SList,SListFind(SList,10),26);
    SListPrint(SList);

}

void Test7()
{
    printf("ԭ����:");
    SListPrint(SList);
    SListErase(&SList,SListFind(SList,35)); //���ɾ��
    SListErase(&SList,SListFind(SList,18));
    SListErase(&SList,SListFind(SList,0));
    SListErase(&SList,SListFind(SList,2));
    printf("ɾ�� (35,18,0,2):");
    SListPrint(SList);

    SListDestory(&SList);  //��������
    printf("��������:");
    SListPrint(SList);

}

void Test8()
{
    printf("ԭ����:");
    SListPrint(SList);

    printf("\n����������(ÿ������ɱһ��):%d\n\n",JosephCircle(SList)->_data);//Լɪ��
}

void Test9()
{
    printf("ԭ����:");
    SListPrint(SList);

    printf("���ú������:");
    SListPrint(ReverseSeqList(SList));//����/��ת������
}

void Test10()
{
    printf("ԭ����:");
    SListPrint(SList);

    printf("ð�ݺ������:");
    SeqListSort(SList);   //ð������
    SListPrint(SList);
    printf("\n");
}

void Test11()
{
    SList=BuySListNode(2);  //��������    
    SListPushFront(&list1,5);  //ͷ��
    SListPushFront(&list1,15);
    SListPushBack(&list1,10);  //β��
    SListPushBack(&list1,12);
    SListPushBack(&list1,11);
    SListPushFront(&list1,25);
    SListPushFront(&list1,35);
    SListPushBack(&list1,28);
    SListPushFront(&list1,25);
    SListPushFront(&list1,35);

    SeqListSort(list1);   //ð������
    printf("����1:");
    SListPrint(list1);

    SListPushBack(&list2,444);  //β��
    SListPushBack(&list2,56);
    SListPushBack(&list2,0);
    SListPushBack(&list2,15);
    SListPushBack(&list2,25);
    SListPushFront(&list2,18);
    SListPushFront(&list2,35);
    SeqListSort(list2);   //ð������
    printf("����2:");
    SListPrint(list2);

    printf("\n");
    printf("�ϲ��������:");
    SListPrint(SListMerge(list1,list2));
}

void Test12()
{
    printf("ԭ����:");
    SListPrint(SList);

    printf("�м�ڵ�ĵ�ַ:%p\n\n",SListFindMidNode(SList));
    printf("�м�ڵ������:%d\n\n",SListFindMidNode(SList)->_data);  //���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������

    printf("������k���ڵ�ĵ�ַ:%p\n\n",SListFindTailKNode(SList,5));
    printf("������k���ڵ�����:%d\n\n",SListFindTailKNode(SList,5)->_data); //���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
    DeleteKNode(SList,5);
    printf("ɾ����k���ڵ�������:");
    SListPrint(SList);
}

void Test13()
{
   // �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ�
    SListNode *entry,*end;
    printf("ԭ����:");
    SListPrint(SList);
    entry=SListFind(SList,1);
    end=SListFind(SList,18);
    end->_next=entry;

    printf("\n����ָ���������ַ:");
    printf("%p\n",CircleSListNode(SList));
    printf("\n����:");
    printf("%d\n",CircleLengthSListNode(CircleSListNode(SList)));  //����
    printf("\n����ڵ�ַ:");
    printf("%p\n",CircleEntrySListNode(SList,CircleSListNode(SList))); //����ڵ�ַ
    printf("\n����ڵ�ַ������:");
    printf("%d\n",CircleEntrySListNode(SList,CircleSListNode(SList))->_data); //����ڵ�ַ
}

void Test14()
{
    SListNode *cross,*end,*entry;
    SListPushFront(&list1,5);  //ͷ��
    SListPushFront(&list1,15);
    SListPushBack(&list1,10);  //β��
    SListPushBack(&list1,12);
    SListPushBack(&list1,11);
    SListPushFront(&list1,25);
    SListPushFront(&list1,35);
    SListPushBack(&list1,28);
    SListPushFront(&list1,25);
    SListPushFront(&list1,35);
    printf("����1:");
    SListPrint(list1);

    SListPushBack(&list2,444);  //β��
    SListPushBack(&list2,56);
    SListPushBack(&list2,0);
    SListPushBack(&list2,15);
    SListPushBack(&list2,25);
    SListPushFront(&list2,18);
    SListPushFront(&list2,35);
    printf("����2:");
    SListPrint(list2);
    
    cross=SListFind(list2,25);
    cross->_next=SListFind(list1,10);

    printf("\n����:");
    printf("%p\n",SListCrossNode(list1,list2)); //�������Ƿ��ཻ
    printf("\n���㴦����:");
    printf("%d\n",SListCrossNode(list1,list2)->_data); 

    entry=SListFind(list1,5);
    end=SListFind(list1,28);
    end->_next=entry;
    printf("\n����:");
    printf("%p\n",SListIsCross(list1,list2));  //�ж��������ཻ�����ܴ�����
    printf("\n���㴦����:");
    printf("%d\n",SListIsCross(list1,list2)->_data);
}

void  Test15()
{
    SListPushFront(&list1,5);  //ͷ��
    SListPushFront(&list1,15);
    SListPushBack(&list1,10);  //β��
    SListPushBack(&list1,12);
    SListPushBack(&list1,11);
    SListPushFront(&list1,25);
    SListPushFront(&list1,3);
    SListPushBack(&list1,28);
    SListPushFront(&list1,2);
    SListPushFront(&list1,35);
    SeqListSort(list1);   //ð������
    printf("����1:");
    SListPrint(list1);
    
    SListPushBack(&list2,4);  //β��
    SListPushBack(&list2,56);
    SListPushBack(&list2,0);
    SListPushBack(&list2,15);
    SListPushBack(&list2,25);
    SListPushFront(&list2,18);
    SListPushFront(&list2,35);
    SeqListSort(list2);
    printf("����2:");
    SListPrint(list2);
    printf("��ͬ������:");

    SListUnionData(list1,list2);//��������������������ͬ�����ݡ�

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

