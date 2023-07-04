#include <stdio.h>
#include <string.h>

extern char **environ;

int main(int argc, char **argv) {
    printf("from argv: \n");
    for (int i = 0; i < argc; i++) {
        printf("%p: %s\n", &argv[i], argv[i]);
    }

    printf("from environ: \n");
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%p: %s\n", &environ[i], environ[i]);
    }

    char *base, *end, *nul, *tmp;
    base = argv[0];
    printf("argv[0]起始地址赋值给base：%p\n", &base);
    printf("argv[0]的长度：%lu\n", strlen(base));

    nul = &base[strlen(base)];
    printf("argv[0]的结束地址赋值给nul：%p\n", nul);
    return 0;
}
