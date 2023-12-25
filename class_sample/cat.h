// 防止cat.h被重复引用
#ifndef CLASS_SAMPLE_CAT_H
#define CLASS_SAMPLE_CAT_H

#include "animal.h"

struct cat {
    struct animal *p;
    struct animal ani;
    char sex;
    void (*eat)(void);
};

#endif //CLASS_SAMPLE_CAT_H
