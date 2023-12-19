#include <stdio.h>
#include <stdarg.h>

/**
 * 使用vprintf进行打印
 * @param fmt
 * @param ...
 */
void print_use_vprintf(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

/**
 * 使用vprintf进行打印，添加了format属性声明
 * @param fmt
 * @param ...
 */
void __attribute__((format(printf, 1, 2))) print_use_vprintf_format(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

int main() {
    printf("函数属性：format\n");

    /**
     * format属性用来指定变参函数的参数格式检查
     */

    printf("使用vprintf进行打印：\n");
    int number = 10;
    print_use_vprintf("Input number is: %d", number);

    printf("==========\n");

    printf("使用vprintf进行打印，并添加了format属性：\n");
    print_use_vprintf_format("Input number is: %d", number);
    return 0;
}
