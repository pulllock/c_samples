#include <stdio.h>
#include "packed.h"

int main() {
    packed_struct_sample();

    unpacked_struct_sample();

    packed_struct_student_sample();

    unpacked_struct_student_sample();

    sdshdr64_sample();
    return 0;
}
