#include <stdio.h>
#include "cat.h"

int main() {
    struct animal ani;
    ani.age = 1;
    ani.weight = 2;
    ani.fp.fp1 = speak;
    printf("%d %d \n", ani.age, ani.weight);
    ani.fp.fp1();

    struct cat c;
    c.p = &ani;
    c.p->fp.fp1();
    printf("%d %d \n", c.p->age, c.p->weight);
    return 0;
}
