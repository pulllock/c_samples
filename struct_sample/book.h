// 防止book.h被重复引用
#ifndef STRUCT_SAMPLE_BOOK_H
#define STRUCT_SAMPLE_BOOK_H

#include <stdio.h>
#include <string.h>

// 书名最大长度+1
#define MAX_TITLE_LENGTH 41
// 作者姓名最大长度+1
#define MAX_AUTHOR_LENGTH 31

// 最大的书籍数量
#define MAX_BOOK_NUMBER 100

/**
 * 定义book结构体
 */
struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
};

void struct_book_sample();

/**
 * 结构的初始化器
 */
void struct_initializer_sample();

/**
 * 结构数组
 */
void struct_array_sample();

#endif //STRUCT_SAMPLE_BOOK_H