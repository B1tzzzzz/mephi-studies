#include <stdio.h>
#include <math.h>
#define E 1e-12
int main() {
    double current, prev;
    printf("Enter the element of the sequence: ");
    if (scanf("%lf", &current)) {
        prev = current;
    }
    else {
        printf("Empty sequence.");
        return 0;
    }

    int uniqueCnt = 1;
    while (1) { 
        printf("Enter the element of the sequence: ");
        if (scanf("%lf", &current)) {
            if (current - prev > E) {
                uniqueCnt++;
            }
            prev = current;
        }
        else {
            break;
        }
    }

    printf("The number of unique elements is %d.", uniqueCnt);
}