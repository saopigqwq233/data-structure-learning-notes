#include "BinaryTree.h"

int main() {
    BTNode *root=CreatBinaryTree();
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");


    printf("�ڵ�����%d\n", BTSize(root));
    printf("�ڵ�����%d\n", BTLeaveSize(root));
    printf("�������߶ȣ�%d\n", BTHeight(root));

    BTDestroy(&root);
    return 0;
}
