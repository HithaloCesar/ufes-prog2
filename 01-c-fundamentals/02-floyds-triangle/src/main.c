#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int row_count;
    scanf("%d", &row_count);

    int n = 1;
    for (int row = 0; row < row_count; row++) {
        const char *sep = "";
        for (int col = 0; col <= row; col++) {
            printf("%s%d", sep, n++);
            sep = " ";
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}
