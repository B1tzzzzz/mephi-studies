#include <stdio.h>
#include "array.h"

int main() {
    int n;
    float *m;
    printf("Input array size: ");
    scanf("%d", &n);
    if (!(m = (float*)malloc(n * sizeof(float)))) {
        printf("Bad memory allocation\n");
        return 1;
    }
    fillArray(m, n);
    printf("Sum of array elements = %f\n", sumArray(m, n));
    free(m);
    return 0;
}