#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

void menu() {
    printf("****** 欢迎使用通讯录管理系统 ******\n");
    printf("主菜单\n");
    printf("===================================\n");
    printf("[1] 添加联系人\n");
    printf("[2] 删除联系人\n");
    printf("[3] 查找联系人\n");
    printf("[4] 修改联系人\n");
    printf("[5] 展示所有联系人\n");
    printf("[6] 按姓名排序联系人\n");
    printf("[7] 保存通讯录\n");
    printf("[8] 清空通讯录\n");
    printf("[0] 退出\n");
    printf("===================================\n");
}

int user_chose;

int main() {
    // 通讯录
    struct contact contact;

    // 初始化通讯录
    init(&contact);

    // 打印菜单
    menu();

    do {
        printf("请输入选择->");
        scanf("%d", &user_chose);
        switch (user_chose) {
            case ADD:
                add(&contact);
                break;
            case SHOW:
                show(&contact);
                break;
            case SAVE:
                save(&contact);
                break;
            case EXIT:
                // 保存通讯录
                // 释放动态申请的内存
                destroy(&contact);
                break;
            default:
                printf("无效的选项\n");
                break;
        }
    } while (user_chose);
    return 0;
}
