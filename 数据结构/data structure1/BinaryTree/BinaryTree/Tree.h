#ifndef __TREE_H__
#define __TREE_H__

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>

typedef int BTDataType;

typedef struct BTNode //树结构
{
    BTDataType data;
    struct BTNode *left;
    struct BTNode *right;
}BTNode;

BTNode* CreateBTree(BTDataType *a,size_t *index,BTDataType invalid);  //创建一棵二叉树
void BTreePrevOrderR(BTNode *root); //前序遍历
void BTreeInOrderR(BTNode *root);  //中序遍历
void BTreeBackOrderR(BTNode *root);  //后序遍历

void BTreePrevOrder(BTNode *root); //前序遍历
void BTreeInOrder(BTNode *root);  //中序遍历
void BTreeBackOrder(BTNode *root);  //后序遍历
void BTreeFloorOrder(BTNode *root);  //层序遍历

size_t BTreeLenth(BTNode* root); // 求二叉树的高度
size_t BTreeLeafNumber(BTNode* root); //求二叉树叶子结点的个数
size_t BTreeNodeNumber(BTNode *root);// 求二叉树结点的个数
size_t BTreeKLevelNodeNumber(BTNode* root, size_t k); //求二叉树第K层结点的个数
BTNode* BTreeNodeFind(BTNode* root, BTDataType x) ; //判断一个节点是否在一棵二叉树中
BTNode* GetBTreeParents(BTNode *root,BTNode *node); //获取一个节点的双亲结点
BTNode* GetNodeLeftChild(BTNode *root,BTNode *node);//获取一个节点的左孩子结点
BTNode* BTreeMirrorR(BTNode *root);// 求二叉树的镜像(递归&非递归)
BTNode* BTreeMirror(BTNode *root);// 求二叉树的镜像(非递归)
size_t CheckBTree(BTNode *root);// 判断一棵二叉树是否为完全二叉树(层序遍历变形)
size_t CheckBTreeF(BTNode* root) ;// flag的方式判断 

//二叉树的线索化


#endif //__TREE_H__


