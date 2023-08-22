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
    node->val = val;
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
    printf("%d ",root->val);
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
    printf("%d ",root->val);
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
    printf("%d ",root->val);
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

    node5->left=null;
    node5->right=null;

    node6->left=null;
    node6->right=null;

    node7->left=null;
    node7->right=node11;

    node8->left=node8->right=null;
    node9->left=node9->right=null;
    node10->left=node10->right=null;
    node11->left=node10;
    node11->right=null;

    return node1;
}

int BTSize(BTNode* root)
{
    //法一：判断
/*    if(root==null)
    {
        return 0;
    }
    return BTSize(root->left)+ BTSize(root->_right)+1;
    */
    //法二：三目运算
    return root==null?0:(BTSize(root->left) + BTSize(root->right) + 1);
}
int BTLeaveSize(BTNode* root)
{
    if(root==null)
        return 0;
    if(root->left==null&& root->right == null)
        return 1;
    return BTLeaveSize(root->left)+ BTLeaveSize(root->right);
}
int BTHeight(BTNode* root)
{
    //分治思想
    //判断左/右数哪个度更高，返回1+（更大的数）

    if(root==null)
    {
        return 0;
    }
    int lefttree= BTHeight(root->left);
    int righttree= BTHeight(root->right);
    return (lefttree>righttree)?(lefttree+1):(righttree+1);
}


bool isSameTree(BTNode* p, BTNode* q)
{
    //分治思想
    //把p，q两棵树看作是一棵树的左右子树
    //根节点相同，只要左右子树相同就说明p，q相同
    if(p==null&&q==null)//两者都为空，返回对
        return true;
    if(p==null||q==null)//不可能两个都空，则一旦有一个空：  一个为空，一个不为空
        return false;
    else if(p->val==q->val)
    {
        bool lefttree=isSameTree(p->left,q->left);
        bool righttree= isSameTree(p->right,q->right);
        return lefttree&&righttree;
    }
}
bool isUnivalTree(BTNode* root)
{
    //分治思想
    //分别判断左右子树是否为单值
    if(root==NULL)
        return true;
    if(root->left==NULL&&root->right==NULL)
        return true;
    if(root->left&&root->val!=root->left->val)
        return false;
    if(root->right&&root->val!=root->right->val)
        return false;

    return isUnivalTree(root->left)&& isUnivalTree(root->right);
}