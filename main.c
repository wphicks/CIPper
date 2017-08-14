#include <stdio.h>
#include "factorial.h"

int main() {
    int i;
    for (i = 0; i < 10; ++i) {
        printf("The factorial of %d is %d\n", i, factorial(i));
    }
}

