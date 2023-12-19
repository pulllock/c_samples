#include <stdio.h>

/**
 * 使用宏连接符##，当变参列表非空时，用来连接fmt和可变参数列表，各个参数之间用逗号隔开；当变参列表为空时，会将固定参数fmt后面的逗号删除掉
 */
#define LOG_USE_VA_ARGS(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define LOG_USE_ARGS(fmt, args...) printf(fmt, ##args)

int main() {
    printf("可变参数宏：\n");
    int number = 10;
    LOG_USE_VA_ARGS("Input number is %d\n", number);
    LOG_USE_VA_ARGS("Input number is emtpy\n");

    printf("==========\n");

    LOG_USE_ARGS("Input number is %d\n", number);
    LOG_USE_ARGS("Input number is emtpy\n");
    return 0;
}
