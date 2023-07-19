#include "animal.h"

#ifndef CLASS_SAMPLE_CAT_H
#define CLASS_SAMPLE_CAT_H

#endif //CLASS_SAMPLE_CAT_H

struct cat {
    struct animal *p;
    struct animal ani;
    char sex;
    void (*eat)(void);
};
