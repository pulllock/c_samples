#include <stdio.h>
#include <stdarg.h>

/**
 * 变参函数1
 * @param count 参数个数
 * @param ... 参数
 */
void variadic_function_1(int count, ...) {
    // int类型指针变量保存参数的地址
    int *args;
    // count参数的地址+1是下一个参数的地址
    args = &count + 1;
    for (int i = 0; i < count; i++) {
        // 打印当前参数的值
        printf("参数%d：%d\n", i, *args);
        // 下一个参数的地址
        args++;
    }
}

/**
 * 变参函数2
 * @param count 参数个数
 * @param ... 参数
 */
void variadic_function_2(int count, ...) {
    // char类型指针变量保存参数的地址
    char *args;
    // count参数的地址+4是下一个参数的地址
    args = (char *) &count + 4;
    for (int i = 0; i < count; i++) {
        // 打印当前参数的值
        printf("参数%d：%d\n", i, *(int *) args);
        // 下一个参数的地址
        args += 4;
    }
}

/**
 * 使用stdarg进行解析的变参函数
 * @param count
 * @param ... 参数
 */
void variadic_function_use_stdarg(int count, ...) {
    // va_list指向参数地址的指针
    va_list args;
    // va_start以固定参数的地址为起点确定变参的内存起始地址，获取第一个参数的首地址
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        // va_arg获取下一个参数的地址，根据传入参数类型决定返回值类型
        printf("参数%d：%d\n", i, va_arg(args, int));
    }
    // va_end将参数地址指针置为0
    va_end(args);
}

int main() {
    printf("变参函数：\n");
    printf("变参函数1：\n");
    variadic_function_1(5, 10, 9, 8, 7, 6);

    printf("==========\n");

    printf("变参函数2：\n");
    variadic_function_2(5, 10, 9, 8, 7, 6);

    printf("==========\n");

    printf("使用stdarg进行解析的变参函数：\n");
    variadic_function_use_stdarg(5, 10, 9, 8, 7, 6);

    printf("==========\n");
    return 0;
}
