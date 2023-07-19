#ifndef CLASS_SAMPLE_ANIMAL_H
#define CLASS_SAMPLE_ANIMAL_H

#endif //CLASS_SAMPLE_ANIMAL_H

struct func_operations {
    void (*fp1)(void);
    void (*fp2)(void);
    void (*fp3)(void);
    void (*fp4)(void);
};

struct animal {
    int age;
    int weight;
    struct func_operations fp;
};

void speak(void);