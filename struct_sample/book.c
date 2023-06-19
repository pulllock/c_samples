#include "book.h"

void struct_book_sample() {
    // 声明book类型结构
    // 初始化结构
    struct book library = {
            "sample title",
            "sample author",
            12.3
    };

    printf("请输入书名->");
    fgets(library.title, MAX_TITLE_LENGTH, stdin);

    printf("请输入作者->");
    fgets(library.author, MAX_AUTHOR_LENGTH, stdin);

    printf("请输入价格->");
    scanf("%f", &library.price);

    printf("书名：%s", library.title);
    printf("作者：%s", library.author);
    printf("价格：%.2f\n", library.price);

    printf("完成。\n");
}

void struct_initializer_sample() {
    // 声明book类型结构
    // 使用指定初始化器
    struct book library = {
            .price = 12.0,
            .title = "sample title"
    };

    printf("书名：%s\n", library.title);
    printf("作者：%s\n", library.author);
    printf("价格：%.2f\n", library.price);
    printf("完成。\n");
}

void struct_array_sample() {
    // book类型结构数组
    struct book library[MAX_BOOK_NUMBER];

    int i = 0;
    while (i < MAX_BOOK_NUMBER) {
        strcpy(library[i].title, "sample title");
        strcpy(library[i].author, "sample author");
        library[i].price = i;
        i++;
    }

    for (int i = 0; i < MAX_BOOK_NUMBER; i++) {
        printf("书名：%s\n", library[i].title);
        printf("作者：%s\n", library[i].author);
        printf("价格：%.2f\n", library[i].price);
    }
    printf("完成。\n");
}