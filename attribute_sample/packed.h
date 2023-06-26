#include <stdint.h>

#ifndef ATTRIBUTE_SAMPLE_PACKED_H
#define ATTRIBUTE_SAMPLE_PACKED_H

#endif //ATTRIBUTE_SAMPLE_PACKED_H

struct __attribute__ ((__packed__)) packed_struct {
    unsigned char uc1;
    unsigned char uc2;
    unsigned char uc3;
    unsigned short us1;
};

struct unpacked_struct {
    unsigned char uc1;
    unsigned char uc2;
    unsigned char uc3;
    unsigned short us1;
};

struct __attribute__ ((__packed__)) packed_struct_student {
    char sex;
    int age;
    char name[10];
};

struct unpacked_struct_student {
    char sex;
    int age;
    char name[10];
};

struct __attribute__ ((__packed__)) sdshdr64 {
    // 字符串的实际长度，不包含最后的空字符，8个字节
    uint64_t len; /* used */
    // 字符串最大长度，也就是buf分配的总长度，不包含header大小和最后的空字符，8个字节
    uint64_t alloc; /* excluding the header and null terminator */
    // header的类型标志，低3位表示存储类型，高5位未使用，1个字节
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    // 实际存储字符串的字节数组
    char buf[];
};

void packed_struct_sample();

void unpacked_struct_sample();

void unpacked_struct_student_sample();

void packed_struct_student_sample();

void sdshdr64_sample();