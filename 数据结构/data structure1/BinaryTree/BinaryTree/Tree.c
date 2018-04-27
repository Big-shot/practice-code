#include "Tree.h"

#include "stack.h"
#pragma   warning(disable:4047)   
#pragma   warning(disable:4024)  

BTNode* BuyTreeNode(BTDataType x) //创建树节点
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    assert(node);
    node->left = NULL;
    node->right = NULL;
    node->data = x;

    return node;
}

BTNode* CreateBTree(BTDataType *a,size_t *index,BTDataType invalid)  //创建一棵二叉树
{
    BTNode *root = NULL;
    if (a[*index] != invalid) //序列值不为非法值就创建左右子树
    {
        root = BuyTreeNode(a[*index]);
        ++(*index);
        root->left = CreateBTree(a,index,invalid);
        ++(*index);
        root->right = CreateBTree(a,index,invalid);
    }
    return root;
}

void BTreePrevOrderR(BTNode *root)  //前序遍历
{
    if (NULL == root)  //递归结束条件
    {
        return;
    }
    printf("%d ",root->data); //根
    BTreePrevOrderR(root->left); //左
    BTreePrevOrderR(root->right);  //右
}

void BTreeInOrderR(BTNode *root)  //中序遍历
{
    if (NULL == root)  //递归结束条件
    {
        return;
    }
    BTreeInOrderR(root->left);  //左
    printf("%d ",root->data);  //根
    BTreeInOrderR(root->right);  //右
}

void BTreeBackOrderR(BTNode *root)  //后序遍历
{
    if (NULL == root)  //递归结束条件
    {
        return;
    }
    BTreeBackOrderR(root->left);  //左
    BTreeBackOrderR(root->right);  //右
    printf("%d ",root->data);  //根
}



void BTreePrevOrder(BTNode *root) //迭代法前序遍历
{
    Stack s;
    BTNode *top = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) != 0 || NULL != tmp) 
    {
        while (NULL != tmp) //遍历左子树
        {
            printf("%d ",tmp->data); 
            StackPush(&s,tmp); //左子树不为空则入栈
            tmp = tmp->left;
        }

        top = StackTop(&s); //左子树为空，取栈顶
        StackPop(&s);

        tmp = top->right; //访问右子树
    }
}

void BTreeInOrder(BTNode *root)  //中序遍历
{
    Stack s;
    BTNode *top = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) != 0 || NULL != tmp) 
    {
        while (NULL != tmp) //遍历左子树
        {
            if (NULL != tmp)
            {
                StackPush(&s,tmp); //左子树不为空则入栈
                tmp = tmp->left;
            }
        }
        
        top = StackTop(&s); //左子树为空，取栈顶
        printf("%d ",top->data); 
        StackPop(&s);

        tmp = top->right; //访问右子树
    }
}

void BTreeBackOrder(BTNode *root)  //后序遍历
{
    Stack s;
    BTNode *top = NULL;
    BTNode *prev = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) != 0 || NULL != tmp) 
    {
        while (NULL != tmp) //遍历左子树
        {
            if (NULL != tmp)
            {
                StackPush(&s,tmp); //左子树不为空则入栈
                tmp = tmp->left;
            }
        }

        top = StackTop(&s); //左子树为空，取栈顶
        if (NULL == top->right || top->right == prev)
        {
            printf("%d ",top->data);  //访问根节点
            prev = top;
            StackPop(&s);
        }
        else
           tmp = top->right; //访问右子树
    }
}

void BTreeFloorOrder(BTNode *root)  //层序遍历
{
   Queue q;
   BTNode *tmp = root;
   QueueInit(&q);
   QueuePush(&q,tmp);
   while (QueueEmpty(&q)) //取队头元素访问，并同时入队该元素的左右非空子树节点
   {
       BTNode *front = QueueFront(&q);
       QueuePop(&q);
       printf("%d ",front->data);
       if (front->left)
       {
           QueuePush(&q,front->left);
       }
       if (front->right)
       {
           QueuePush(&q,front->right);
       }
   }
}

size_t BTreeLenth(BTNode* root) // 求二叉树的高度
{
    if (root==NULL)
    {
        return 0;
    }
    
    if (BTreeLenth(root->left)>=BTreeLenth(root->right))  //返回左右高度中高的一个再加一
        return BTreeLenth(root->left)+1;
    else
        return BTreeLenth(root->right)+1;
    
}

size_t BTreeLeafNumber(BTNode* root) //求二叉树叶子结点的个数
{
    if (root == NULL)  //递归结束条件
    {
        return 0;
    }
    
    if (NULL == root->right)   //当左边为NULL时，如果右边也为NULL，则为叶子节点
        return 1;
   
    return BTreeLeafNumber(root->left)+BTreeLeafNumber(root->right);  //左子树叶子+右子树叶子
}

size_t BTreeNodeNumber(BTNode *root)// 求二叉树结点的个数
{
    if (NULL == root)  //递归结束条件
    {
        return 0;
    }

    return BTreeNodeNumber(root->left) + BTreeNodeNumber(root->right)+1; //左子树节点数 + 右子树节点 + 1
}

size_t BTreeKLevelNodeNumber(BTNode* root, size_t k) //求二叉树第K层结点的个数
{
    if (root == NULL || k<1)
    {
        return 0;
    }
    
    if (k==1)
    {
        return 1;
    }
    //二叉树不为空，且左右子树不同时为空，返回左子树中叶子节点个数加上右子树中叶子节点个数   
    return BTreeKLevelNodeNumber(root->left,k-1) + BTreeKLevelNodeNumber(root->right,k-1);
}

BTNode* BTreeNodeFind(BTNode* root, BTDataType x) //判断一个节点是否在一棵二叉树中（层序遍历比较）
{
    Queue q;
    BTNode *tmp = root;
    QueueInit(&q);
    QueuePush(&q,tmp);
    while (QueueEmpty(&q)) //取队头元素访问，并同时入队该元素的左右非空子树节点
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);
        if (front->data == x) //找到该元素则返回该元素地址
        {
            return front;
        }
        if (front->left)
        {
            QueuePush(&q,front->left);
        }
        if (front->right)
        {
            QueuePush(&q,front->right);
        }
    }
    return NULL; //没找到
}

BTNode* GetBTreeParents(BTNode *root,BTNode *node) //获取一个节点的双亲结点(层序遍历)
{
    Queue q;
    BTNode *tmp = root;
    if (root == node)  //该节点为根节点
    {
        return NULL;
    }
    QueueInit(&q);
    QueuePush(&q,tmp);
    while (QueueEmpty(&q)) //取队头元素访问，并同时入队该元素的左右非空子树节点
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);
        
        if (front->left == node)
            return front;
        else
            QueuePush(&q,front->left);
        if (front->right == node)
            return front;
        else
            QueuePush(&q,front->right);
    }
    return NULL; //没有该节点
}

BTNode* GetNodeLeftChild(BTNode *root,BTNode *node)//获取一个节点的左孩子结点(层序遍历)
{
    Queue q;
    BTNode *tmp = root;
    QueueInit(&q);
    QueuePush(&q,tmp);
    while (QueueEmpty(&q)) //取队头元素访问，并同时入队该元素的左右非空子树节点
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);

        if (front== node)
            return front->left;
        else
        {
            QueuePush(&q,front->left);
            QueuePush(&q,front->right);
        }
    }
    return NULL; //没有该节点
}

static void Swap(BTNode **left,BTNode **right)  //交换
{
    BTNode *tmp;
    tmp = *left;
    *left = *right;
    *right = tmp;
}

BTNode* BTreeMirrorR(BTNode *root)// 求二叉树的镜像(递归)
{
    if (root == NULL)
    {
        return NULL;
    }
    BTreeMirrorR(root->left);
    BTreeMirrorR(root->right);
    Swap(&root->left,&root->right);  //左右交换
   
    return root;
}

BTNode* BTreeMirror(BTNode *root)// 求二叉树的镜像(非递归)
{
    Stack s;
    BTNode *top = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) != 0 || NULL != tmp) 
    {
        while (tmp) //遍历左子树
        {
            StackPush(&s,tmp); //左子树不为空则入栈
            tmp = tmp->left;
        }

        top = StackTop(&s); //左子树为空，取栈顶
        Swap(&top->left,&top->right);
        StackPop(&s);

        tmp = top->right; //右子树
    }
    return root;
}

size_t CheckBTree(BTNode *root)// 判断一棵二叉树是否为完全二叉树(层序遍历变形)
{
    Queue q;
    BTNode *tmp = root;
    QueueInit(&q);
    QueuePush(&q,tmp);
    while (QueueEmpty(&q)) //取队头元素访问，并同时入队该元素的左右非空子树节点
    {
        BTNode *front = QueueFront(&q);
        if (front)
            QueuePop(&q);
        else
            break;
        QueuePush(&q,front->left);
        QueuePush(&q,front->right);
    }
    while (QueueEmpty(&q)) //如果从第一个空元素后面没有非空元素，则是完全二叉树，否则，不是。
    {
        BTNode *front = QueueFront(&q);
        if (front)
        {
            return 0;
        }
        QueuePop(&q);
    }
    return 1;
}

size_t CheckBTreeF(BTNode *root)  // flag的方式判断 
{
    Stack s;
    size_t flag = 1;
    BTNode *top = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) || tmp ) 
    {
        while (tmp) //遍历左子树
        {
            StackPush(&s,tmp); //左子树不为空则入栈
            tmp = tmp->left;
            flag = 0;
        }

        top = StackTop(&s); //左子树为空，取栈顶
        StackPop(&s);
        if (!top->left && top->right) //左子树 = NULL,右子树 != NULL.
        {
            flag = 1;
            break;
        }
        tmp = top->right; //访问右子树

    }
    if (flag == 0)
        return 1;
    else
        return 0;
}

