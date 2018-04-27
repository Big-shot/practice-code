#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include<string.h>

typedef char* KeyType;
typedef int ValueType;


typedef struct BSTreeNode 
{
    struct BSTreeNode *_left;
    struct BSTreeNode *_right;

    KeyType _key;
    ValueType _count;
}BSTreeNode;

////�ǵݹ�
//BSTreeNode *BuyTreeNode(KeyType x); //�����ڵ�
//int BSTreeNodeInsert(BSTreeNode **tree,KeyType x); //�������Ĳ���
//int BSTreeNodeDel(BSTreeNode **tree,KeyType x); //ɾ��
//BSTreeNode *BSTreeNodeFind(BSTreeNode *tree,KeyType x); //����
//void BSTreeNodeDestory(BSTreeNode **tree); //����

//�ݹ�

int BSTreeNodeInsertR(BSTreeNode **tree,KeyType key); //�������Ĳ���
int BSTreeNodeDelR(BSTreeNode **tree,KeyType key); //ɾ��
BSTreeNode *BSTreeNodeFindR(BSTreeNode *tree,KeyType const key); //����

typedef int Datatype;
int CheckArryIsAfterOrder(Datatype *a,size_t len); 

#define K 4


#endif //__BSTREE_H__
