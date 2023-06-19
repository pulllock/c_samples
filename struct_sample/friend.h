#include <stdio.h>
#ifndef STRUCT_SAMPLE_FRIEND_H
#define STRUCT_SAMPLE_FRIEND_H

#endif //STRUCT_SAMPLE_FRIEND_H

#define MAX_NAME_LENGTH 20
#define MAX_JOB_LENGTH 20

struct names {
    char first[MAX_NAME_LENGTH];
    char last[MAX_NAME_LENGTH];
};

struct guy {
    // 嵌套结构
    struct names names;
    char job[MAX_JOB_LENGTH];
    int age;
};

void struct_nested_sample();

void struct_pointer_sample();