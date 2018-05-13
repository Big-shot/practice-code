#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct BtNode
{
	struct BtNode *_left;
	struct BtNode *_right;
	int _data;
}PBTNode;

typedef struct stack
{
	int _data;
}stack;

typedef enum
{
	THREAD,
	LINK,
}Cue;

typedef struct BTNode
{
	struct BTNode*  _left;
	struct BTNode* _right;
	int  _data;
	Cue* _lefthread;
	Cue* _rightthread;
}BTNode;

void CuePrevorder(PBTNode *root)
{

}


void PostOrder(PBTNode* root)
{
	PBTNode* cur = root;
	PBTNode* top = NULL;
	PBTNode* prev = NULL;
	stack s;
	stackinit(&s);

	while (!stackEmpty(&s) || cur)
	{
		while (cur)
		{
			stackpush(&s, cur);
			cur = cur->_left;
		}

		top = stacktop(&s);
		if (!top->_right || prev == top->_right)
		{
			printf("%d ", top->_data);
			prev = top;
			stackpop(&s);
		}
		else
			cur = top->_right;
	}
}


