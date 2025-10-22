#include <stdio.h>
#include <stdlib.h>

static int digit_sum(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", digit_sum(n));

    return EXIT_SUCCESS;
}

static int digit_sum(int n) {
    if (n % 10 == n) {
        return n;
    }

    int sum = n % 10;

    return sum + digit_sum(n / 10);
}
