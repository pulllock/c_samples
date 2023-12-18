#include <stdio.h>
#include "student.h"

int main() {
    // 指定初始化结构体成员
    printf("指定初始化结构体成员：\n");
    struct student student_1 = {
            .name = "Test Name",
            .age = 23
    };
    printf("struct student_1: \n");
    printf("\tname = %s\n", student_1.name);
    printf("\tage = %d\n", student_1.age);
    return 0;
}
