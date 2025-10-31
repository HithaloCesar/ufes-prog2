#include "string_utils.h"
#include <ctype.h>

int string_length(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

void string_copy(char *src, char *dest) {
    dest[0] = src[0];
    for (int i = 1; src[i - 1] != '\0'; i++) {
        dest[i] = src[i];
    }
}

void string_upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void string_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void string_reverse(char *str) {
    int len = string_length(str);
    for (int i = 0; i < len / 2; i++) {
        char aux = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = aux;
    }
}
