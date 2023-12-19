#include <stdio.h>

/**
 * f的返回值类型为int
 * @return
 */
int f(){
    return 0;
}

int main() {
    printf("typeof: \n");

    // i的类型为int
    int i = 0;
    printf("变量i的类型：int，值：%d\n", i);

    // j的类型为int
    typeof(i) j = 20;
    printf("变量j的类型为typeof(i)：int，值：%d\n", j);

    // a的类型为 int*
    typeof(int*) a = &j;
    printf("变量a的类型为typeof(int*)：int*，值：%d\n", *a);

    // k的类型为int，因为f函数的返回值是int类型
    typeof(f()) k = 0;
    printf("变量k的类型为typeof(f())：int，值：%d\n", k);

    typeof(int) *y = &k;
    printf("变量y的类型为typeof(int) *：int*，值%d\n", *y);
    return 0;
}


