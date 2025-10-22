#include <stdio.h>
#include <stdlib.h>

static int fatorial(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", fatorial(n));

    return EXIT_SUCCESS;
}

static int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * fatorial(n - 1);
}
