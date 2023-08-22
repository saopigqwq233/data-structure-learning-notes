#include "BinaryTree.h"

BTNode *BuyNode(int val)
{
    BTNode *node = (BTNode *) malloc(sizeof(BTNode));
    if (node == null)
    {
    perror("malloc error\n");
    return null;
    }
    //初始化节点
    node->data = val;
    node->left = node->right = null;
    return node;
}

void BTDestroy(BTNode** root)
{
    if(*root==null)//当遍历到空，则停止
        return;

    BTDestroy(&(*root)->left);
    BTDestroy(&(*root)->right);
    free((*root));
    *root=null;
}

void PreOrder(BTNode* root)
{
    if(root==null)
    {
        printf("# ");
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(BTNode* root)
{
    if(root==null)
    {
        printf("# ");
        return;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

void PostOrder(BTNode* root)
{
    if(root==null)
    {
        printf("# ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}

BTNode *CreatBinaryTree()
{
    BTNode *node1= BuyNode(1);
    BTNode *node2= BuyNode(2);
    BTNode *node3= BuyNode(3);
    BTNode *node4= BuyNode(4);
    BTNode *node5= BuyNode(5);
    BTNode *node6= BuyNode(6);
    BTNode *node7= BuyNode(7);
    BTNode *node8= BuyNode(8);
    BTNode *node9= BuyNode(9);
    BTNode *node10= BuyNode(10);
    BTNode *node11= BuyNode(11);

    node1->left=node2;
    node1->right=node3;

    node2->left=node4;
    node2->right=node5;

    node3->left=node6;
    node3->right=node7;

    node4->left=node8;
    node4->right=node9;

    node5->left=node10;
    node5->right=node11;

    node6->left=null;
    node6->right=null;

    node7->left=null;
    node7->right=null;

    node8->left=node8->right=null;
    node9->left=node9->right=null;
    node10->left=node10->right=null;
    node11->left=node11->right=null;

    return node1;
}