#include <stdio.h>

/* 使用语句表达式的宏 */
#define MAX_WITH_TYPE(type, x, y) ({ \
    type _x = x;                     \
    type _y = y;                     \
    _x > _y ? _x : _y;               \
})

/* 使用语句表达式的宏 */
#define MAX(x, y) ({ \
    /* 使用typeof获取数据类型 */  \
    typeof(x) _x = (x);  \
    typeof(y) _y = (y); \
    /* 对于不同类型指针的比较会有一个警告；加上void后可以让有些编译器消除警告 */                 \
    (void) (&_x == &_y); \
    _x > _y ? _x : _y; \
})

int main() {
    printf("statement expression macro: \n");
    printf("MAX WITH TYPE: \n");

    int i = 1;
    int j = 2;
    printf("max = %d\n", MAX_WITH_TYPE(int, i++, j++));

    printf("==========\n");
    printf("MAX: \n");
    int a = 1;
    int b = 2;
    printf("max = %d\n", MAX(a++, b++));
    return 0;
}
