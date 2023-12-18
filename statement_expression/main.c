#include <stdio.h>

int main() {
    // 语句表达式的值是最后一个表达式的值
    printf("语句表达式的值是最后一个表达式的值：\n");
    int expression_result = ({
            int count = 0;
            for (int i = 0; i < 10; i++) {
                count = count + i;
            }
            count;
    });
    printf("expression result = %d\n", expression_result);
    return 0;
}
