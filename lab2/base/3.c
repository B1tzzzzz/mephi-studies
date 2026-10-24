#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool input_n(int *n);
bool input_array(int* arr,  int n);
bool pseudo_sort_array(int *arr, int n);
void print_array(const int *arr, int n);


int main() {
    int n = 0;
    int* arr = NULL;
    if (!input(&n, &arr)) {
        return 1;
    }
    if (!pseudo_sort_array(arr, n)) {
        return 1;
    }
    print_array(arr, n);
    free(arr);
    return 0;
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

void print_array(const int *arr, int n) {
    printf("Pseudosorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool pseudo_sort_array(int *arr, int n){
    int *tmpNegative = (int*)malloc(sizeof(int) * n);
    if (tmpNegative == NULL) {
        printf("Error allocating memory.\n");
        return 0;
    }
    
    int *tmpPositive = (int*)malloc(sizeof(int) * n);
    if (tmpPositive == NULL) {
        printf("Error allocating memory.\n");
        return 0;
    }
    
    int szTmpNegative = 0, szTmpPositive = 0, cntZero = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            tmpPositive[szTmpPositive++] = arr[i];
        }
        else if (arr[i] < 0) {
            tmpNegative[szTmpNegative++] = arr[i];
        }
        else {
            cntZero++;
        }
    }

    for (int i = 0; i < szTmpNegative; i++) {
        arr[i] = tmpNegative[i];
    }

    for (int i = szTmpNegative; i < szTmpNegative + cntZero; i++) {
        arr[i] = 0;
    }

    for (int i = szTmpNegative + cntZero; i < n; i++) {
        arr[i] = tmpPositive[i - szTmpNegative - cntZero];
    }

    free(tmpPositive);
    free(tmpNegative);
    return 1;
}
