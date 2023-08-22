#include "BinaryTree.h"

int main() {
    BTNode *root=CreatBinaryTree();
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
    BTDestroy(&root);
    return 0;
}
