#include "BinaryTree.h"

int main() {
    BTNode *root=CreatBinaryTree();
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");


    printf("节点数：%d\n", BTSize(root));
    printf("节点数：%d\n", BTLeaveSize(root));
    printf("二叉树高度：%d\n", BTHeight(root));

    BTDestroy(&root);
    return 0;
}
