#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOK_COUNT 1024

int main(void) {
    int book_count;
    scanf("%d", &book_count);

    int books[MAX_BOOK_COUNT] = {0};
    for (int i = 0; i < book_count; i++) {
        int id;
        scanf("%d", &id);
        books[id]++;
    }

    int requests = 0;
    const char *sep = "";
    for (int id = 0; id < MAX_BOOK_COUNT; id++) {
        if (books[id] == 1) {
            printf("%s%d", sep, id);
            sep = " ";
            requests++;
        }
    }

    if (requests == 0) {
        printf("NENHUM\n");
    } else {
        putchar('\n');
    }

    return EXIT_SUCCESS;
}
