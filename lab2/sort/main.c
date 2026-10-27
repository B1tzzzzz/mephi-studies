#include <stdio.h>
#include "array.h"
#include "utils.h"
#include "cmath.h"

int main() {
    int n = 0;
    if (!input_n(&n)) {
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    if (!input_array(arr,  n)) {
        free(arr);
        return 1;
    }

    if (!merge_sort(arr, n)) {
        free(arr);
        return 1;
    }

    print_array(arr, n);
    free(arr);
    return 0;
}