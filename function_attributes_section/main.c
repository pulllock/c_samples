#include <stdio.h>

// 通过section属性将未初始化的全局变量放到数据段.data中
#ifdef __linux__
    int un_init_value __attribute__((section(".data")))
#elif __APPLE__
    int un_init_value __attribute__((section("__DATA,__data")));
#endif


int main() {
    printf("函数属性：section\n");
    /**
     * section属性主要作用：在程序编译时，将一个函数或变量放到指定的段（section）中。
     *
     * 一个可执行文件主要由：代码段、数据段、BSS段构成。
     *
     * - 代码段主要存放编译生成的可执行指令代码。
     * - 数据段用来存放初始化的全局变量、初始化的静态局部变量。
     * - BSS段用来存放未初始化的全局变量、未初始化的静态局部变量。
     *
     * 可以使用readelf命令来查看一个可执行文件中各个section的信息：`readelf -S a.out`
     */
    printf("un_init_value: %d\n", un_init_value);
    return 0;
}
