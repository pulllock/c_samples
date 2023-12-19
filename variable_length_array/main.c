#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("变长数组\n");
    long int length;

    printf("请输入数组的长度：");
    char input[10];
    char *end_ptr;
    fgets(input, 10, stdin);
    length = strtol(input, &end_ptr, 10);

    // 初始化数组数据
    int array[length];
    for (int i = 0; i < length; i++) {
        array[i] = i + 1;
    }

    // 打印数组长度和数据
    printf("数组的长度为：%lu\n", sizeof(array) / sizeof (array[0]));
    printf("数组的值：\n");
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
