#include <stdio.h>
#include "fgets.h"

int main() {
    printf("File: \n");

    printf("fgetc: \n");

    char *fgetc_file_name = "fgetc.conf";
    printf("打开文本文件：%s\n", fgetc_file_name);
    printf("使用fgetc对文件%s内容进行读取：\n", fgetc_file_name);

    // 打开文件
    FILE *fgetc_file = fopen(fgetc_file_name, "r");
    char ch;
    if (fgetc_file != NULL) {
        // fgetc读取数据
        while ((ch = fgetc(fgetc_file)) != EOF) {
            printf("%c", ch);
        }
        printf("\n");
        // 关闭文件
        fclose(fgetc_file);
    }

    printf("==========\n");

    printf("fgets：\n");
    char fgets_file_name[] = "fgets.conf";
    printf("打开文本文件：%s\n", fgets_file_name);
    printf("使用fgets对文本文件%s内容进行读取：\n", fgets_file_name);
    fgets_sample();
    printf("\n");

    printf("==========\n");
    return 0;
}
