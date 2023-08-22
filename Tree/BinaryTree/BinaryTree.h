#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#define null NULL
typedef int BTDataType;

typedef struct BinartTree{
    BTDataType data;
    struct BinartTree* left;
    struct BinartTree* right;
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

