#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define E 1e-12
int Process(FILE* f, bool* res) {
    int key = -1;
    double current, gap, prev;
    bool isArifmeticProgression = 1;

    if (fscanf(f, "%lf", &current) == 1) {
        prev = current;
    }
    else {
        return -1;
    }

    if (fscanf(f, "%lf", &current) == 1) {
        gap = current - prev;
        prev = current;
    }
    else {
        return -1;
    }
    
    while (fscanf(f, "%lf", &current) == 1) {
        if (!isArifmeticProgression) {
            break;
        }
        if (fabs(current - prev - gap) > E) {
            isArifmeticProgression = 0;
        }
        prev = current;
        key = 0;
    }
    *res = isArifmeticProgression;
    return key;
}

int main() {
    bool result; 
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
        if (result) {
            printf("This sequence is an arifmetic progression.\n");
        }
        else {
            printf("This sequence is not an arifmetic progression.\n");
        }
    }

    fclose(f);
    return retcode;
}

