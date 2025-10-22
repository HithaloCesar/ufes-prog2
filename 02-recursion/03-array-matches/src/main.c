#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 32

static int array_count_matches(const int array[], int size, int searched_n);

int main(void) {
    int array_count;
    scanf("%d", &array_count);

    for (int i = 0; i < array_count; i++) {
        int searched_n, array_size;
        scanf("%d %d", &searched_n, &array_size);

        int array[MAX_ARRAY_SIZE];
        for (int j = 0; j < array_size; j++) {
            scanf("%d", &array[j]);
        }

        printf("%d\n", array_count_matches(array, array_size, searched_n));
    }

    return EXIT_SUCCESS;
}

static int array_count_matches(const int array[], int size, int searched_n) {
    if (size == 0) {
        return 0;
    }

    int match_count = (*array == searched_n);

    return match_count + array_count_matches(array + 1, size - 1, searched_n);
}
