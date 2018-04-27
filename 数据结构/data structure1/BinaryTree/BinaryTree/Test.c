#include "Tree.h"
#include "stack.h"

 void Test1()
 {
     BTDataType a[] = {1,2,3,'#','#',4,5,'#','#',6,'#','#',7,8,'#',9,'#','#','#'};
     BTDataType index = 0;
     BTNode *tree = CreateBTree(a,&index,'#');
     //BTreePrevOrderR(tree); //前序遍历
     //BTreeInOrderR(tree);  //中序遍历
     //BTreeBackOrderR(tree);  //后序遍历
     BTreePrevOrder(tree); //非递归前序遍历
     //BTreeInOrder(tree);  //非递归中序遍历
     //BTreeBackOrder(tree); //非递归后序遍历
    //BTreeFloorOrder(tree);//层序遍历
    printf("\n");
}

//void Test2()
//{
//    //BTDataType a[] = {1,2,3,'#','#',4,'#','#',7,8,'#','#','#'};
//    BTDataType a[] = {1,2,3,'#','#',4,5,'#','#',6,'#','#',7,8,'#',9,'#','#','#'};
//    BTDataType index = 0;
//    BTNode *tree = CreateBTree(a,&index,'#');
//    BTreePrevOrderR(tree); //前序遍历
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