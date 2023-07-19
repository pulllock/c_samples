#include <stdio.h>
#include "packed.h"

void packed_struct_sample() {
    struct packed_struct packed_struct;
    printf("sizeof(unsigned char): %lu\n", sizeof(unsigned char));
    printf("sizeof(unsigned short): %lu\n", sizeof(unsigned short));
    printf("packed struct: %lu\n", sizeof(packed_struct));
}

void unpacked_struct_sample() {
    struct unpacked_struct unpacked_struct;
    printf("sizeof(unsigned char): %lu\n", sizeof(unsigned char));
    printf("sizeof(unsigned short): %lu\n", sizeof(unsigned short));
    printf("unpacked struct: %lu\n", sizeof(unpacked_struct));
}

void unpacked_struct_student_sample() {
    struct unpacked_struct_student unpacked_struct_student;
    printf("sizeof(char): %lu\n", sizeof(char));
    printf("sizeof(int): %lu\n", sizeof(int));
    printf("unpacked struct student: %lu\n", sizeof(unpacked_struct_student));
}

void packed_struct_student_sample() {
    struct packed_struct_student packed_struct_student;
    printf("sizeof(char): %lu\n", sizeof(char));
    printf("sizeof(int): %lu\n", sizeof(int));
    printf("packed struct student: %lu\n", sizeof(packed_struct_student));
}

void sdshdr64_sample() {
    struct sdshdr64 sdshdr64;
    printf("sdshdr64: %lu\n", sizeof(sdshdr64));
}