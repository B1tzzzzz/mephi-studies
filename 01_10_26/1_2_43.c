#include <stdio.h>
#include <math.h>
#define E 1e-12
int main() {
    int n;
    double current, prev;
    printf("Enter the minimal lenght of the constant segment: ");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input.");
        return 0;
    }
    printf("Enter the element of the sequence: ");
    if (scanf("%lf", &current)) {
        prev = current;
    }
    else {
        printf("Empty sequence.");
        return 0;
    }

    int curLen = 1, ans = 0;
    while (1) { 
        printf("Enter the element of the sequence: ");
        if (scanf("%lf", &current)) {
            if (current - prev > E) {
                if (curLen >= n) {
                    ans++;
                }
                curLen = 1;
            }
            else {
                curLen++;
            }
            prev = current;
        }
        else {
            break;
        }
    }

    if (curLen >= n) {
        ans++;
    }
    printf("The number of constant segments with lenght more or equal than %d is %d.", n, ans);
}