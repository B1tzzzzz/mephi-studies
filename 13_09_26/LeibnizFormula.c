#include <stdlib.h>
#include <stdio.h>
#include <math.h>  
#include <stdbool.h>
#define E 2.2e-8
void solve() {
    double sum = 0;
    int i = 0;
    while (true) {
        //printf("eq: %d\n", (1 - (2 * (i & 1))));
        double add = (1 - (2 * (i & 1))) / (double)(2 * i + 1);
        //printf("add: %.7f\n", add);
        if (add * (1 - 2 * (add < 0)) < E) break;
        sum += add;
        i++;
    }
    printf("Сумма ряда Лейбница: %.16f\n", sum); 
    printf("Кол-во итераций: %d", i);
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}