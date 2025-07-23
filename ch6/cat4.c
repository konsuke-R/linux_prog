#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        FILE *file;
        int c;

        file = fopen(argv[i], "r");
        if (!file) {
            perror(argv[i]);
            exit(1);
        }
        while ((c = fgetc(file)) != EOF) {
            if (c == '\t') {
                printf("\\t");
                continue;
            } else if (c == '\n') {
                printf("\\n");
                continue;
            }
            if (putchar(c) < 0) exit(1);
        }

        fclose(file);
    }

    exit(0);
}