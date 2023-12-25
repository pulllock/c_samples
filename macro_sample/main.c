#include <stdio.h>

// 类对象宏
#define ONE 1

// 类函数宏
#define SQUARE(X) ((X) * (X))

// #运算符
#define SQUARE_AND_PRINT(X) printf("求" #X "的平方，结果是：%d\n", ((X) * (X)));

// ##运算符
#define INT_VARIABLE_N(N) int a##N = N

int main() {
    printf("宏：\n");
    /**
     * 格式：#define 宏 替换体
     * 分类：类对象宏（object-like macro）、类函数宏（function-like macro）
     */
    printf("类对象宏：\n");
    printf("宏ONE的值为：%d\n", ONE);
    printf("使用宏ONE进行计算：%d\n", ONE + ONE);

    printf("==========\n");

    printf("类函数宏：\n");
    printf("使用类函数宏SQUARE计算2的平方：%d\n", SQUARE(2));

    printf("==========\n");

    printf("使用#运算符进行替换：\n");
    SQUARE_AND_PRINT(2);

    printf("==========\n");

    printf("使用##运算符进行替换：\n");
    INT_VARIABLE_N(1);
    INT_VARIABLE_N(2);
    int a3 = a1 + a2;
    printf("计算结果：%d\n", a3);
    return 0;
}
