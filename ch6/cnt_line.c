#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int cnt_line = 0;

    for (int i = 1; i < argc; i++) {
        FILE *file;
        int c;

        file = fopen(argv[i], "r");
        if (!file) {
            perror(argv[i]);
            exit(1);
        }

        while ((c = fgetc(file)) != EOF) {
            if (c == '\n') {
                cnt_line++;
                continue;
            }
        }

        fclose(file);
    }
    printf("%d\n",cnt_line);
    exit(0);
}