#include "Tree.h"
#include "stack.h"

 void Test1()
 {
     BTDataType a[] = {1,2,3,'#','#',4,5,'#','#',6,'#','#',7,8,'#',9,'#','#','#'};
     BTDataType index = 0;
     BTNode *tree = CreateBTree(a,&index,'#');
     //BTreePrevOrderR(tree); //ǰ�����
     //BTreeInOrderR(tree);  //�������
     //BTreeBackOrderR(tree);  //�������
     BTreePrevOrder(tree); //�ǵݹ�ǰ�����
     //BTreeInOrder(tree);  //�ǵݹ��������
     //BTreeBackOrder(tree); //�ǵݹ�������
    //BTreeFloorOrder(tree);//�������
    printf("\n");
}

//void Test2()
//{
//    //BTDataType a[] = {1,2,3,'#','#',4,'#','#',7,8,'#','#','#'};
//    BTDataType a[] = {1,2,3,'#','#',4,5,'#','#',6,'#','#',7,8,'#',9,'#','#','#'};
//    BTDataType index = 0;
//    BTNode *tree = CreateBTree(a,&index,'#');
//    BTreePrevOrderR(tree); //ǰ�����
//
//    printf("%d \n",BTreeLenth(tree));
//    printf("%d \n",BTreeLeafNumber(tree));
//    printf("%d \n",BTreeNodeNumber(tree));
//    printf("%d \n",BTreeKLevelNodeNumber(tree,3));
//    printf("%p \n",BTreeNodeFind(tree,2));
//    printf("%p \n",GetBTreeParents(tree,BTreeNodeFind(tree,4)));
//    printf("%p \n",GetNodeLeftChild(tree,BTreeNodeFind(tree,1)));
//    tree = BTreeMirrorR(tree);
//    tree = BTreeMirror(tree);
//    printf("%d \n",CheckBTree(tree));
//    printf("%d \n",CheckBTreeF(tree));
//}

int main()
{
    Test1();
    //Test2();
    return 0;
}