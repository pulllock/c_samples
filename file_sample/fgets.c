#include <stdio.h>
#include <stdlib.h>
#include "fgets.h"

void fgets_sample() {
    FILE *file_pointer;
    char *file_name = "fgets.conf";

    if ((file_pointer = fopen(file_name, "r")) == NULL) {
        printf("can not open file: %s", file_name);
        exit(1);
    }

    char buf[CONFIG_MAX_LINE + 1];

    while (fgets(buf, CONFIG_MAX_LINE + 1, file_pointer)) {
        printf("%s", buf);
    }

    fclose(file_pointer);
}