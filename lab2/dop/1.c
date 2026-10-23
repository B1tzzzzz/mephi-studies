#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool input(int *n, int *k, int **arr);
void swap(int *a, int *b);
int partition(int *arr, int l, int r, int pivot);
int quick_select(int *arr, int l, int r, int k);

int main() {
    int n = 0, k = 0;
    int* arr = NULL;
    if (!input(&n, &k, &arr)) {
        return 1;
    }
    printf("The element on position %d is: %d.\n", k, quick_select(arr, 0, n, k - 1));
    free(arr);
    return 0;
}

bool input(int *n, int *k, int **arr) {
    printf("Enter the lenght of an array: ");
    if (scanf("%d", n) != 1 || (*n) <= 0) {
        printf("Incorrect input.\n");
        return 0;
    }
    
    printf("Enter the position of an element in sorted array that you want to find: ");
    if (scanf("%d", k) != 1 || (*k) > (*n) || (*k) < 1 || (*n) <= 0) {
        printf("Incorrect input.\n");
        return 0;
    }

    *arr = (int*)malloc((*n) * sizeof(int));
    if (arr == NULL) {
        printf("Error allocating memory.\n");
        return 0;
    }
    for (int i = 0; i < (*n); i++) {
        int current;
        printf("Enter element of an array: ");
        if (scanf("%d", &current) == 1) {
            (*arr)[i] = current;
        }
        else {
            printf("Incorrect input.\n");
            free(arr);
            return 0;
        }
    }
    return 1;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int l, int r, int pivot) {
    int j = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < arr[pivot]) {
            swap(&arr[j++], &arr[i]);
        }
    }
    swap(&arr[pivot], &arr[j]);
    return j;
}

int quick_select(int *arr, int l, int r, int k) {
    int pivot = r - 1;
    int split = partition(arr, l, r, pivot);
    if (split == k) return arr[split];
    else if (split < k) return quick_select(arr, split + 1, r, k);
    return quick_select(arr, l, split, k);
}