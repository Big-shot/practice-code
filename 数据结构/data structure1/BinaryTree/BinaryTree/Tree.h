#ifndef __TREE_H__
#define __TREE_H__

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>

typedef int BTDataType;

typedef struct BTNode //���ṹ
{
    BTDataType data;
    struct BTNode *left;
    struct BTNode *right;
}BTNode;

BTNode* CreateBTree(BTDataType *a,size_t *index,BTDataType invalid);  //����һ�ö�����
void BTreePrevOrderR(BTNode *root); //ǰ�����
void BTreeInOrderR(BTNode *root);  //�������
void BTreeBackOrderR(BTNode *root);  //�������

void BTreePrevOrder(BTNode *root); //ǰ�����
void BTreeInOrder(BTNode *root);  //�������
void BTreeBackOrder(BTNode *root);  //�������
void BTreeFloorOrder(BTNode *root);  //�������

size_t BTreeLenth(BTNode* root); // ��������ĸ߶�
size_t BTreeLeafNumber(BTNode* root); //�������Ҷ�ӽ��ĸ���
size_t BTreeNodeNumber(BTNode *root);// ����������ĸ���
size_t BTreeKLevelNodeNumber(BTNode* root, size_t k); //���������K����ĸ���
BTNode* BTreeNodeFind(BTNode* root, BTDataType x) ; //�ж�һ���ڵ��Ƿ���һ�ö�������
BTNode* GetBTreeParents(BTNode *root,BTNode *node); //��ȡһ���ڵ��˫�׽��
BTNode* GetNodeLeftChild(BTNode *root,BTNode *node);//��ȡһ���ڵ�����ӽ��
BTNode* BTreeMirrorR(BTNode *root);// ��������ľ���(�ݹ�&�ǵݹ�)
BTNode* BTreeMirror(BTNode *root);// ��������ľ���(�ǵݹ�)
size_t CheckBTree(BTNode *root);// �ж�һ�ö������Ƿ�Ϊ��ȫ������(�����������)
size_t CheckBTreeF(BTNode* root) ;// flag�ķ�ʽ�ж� 

//��������������


#endif //__TREE_H__


