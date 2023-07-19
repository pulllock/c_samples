#include <stdio.h>

#define MAX_1(x, y) x > y ? x : y
#define MAX_2(x, y) (x) > (y) ? (x) : (y)
#define MAX_3(x, y) ((x) > (y) ? (x) : (y))
#define MAX_4(x, y) ({ \
    int _x = x;        \
    int _y = y;        \
    _x > _y ? _x : _y; \
})
#define MAX_5(type, x, y) ({ \
    type _x = x;        \
    type _y = y;        \
    _x > _y ? _x : _y; \
})
#define MAX_6(x, y) ({ \
    typeof(x) _x = (x);        \
    typeof(y) _y = (y);  \
    (void) (&_x == &_y); \
    _x > _y ? _x : _y; \
})

int main() {
    printf("use macro MAX_1\n");
    printf("max = %d\n", MAX_1(1, 2));
    printf("max = %d\n", MAX_1(2, 1));
    printf("max = %d\n", MAX_1(2, 2));

    // 结果错误，展开后是：1!=1 > 1!=2 ? 1!=1 : 1!=2
    printf("max = %d\n\n", MAX_1(1!=1, 1!=2));

    printf("use macro MAX_2\n");
    printf("max = %d\n", MAX_2(1, 2));
    printf("max = %d\n", MAX_2(2, 1));
    printf("max = %d\n", MAX_2(2, 2));

    // 结果正确，展开后是：(1!=1) > (1!=2) ? (1!=1) : (1!=2)
    printf("max = %d\n", MAX_2(1!=1, 1!=2));

    // 结果错误，展开后是：3 + (1) > (2) ? (1) : (2)
    printf("max = %d\n\n", 3 + MAX_2(1, 2));

    printf("use macro MAX_3\n");
    printf("max = %d\n", MAX_3(1, 2));
    printf("max = %d\n", MAX_3(2, 1));
    printf("max = %d\n", MAX_3(2, 2));

    // 结果正确，展开后是：(1!=1) > (1!=2) ? (1!=1) : (1!=2)
    printf("max = %d\n", MAX_3(1!=1, 1!=2));

    // 结果正确，展开后是：3 + ((1) > (2) ? (1) : (2))
    printf("max = %d\n", 3 + MAX_3(1, 2));

    // 结果错误，展开后是：((3) > (6) ? (4) : (7))
    int i = 2;
    int j = 6;
    printf("max = %d\n\n", MAX_3(i++, j++));

    printf("use macro MAX_4\n");
    printf("max = %d\n", MAX_4(1, 2));
    printf("max = %d\n", MAX_4(2, 1));
    printf("max = %d\n", MAX_4(2, 2));

    // 结果正确，展开后是：(1!=1) > (1!=2) ? (1!=1) : (1!=2)
    printf("max = %d\n", MAX_4(1!=1, 1!=2));

    // 结果正确，展开后是：3 + ((1) > (2) ? (1) : (2))
    printf("max = %d\n", 3 + MAX_4(1, 2));

    // 结果正确，展开后是：((3) > (6) ? (3) : (6))
    i = 2;
    j = 6;
    printf("max = %d\n\n", MAX_4(i++, j++));

    printf("use macro MAX_5\n");
    i = 2;
    j = 6;
    printf("max = %d\n\n", MAX_5(int, i++, j++));

    printf("use macro MAX_6\n");
    i = 2;
    j = 6;
    printf("max = %d\n\n", MAX_6(i++, j++));
    return 0;
}
