#include <stdio.h>
#include "array.h"
#include "utils.h"
#include "cmath.h"

int log_2(int a) {
    int res = 0;
    a = (a >> 1);
    while (a) {
        a = (a >> 1);
        res++;
    }
    return res;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool input_n(int *n) {
    printf("Enter the lenght of an array: ");
    if (scanf("%d", n) != 1 || (*n) <= 0) {
        printf("Incorrect input.\n");
        return 0;
    }
    return 1;
}

bool input_array(int* arr,  int n) {
    for (int i = 0; i < n; i++) {
        int current;
        printf("Enter element of an array: ");
        if (scanf("%d", &current) == 1) {
            arr[i] = current;
        }
        else {
            printf("Incorrect input.\n");
            return 0;
        }
    }
    return 1;
}

bool merge(int* arr, int l, int mid, int r) {
    int* tmpArr = (int*)malloc((r - l + 1) * sizeof(int));
    if (tmpArr == NULL) {
        printf("Error allocating memory.\n");
        return 0;
    }

    int i = l, j = mid, k = 0;
    while (i < mid && j < r) {
        if (arr[i] <= arr[j]) {
            tmpArr[k++] = arr[i++];
        }
        else {
            tmpArr[k++] = arr[j++];
        }
    }

    while (i < mid) {
        tmpArr[k++] = arr[i++];
    }

    while (j < r) {
        tmpArr[k++] = arr[j++];
    }

    for (int i = l; i < r; i++) {
        arr[i] = tmpArr[i - l];
    }
    free(tmpArr);
    return 1;
}

bool merge_sort(int *arr, int n) {
    int tmpSize = (1 << (log_2(n - 1) + 1));
    int max = arr[0];
    int *tmpArr = (int*)malloc(tmpSize * sizeof(int));
    if (tmpArr == NULL) {
        printf("Error allocating memory.\n");
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        tmpArr[i] = arr[i];
        max = (arr[i] > max) ? arr[i] : max;
    }
    for (int i = n; i < tmpSize; i++) {
        tmpArr[i] = max;
    }

    for (int l = 2; l <= tmpSize; l *= 2) {
        for (int i = 0; i < tmpSize; i += l) {
            if (!merge(tmpArr, i, (i * 2 + l) / 2, i + l)){
                free(tmpArr);
                return 0;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = tmpArr[i];
    }

    free(tmpArr);
    return 1;
}

void print_array(const int *arr, int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}