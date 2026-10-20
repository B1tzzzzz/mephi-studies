#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define E 1e-12
int Process(FILE* f, int* res, int* n) {
    int key = -1, cnt, localN, cntConstantSegmentsMoreN = 0, lenght = 1;
    double current, prev;
    if (fscanf(f, "%lf", &current) == 1) {
        localN = current;
    }
    else {
        return -1;
    }

    if (fscanf(f, "%lf", &current) == 1) {
        prev = current;
        key = 0;
    }
    else {
        return -1;
    }

    while (fscanf(f, "%lf", &current) == 1) {
        if (fabs(current - prev) < E) {
            lenght++;
        }
        else {
            if (lenght >= localN) {
                cntConstantSegmentsMoreN++;
            }
            lenght = 1;
        }
        prev = current;
        key = 0;
    }

    if (lenght >= localN) {
        cntConstantSegmentsMoreN++;
    }

    *res = cntConstantSegmentsMoreN;
    *n = localN; 
    return key;
}

int main() {
    int result; 
    int retcode;
    int n;
    FILE* f;
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Error opening the file.\n");
        return -1;
    }

    retcode = Process(f, &result, &n);
    if (retcode < 0) {
        printf("File is Empty.\n");
    } 
    else {
        printf("There are %d constant segments in this sequence with length more than %d", result, n - 1);
    }

    fclose(f);
    return retcode;
}

