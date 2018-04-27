#include "Tree.h"

#include "stack.h"
#pragma   warning(disable:4047)   
#pragma   warning(disable:4024)  

BTNode* BuyTreeNode(BTDataType x) //�������ڵ�
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    assert(node);
    node->left = NULL;
    node->right = NULL;
    node->data = x;

    return node;
}

BTNode* CreateBTree(BTDataType *a,size_t *index,BTDataType invalid)  //����һ�ö�����
{
    BTNode *root = NULL;
    if (a[*index] != invalid) //����ֵ��Ϊ�Ƿ�ֵ�ʹ�����������
    {
        root = BuyTreeNode(a[*index]);
        ++(*index);
        root->left = CreateBTree(a,index,invalid);
        ++(*index);
        root->right = CreateBTree(a,index,invalid);
    }
    return root;
}

void BTreePrevOrderR(BTNode *root)  //ǰ�����
{
    if (NULL == root)  //�ݹ��������
    {
        return;
    }
    printf("%d ",root->data); //��
    BTreePrevOrderR(root->left); //��
    BTreePrevOrderR(root->right);  //��
}

void BTreeInOrderR(BTNode *root)  //�������
{
    if (NULL == root)  //�ݹ��������
    {
        return;
    }
    BTreeInOrderR(root->left);  //��
    printf("%d ",root->data);  //��
    BTreeInOrderR(root->right);  //��
}

void BTreeBackOrderR(BTNode *root)  //�������
{
    if (NULL == root)  //�ݹ��������
    {
        return;
    }
    BTreeBackOrderR(root->left);  //��
    BTreeBackOrderR(root->right);  //��
    printf("%d ",root->data);  //��
}



void BTreePrevOrder(BTNode *root) //������ǰ�����
{
    Stack s;
    BTNode *top = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) != 0 || NULL != tmp) 
    {
        while (NULL != tmp) //����������
        {
            printf("%d ",tmp->data); 
            StackPush(&s,tmp); //��������Ϊ������ջ
            tmp = tmp->left;
        }

        top = StackTop(&s); //������Ϊ�գ�ȡջ��
        StackPop(&s);

        tmp = top->right; //����������
    }
}

void BTreeInOrder(BTNode *root)  //�������
{
    Stack s;
    BTNode *top = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) != 0 || NULL != tmp) 
    {
        while (NULL != tmp) //����������
        {
            if (NULL != tmp)
            {
                StackPush(&s,tmp); //��������Ϊ������ջ
                tmp = tmp->left;
            }
        }
        
        top = StackTop(&s); //������Ϊ�գ�ȡջ��
        printf("%d ",top->data); 
        StackPop(&s);

        tmp = top->right; //����������
    }
}

void BTreeBackOrder(BTNode *root)  //�������
{
    Stack s;
    BTNode *top = NULL;
    BTNode *prev = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) != 0 || NULL != tmp) 
    {
        while (NULL != tmp) //����������
        {
            if (NULL != tmp)
            {
                StackPush(&s,tmp); //��������Ϊ������ջ
                tmp = tmp->left;
            }
        }

        top = StackTop(&s); //������Ϊ�գ�ȡջ��
        if (NULL == top->right || top->right == prev)
        {
            printf("%d ",top->data);  //���ʸ��ڵ�
            prev = top;
            StackPop(&s);
        }
        else
           tmp = top->right; //����������
    }
}

void BTreeFloorOrder(BTNode *root)  //�������
{
   Queue q;
   BTNode *tmp = root;
   QueueInit(&q);
   QueuePush(&q,tmp);
   while (QueueEmpty(&q)) //ȡ��ͷԪ�ط��ʣ���ͬʱ��Ӹ�Ԫ�ص����ҷǿ������ڵ�
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

size_t BTreeLenth(BTNode* root) // ��������ĸ߶�
{
    if (root==NULL)
    {
        return 0;
    }
    
    if (BTreeLenth(root->left)>=BTreeLenth(root->right))  //�������Ҹ߶��иߵ�һ���ټ�һ
        return BTreeLenth(root->left)+1;
    else
        return BTreeLenth(root->right)+1;
    
}

size_t BTreeLeafNumber(BTNode* root) //�������Ҷ�ӽ��ĸ���
{
    if (root == NULL)  //�ݹ��������
    {
        return 0;
    }
    
    if (NULL == root->right)   //�����ΪNULLʱ������ұ�ҲΪNULL����ΪҶ�ӽڵ�
        return 1;
   
    return BTreeLeafNumber(root->left)+BTreeLeafNumber(root->right);  //������Ҷ��+������Ҷ��
}

size_t BTreeNodeNumber(BTNode *root)// ����������ĸ���
{
    if (NULL == root)  //�ݹ��������
    {
        return 0;
    }

    return BTreeNodeNumber(root->left) + BTreeNodeNumber(root->right)+1; //�������ڵ��� + �������ڵ� + 1
}

size_t BTreeKLevelNodeNumber(BTNode* root, size_t k) //���������K����ĸ���
{
    if (root == NULL || k<1)
    {
        return 0;
    }
    
    if (k==1)
    {
        return 1;
    }
    //��������Ϊ�գ�������������ͬʱΪ�գ�������������Ҷ�ӽڵ����������������Ҷ�ӽڵ����   
    return BTreeKLevelNodeNumber(root->left,k-1) + BTreeKLevelNodeNumber(root->right,k-1);
}

BTNode* BTreeNodeFind(BTNode* root, BTDataType x) //�ж�һ���ڵ��Ƿ���һ�ö������У���������Ƚϣ�
{
    Queue q;
    BTNode *tmp = root;
    QueueInit(&q);
    QueuePush(&q,tmp);
    while (QueueEmpty(&q)) //ȡ��ͷԪ�ط��ʣ���ͬʱ��Ӹ�Ԫ�ص����ҷǿ������ڵ�
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);
        if (front->data == x) //�ҵ���Ԫ���򷵻ظ�Ԫ�ص�ַ
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
    return NULL; //û�ҵ�
}

BTNode* GetBTreeParents(BTNode *root,BTNode *node) //��ȡһ���ڵ��˫�׽��(�������)
{
    Queue q;
    BTNode *tmp = root;
    if (root == node)  //�ýڵ�Ϊ���ڵ�
    {
        return NULL;
    }
    QueueInit(&q);
    QueuePush(&q,tmp);
    while (QueueEmpty(&q)) //ȡ��ͷԪ�ط��ʣ���ͬʱ��Ӹ�Ԫ�ص����ҷǿ������ڵ�
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
    return NULL; //û�иýڵ�
}

BTNode* GetNodeLeftChild(BTNode *root,BTNode *node)//��ȡһ���ڵ�����ӽ��(�������)
{
    Queue q;
    BTNode *tmp = root;
    QueueInit(&q);
    QueuePush(&q,tmp);
    while (QueueEmpty(&q)) //ȡ��ͷԪ�ط��ʣ���ͬʱ��Ӹ�Ԫ�ص����ҷǿ������ڵ�
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
    return NULL; //û�иýڵ�
}

static void Swap(BTNode **left,BTNode **right)  //����
{
    BTNode *tmp;
    tmp = *left;
    *left = *right;
    *right = tmp;
}

BTNode* BTreeMirrorR(BTNode *root)// ��������ľ���(�ݹ�)
{
    if (root == NULL)
    {
        return NULL;
    }
    BTreeMirrorR(root->left);
    BTreeMirrorR(root->right);
    Swap(&root->left,&root->right);  //���ҽ���
   
    return root;
}

BTNode* BTreeMirror(BTNode *root)// ��������ľ���(�ǵݹ�)
{
    Stack s;
    BTNode *top = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) != 0 || NULL != tmp) 
    {
        while (tmp) //����������
        {
            StackPush(&s,tmp); //��������Ϊ������ջ
            tmp = tmp->left;
        }

        top = StackTop(&s); //������Ϊ�գ�ȡջ��
        Swap(&top->left,&top->right);
        StackPop(&s);

        tmp = top->right; //������
    }
    return root;
}

size_t CheckBTree(BTNode *root)// �ж�һ�ö������Ƿ�Ϊ��ȫ������(�����������)
{
    Queue q;
    BTNode *tmp = root;
    QueueInit(&q);
    QueuePush(&q,tmp);
    while (QueueEmpty(&q)) //ȡ��ͷԪ�ط��ʣ���ͬʱ��Ӹ�Ԫ�ص����ҷǿ������ڵ�
    {
        BTNode *front = QueueFront(&q);
        if (front)
            QueuePop(&q);
        else
            break;
        QueuePush(&q,front->left);
        QueuePush(&q,front->right);
    }
    while (QueueEmpty(&q)) //����ӵ�һ����Ԫ�غ���û�зǿ�Ԫ�أ�������ȫ�����������򣬲��ǡ�
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

size_t CheckBTreeF(BTNode *root)  // flag�ķ�ʽ�ж� 
{
    Stack s;
    size_t flag = 1;
    BTNode *top = NULL;
    BTNode *tmp = root;
    StackInit(&s);
    while (StackEmpty(&s) || tmp ) 
    {
        while (tmp) //����������
        {
            StackPush(&s,tmp); //��������Ϊ������ջ
            tmp = tmp->left;
            flag = 0;
        }

        top = StackTop(&s); //������Ϊ�գ�ȡջ��
        StackPop(&s);
        if (!top->left && top->right) //������ = NULL,������ != NULL.
        {
            flag = 1;
            break;
        }
        tmp = top->right; //����������

    }
    if (flag == 0)
        return 1;
    else
        return 0;
}

