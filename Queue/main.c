#include "Queue.h"
void test()
{
    Queue Q;
    QueueInit(&Q);
    QueuePush(&Q,1);
    QueuePush(&Q,2);
    QueuePush(&Q,3);
    QueuePush(&Q,4);
    QueuePush(&Q,15);
    QueuePush(&Q,16);
    QPrint(&Q);
    QueuePop(&Q);
    QPrint(&Q);
    printf("%d  ", QueueBack(&Q));
    printf("%d  ", QueueFront(&Q));
    printf("%d\n", QueueSize(&Q));
}

int main() {
    test();
    return 0;
}
