// 防止user.h被重复引用
#ifndef STRUCT_SAMPLE_USER_H
#define STRUCT_SAMPLE_USER_H

/**
 * 用户结构体
 */
struct user {
    // 年龄
    int age;
    // 分数
    double scores[];
};

#endif //STRUCT_SAMPLE_USER_H