#include <stdio.h>
#include "packed.h"

void packed_struct_sample() {
    struct packed_struct packed_struct;
    printf("sizeof(unsigned char): %d\n", sizeof(unsigned char));
    printf("sizeof(unsigned short): %d\n", sizeof(unsigned short));
    printf("packed struct: %d\n", sizeof(packed_struct));
}

void unpacked_struct_sample() {
    struct unpacked_struct unpacked_struct;
    printf("sizeof(unsigned char): %d\n", sizeof(unsigned char));
    printf("sizeof(unsigned short): %d\n", sizeof(unsigned short));
    printf("unpacked struct: %d\n", sizeof(unpacked_struct));
}

void unpacked_struct_student_sample() {
    struct unpacked_struct_student unpacked_struct_student;
    printf("sizeof(char): %d\n", sizeof(char));
    printf("sizeof(int): %d\n", sizeof(int));
    printf("unpacked struct student: %d\n", sizeof(unpacked_struct_student));
}

void packed_struct_student_sample() {
    struct packed_struct_student packed_struct_student;
    printf("sizeof(char): %d\n", sizeof(char));
    printf("sizeof(int): %d\n", sizeof(int));
    printf("packed struct student: %d\n", sizeof(packed_struct_student));
}

void sdshdr64_sample() {
    struct sdshdr64 sdshdr64;
    printf("sdshdr64: %d\n", sizeof(sdshdr64));
}