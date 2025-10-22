#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 32

static int array_even_sum(const int array[], int array_size);

int main(void) {
    int array_count;
    scanf("%d", &array_count);

    for (int i = 0; i < array_count; i++) {
        int array_size;
        scanf("%d", &array_size);

        int array[MAX_ARRAY_SIZE];
        for (int j = 0; j < array_size; j++) {
            scanf("%d", &array[j]);
        }

        int even_sum = array_even_sum(array, array_size);
        printf("%d\n", even_sum);
    }

    return EXIT_SUCCESS;
}

static int array_even_sum(const int array[], int array_size) {
    if (array_size == 0) {
        return 0;
    }

    int even_sum = (*array % 2 == 0) ? *array : 0;

    return even_sum + array_even_sum(array + 1, array_size - 1);
}
