#include <stdio.h>
#include <stdlib.h>

static int fibonacci(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));

    return EXIT_SUCCESS;
}

static int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n <= 2) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
