#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ASCII_RANGE 128

int main(void) {
    int n;
    scanf("%d\n", &n);

    int label[ASCII_RANGE] = {0};
    while (true) {
        int c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }

        label[c]++;
    }

    bool any_deal = false;
    for (int i = 0; i < ASCII_RANGE; i++) {
        if (label[i] > n) {
            printf("%c: %d\n", i, label[i]);
            any_deal = true;
        }
    }

    if (!any_deal) {
        printf("NENHUM\n");
    }

    return EXIT_SUCCESS;
}
