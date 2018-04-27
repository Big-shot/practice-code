
#include "BSTree.h"

BSTreeNode *BuyTreeNode(KeyType key) //�����ڵ�
{
    BSTreeNode *node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
    assert(node);

    node->_key = key;
    node->_count = 1;

    node->_left = NULL;
    node->_right = NULL;

    return node;
}

//int BSTreeNodeInsert(BSTreeNode **pptree,DataType x) //�������Ĳ���
//{
//    BSTreeNode *parent = NULL;
//    BSTreeNode *cur = *pptree;
//    if (*pptree == NULL)
//    {
//        *pptree = BuyTreeNode(x);
//        return 0;
//    }
//    while (cur)
//    {
//      parent = cur;
//      if (cur->_data > x)
//          cur = cur->_left;
//      else if (cur->_data < x)
//          cur = cur->_right;
//      else
//          return -1;
//    }
//
//    if (parent->_data > x)
//        parent->_left = BuyTreeNode(x);
//    else 
//        parent->_right = BuyTreeNode(x);
//
//    return 0;
//}
//
//
//int BSTreeNodeDel(BSTreeNode **tree,DataType x) //ɾ��
//{
//
//    BSTreeNode *cur = *tree;
//    BSTreeNode *parent = *tree;
//    BSTreeNode *del = NULL;
//    
//    while (cur)
//    {
//        if (cur->_data > x)
//        {
//            parent = cur;
//            cur = cur->_left;
//        }
//        else if (cur->_data < x)
//        {
//            parent = cur;
//            cur = cur->_right;
//        }
//        else
//        {
//            del = cur;
//
//            if (cur->_left == NULL) //1������Ϊ��
//            {
//                if (parent->_left == cur)
//                    parent->_left = cur->_right;
//                else if (parent->_right == cur)
//                    parent->_right = cur->_right;
//                else if (parent == cur) //û�и��׽ڵ�ʱ
//                   *tree = parent->_right;
//            }
//            else if (cur->_right == NULL) //2���Һ���Ϊ��
//            {
//                if (parent->_left == cur)
//                    parent->_left = cur->_left;
//                else if (parent->_right == cur)
//                    parent->_right = cur->_left;
//                else if (parent == cur) //û�и��׽ڵ�ʱ
//                    *tree = parent->_left;
//            }
//            else//3�����Һ��Ӷ���Ϊ��
//            {
//                BSTreeNode *sub = cur->_right;
//                while (sub->_left)
//                {
//                    parent = sub;
//                    sub = sub->_left;
//                }
//                   
//                del = sub;
//                cur->_data = sub->_data;
//
//                if (parent->_left == sub)
//                    parent->_left = sub->_right;
//                else 
//                    parent->_right = sub->_right;
//            }
//
//            free(del);
//            del = NULL;
//            return 0;
//
//        }
//    }
//
//    return -1;
//}
//
//BSTreeNode *BSTreeNodeFind(BSTreeNode *tree,DataType x) //����
//{
//    while (tree)
//    {
//        if (tree->_data == x)
//            return tree;
//        else if (tree->_data < x)
//            tree = tree->_right;
//        else 
//            tree = tree->_left;
//    }
//
//    return NULL;
//}
//
//void BSTreeNodeDestory(BSTreeNode **tree) //����
//{
//    if (*tree == NULL)
//        return;
//
//    BSTreeNodeDestory(&(*tree)->_left);
//    BSTreeNodeDestory(&(*tree)->_right);
//    free(*tree);
//    *tree = NULL;
//}

int BSTreeNodeInsertR(BSTreeNode **tree,KeyType key) //�������Ĳ���
{
    int tmp = 0;
    if(*tree == NULL)
    {
        *tree = BuyTreeNode(key);
        return 0;
    }
    
    tmp  = strcmp((*tree)->_key,key);
    if (tmp>0)
        return BSTreeNodeInsertR(&(*tree)->_left,key);
    else if (tmp<0)
        return BSTreeNodeInsertR(&(*tree)->_right,key);
    else
        (*tree)->_count++;
}

//int BSTreeNodeDelR(BSTreeNode **tree,KeyType key) //ɾ��
//{
//    if (!*tree)
//        return -1;
//
//    if ((*tree)->_data > key)
//        return BSTreeNodeDelR(&(*tree)->_left,key);
//    else if ((*tree)->_data < key)
//        return BSTreeNodeDelR(&(*tree)->_right,key);
//    else
//    {
//        BSTreeNode *del = *tree;
//        if (!(*tree)->_left) //��Ϊ��
//            *tree = (*tree)->_right;
//        else if (!(*tree)->_right) //��Ϊ��
//             *tree = (*tree)->_left;
//        else //���Ҷ���Ϊ��
//        {
//            BSTreeNode *sub = (*tree)->_right;
//            BSTreeNode *parent = *tree;
//            while (sub->_left)
//            {
//                parent = sub;
//                sub = sub->_left;
//            }
//            del = sub;
//            if (parent->_left == sub)
//                parent->_left = sub->_right;
//            else 
//                parent->_right = sub->_right;
//            (*tree)->_data = sub->_data;
//
//            //return BSTreeNodeDelR(&(*tree)->_right,sub->_data);
//        }
//
//        free(del);
//        del = NULL;
//        return 0;
//    }
//}

BSTreeNode *BSTreeNodeFindR(BSTreeNode *tree,KeyType const key) //����
{
    int tmp = 0;
    if (!tree)
        return NULL;
    
    tmp = strcmp(tree->_key,key);
    if (tmp > 0)
        return BSTreeNodeFindR(tree->_left,key);
    else if (tmp < 0)
        return BSTreeNodeFindR(tree->_right,key);
    else
        return tree;
}

int CheckArryIsAfterOrder(Datatype *a,size_t len) //�ж�һ�������Ƿ��Ƕ������ĺ������
{
    size_t tmp = len-1;
    size_t i = 0,j = 0;
    int right = 0;
    for (i=0; i<len-1; i++)
    {
        if (a[i] > a[tmp])
            break;
    }
    for (j=i;j<len-1; j++)
    {
        if (a[j] < a[tmp])
            return -1;
    }
    right = 1; 

    if (i>0)
       CheckArryIsAfterOrder(a,i);
    return 1;
}
