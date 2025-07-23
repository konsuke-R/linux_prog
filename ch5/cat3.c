#include <stdio.h>
#include <stdlib.h>

static void do_cat(FILE*);

int main(int argc, char *argv[]) {
    int i;

    if (argc == 1) {
        do_cat(stdin);
        exit(0);
    }

    for (int i = 0; i < argc; i++) {
        FILE *file;

        file = fopen(argv[i], "r");
        if (!file) {
            perror(argv[i]);
            exit(1);
        }
        do_cat(file);
        fclose(file);
    }
    exit(0);
}

static void do_cat(FILE *file) {
    int c;

    while ((c = fgetc(file)) != EOF) {
        if (putchar(c) < 0) exit(1);
    }
}