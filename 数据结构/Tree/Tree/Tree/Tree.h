
#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>


typedef int DatatypeBt;

typedef struct TreeNode//�������ṹ
{
    DatatypeBt _data;
    struct TreeNode *_left;
    struct TreeNode *_right;
}TreeNode;

TreeNode *CreateTree(DatatypeBt *arr,DatatypeBt invalid,size_t value); //����������
TreeNode *CreateTreeR(DatatypeBt *arr,DatatypeBt invalid,size_t *value); //����������
void PrevOrderTreeR(TreeNode *root); // ������� ���ݹ�
void PrevOrderTree(TreeNode *root); // ������� ���ݹ�



#endif//__TREE_H__