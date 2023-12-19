#include <stdio.h>

struct packed_struct {
    char a;
    short b __attribute__((packed));
    int c __attribute__((packed));
};

int main() {
    printf("函数属性：packed\n");
    /**
     * packed用来指定变量或类型使用最可能小的地址对齐方式
     */

    printf("packed的结构体：\n");
    struct packed_struct packed_struct;
    printf("结构体大小：%lu\n", sizeof(packed_struct));
    printf("结构体的a的地址：%p\n", &packed_struct.a);
    printf("结构体的b的地址：%p\n", &packed_struct.b);
    printf("结构体的c的地址：%p\n", &packed_struct.c);
    return 0;
}
