#include <stdlib.h>
#include <printf.h>
#include <errno.h>
#include <string.h>
#include "contact.h"

void init(struct contact* contact) {
    contact->user = (struct user*) malloc(DEFAULT_CONTACT_SIZE * sizeof(struct user));
    if (contact->user == NULL) {
        printf("申请空间失败");
        return;
    }

    contact->size = 0;
    contact->capacity = DEFAULT_CONTACT_SIZE;

    // 从文件中加载已有的数据
    load(contact);
}

void check_capacity(struct contact* contact) {
    if (contact->size == contact->capacity) {
        struct user* user = (struct user*) realloc(contact->user, (contact->capacity + 5) * sizeof(struct user));
        if (user != NULL) {
            contact->user = user;
            contact->capacity += 5;
        }
    }
}

void load(struct contact *contact) {
    FILE* contact_file = fopen("contact.txt", "rb");
    if (contact_file == NULL) {
        printf("文件不存在：%s\n", strerror(errno));
        return;
    }

    // 读取文件
    struct user temp = {0};
    while (fread(&temp, sizeof(struct user), 1, contact_file)) {
        // 检查容量，确保容量足够
        check_capacity(contact);
        contact->user[contact->size] = temp;
        contact->size++;
    }
    fclose(contact_file);
    contact_file = NULL;
}

void add(struct contact* contact) {
    check_capacity(contact);

    printf("请输入名字->");
    scanf("%s", contact->user[contact->size].name);

    printf("请输入年龄->");
    scanf("%d", &(contact->user[contact->size].age));

    printf("请输入性别->");
    scanf("%s", contact->user[contact->size].gender);

    printf("请输入电话->");
    scanf("%s", contact->user[contact->size].phone);

    printf("请输入地址->");
    scanf("%s", contact->user[contact->size].address);

    contact->size++;
    printf("添加成功\n");
}

void show(const struct contact* contact) {
    if (contact->size == 0) {
        printf("通讯录为空\n");
        return;
    }

    printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
    for (int i = 0; i < contact->size; i++) {
        struct user user = contact->user[i];
        printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n", user.name, user.age, user.gender, user.phone, user.address);
    }
}

void destroy(struct contact* contact) {
    free(contact->user);
    contact->user = NULL;
}

void save(struct contact* contact) {
    FILE* contact_file = fopen("contact.txt", "wb");
    if (contact_file == NULL) {
        printf("%s\n", strerror(errno));
        return;
    }

    for (int i = 0; i < contact->size; i++) {
        fwrite(&(contact->user[i]), sizeof(struct user), 1, contact_file);
    }

    printf("保存成功\n");
    fclose(contact_file);
    contact_file = NULL;
}