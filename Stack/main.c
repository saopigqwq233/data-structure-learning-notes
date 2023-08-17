#include "Stack.h"
void test(void )
{
    ST Stack;
    STinit(&Stack);
    STPush(&Stack,1);
    STPush(&Stack,2);
    STPush(&Stack,3);
    STPush(&Stack,4);
    STPush(&Stack,5);
    STPrint(&Stack);
    STPop(&Stack);
    STPrint(&Stack);
}

int main() {
    test();
    return 0;
}
