#include <stdio.h>

/**
 * 默认对齐的结构体
 */
struct default_aligned_struct {
    char a;
    int b;
    short c;
};

/**
 * 整个结构体的对齐
 */
struct aligned_struct {
    char a;
    short b;
    int c;
}__attribute__((aligned((16))));

int main() {
    printf("函数属性：aligned\n");
    /**
     * aligned属性用来显式的指定变量或类型在内存中的地址对齐方式。
     *
     * 结构体的对齐规则：结构体的整体对齐要按照结构体所有成员最大对齐字节数或其整数倍对齐，结构体的整体长度要为其最大成员字节数的整数倍，如果不是整数倍则要补齐
     */

    printf("按照默认对齐方式进行对齐：\n");
    int a = 1;
    int b = 2;
    char c = 3;
    char d = 4;

    printf("int a的地址： %p\n", &a);
    printf("int b的地址： %p\n", &b);
    printf("char c的地址：%p\n", &c);
    printf("char d的地址：%p\n", &d);

    printf("==========\n");

    printf("指定对齐方式进行对齐：\n");
    int e = 1;
    int f = 2;
    char g = 3;
    char h __attribute__((aligned(4))) = 4;

    printf("int e的地址： %p\n", &e);
    printf("int f的地址： %p\n", &f);
    printf("char g的地址：%p\n", &g);
    printf("char h的地址：%p\n", &h);

    printf("==========\n");

    printf("结构体的对齐：\n");

    printf("未对齐的结构体：\n");

    struct default_aligned_struct default_aligned_struct;
    printf("结构体大小：%lu\n", sizeof(default_aligned_struct));
    printf("结构体的a的地址：%p\n", &default_aligned_struct.a);
    printf("结构体的b的地址：%p\n", &default_aligned_struct.b);
    printf("结构体的c的地址：%p\n", &default_aligned_struct.c);

    printf("==========\n");
    printf("整个结构体的对齐：\n");

    struct aligned_struct aligned_struct;
    printf("结构体大小：%lu\n", sizeof(aligned_struct));
    printf("结构体的a的地址：%p\n", &aligned_struct.a);
    printf("结构体的b的地址：%p\n", &aligned_struct.b);
    printf("结构体的c的地址：%p\n", &aligned_struct.c);
    return 0;
}
