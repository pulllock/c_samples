#include <stdio.h>

struct struct_variable_length {
    int length;
    int array[0];
};

int main() {
    printf("零长度数组：\n");
    int array[0];
    printf("零长度数组的长度：%lu\n", sizeof(array));

    // 零长度数组不占用存储空间大小，通常和结构体一起使用，构成一个变长结构体
    struct struct_variable_length s;
    printf("变长结构体的大小：%lu\n", sizeof(s));
    return 0;
}
