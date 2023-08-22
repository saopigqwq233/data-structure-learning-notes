#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#include "stdbool.h"
#define null NULL
typedef int BTDataType;

typedef struct BinaryTree{
    BTDataType val;
    struct BinaryTree* left;
    struct BinaryTree* right;
}BTNode;

//申请节点
BTNode *BuyNode(int val);
//生成二叉树
BTNode *CreatBinaryTree();
//销毁二叉树
void BTDestroy(BTNode** root);

//前序遍历
void PreOrder(BTNode* root);
//中序
void InOrder(BTNode* root);
//后序
void PostOrder(BTNode* root);
//树的节点数
int BTSize(BTNode* root);
//叶子节点数
int BTLeaveSize(BTNode* root);
//树的高度
int BTHeight(BTNode* root);
//判断两个树是否相同
bool isSameTree(BTNode* p, BTNode* q);
//判断是否为单值二叉树
bool isUnivalTree(BTNode* root);