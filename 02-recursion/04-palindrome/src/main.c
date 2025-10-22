#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 64

static int is_palindrome(const char string[], int len);

int main(void) {
    char string[MAX_WORD_SIZE];
    while (scanf(" %s", string) != EOF) {
        if (is_palindrome(string, (int)strlen(string))) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return EXIT_SUCCESS;
}

static int is_palindrome(const char string[], int len) {
    if (len <= 1) {
        return 1;
    }

    if (string[0] != string[len - 1]) {
        return 0;
    }

    return is_palindrome(string + 1, len - 2);
}
