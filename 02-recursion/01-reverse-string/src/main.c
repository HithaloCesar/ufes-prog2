#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_SIZE 1024

static void print_reverse(const char string[]);

int main(void) {
    const char *sep = "";
    while (true) {
        char string[MAX_WORD_SIZE];
        if (scanf("%s", string) != 1) {
            break;
        }

        printf("%s", sep);
        sep = " ";
        print_reverse(string);
    }

    putchar('\n');

    return EXIT_SUCCESS;
}

static void print_reverse(const char string[]) {
    if (*string == '\0') {
        return;
    }

    print_reverse(string + 1);

    putchar(*string);
}
