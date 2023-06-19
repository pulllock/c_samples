#include "friend.h"

void struct_nested_sample() {
    // 初始化一个结构变量
    struct guy fellow = {
            {"Ewen", "Villa"},
            "Coach",
            23
    };

    printf("first: %s\n", fellow.names.first);
    printf("last: %s\n", fellow.names.last);
    printf("job: %s\n", fellow.job);
    printf("age: %d\n", fellow.age);
    printf("done.\n");
}

void struct_pointer_sample() {
    struct guy fellow[2] = {
            {
                    {"Ewen", "Villa"},
                    "Coach",
                    23
            },
            {
                    {"Rodney", "Swill"},
                    "Editor",
                    30
            }
    };

    // 指向结构的指针
    struct guy *him;

    printf("第一个结构地址：%p\n", &fellow[0]);
    printf("第二个结构地址：%p\n", &fellow[1]);

    // 指向结构数组中的第一个结构
    him = &fellow[0];

    printf("first: %s\n", (*him).names.first);
    printf("last: %s\n", him->names.last);
    printf("job: %s\n", (*him).job);
    printf("age: %d\n", (*him).age);
    printf("done.\n");

    // 指向下一个结构
    him++;
    printf("first: %s\n", (*him).names.first);
    printf("last: %s\n", (*him).names.last);
    printf("job: %s\n", (*him).job);
    printf("age: %d\n", (*him).age);
    printf("done.\n");
}