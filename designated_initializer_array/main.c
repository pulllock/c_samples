#include <stdio.h>

int main() {
    // 通过数组元素索引给指定的元素赋值
    printf("通过数组元素索引给指定的元素赋值：\n");
    int array_1[10] = {[5] = 1, [8] = 10};
    for (int i = 0; i < sizeof(array_1) / sizeof (array_1[0]); i++) {
        printf("array_1[%d] = %d\n", i, array_1[i]);
    }

    printf("==========\n");

    // 给数组中某一个索引范围的元素初始化
    printf("给数组中某一个索引范围的元素初始化\n");
    int array_2[10] = {[1 ... 3] = 1, [7 ... 9] = 5};
    for (int i = 0; i < sizeof(array_2) / sizeof (array_2[0]); i++) {
        printf("array_2[%d] = %d\n", i, array_2[i]);
    }
    return 0;
}
