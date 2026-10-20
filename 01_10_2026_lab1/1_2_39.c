#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define E 1e-12
int Process(FILE* f, int* res) {
    int key = -1, n, cntUnique = 1;
    double current, prev;

    if (fscanf(f, "%lf", &current) == 1) {
        prev = current;
        key = 0;
    }
    else {
        return -1;
    }

    while (fscanf(f, "%lf", &current) == 1) {
        if (current - prev > E) {
            cntUnique++;
        }
        prev = current;
        key = 0;
    }
    
    *res = cntUnique;
    return key;
}

int main() {
    int result; 
    int retcode;
    FILE* f;
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Error opening the file.\n");
        return -1;
    }

    retcode = Process(f, &result);
    if (retcode < 0) {
        printf("File is Empty.\n");
    } 
    else {
        printf("There are %d unique numbers in this sequence.", result);
    }

    fclose(f);
    return retcode;
}

