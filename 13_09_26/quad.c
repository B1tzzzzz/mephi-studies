#include <stdlib.h>
#include <stdio.h>
#include <math.h>  
#include <stdbool.h>
#define E 1e-12
#define MAX_FACTOR (int)1e4

int sign(int x) {
    return 1 - 2 * (x < 0);
}

int sign(double x) {
    return 1 - 2 * (x < 0);
}
void solve() {
    double a, b, c;
    printf("Введите коэффициенты квадратного уравнения:");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Неверный ввод!");
        return;
    }

    int p = fabs(c / a) * sign(c / a), s = fabs(-b / a) * sign(-b / a);
    //printf("p: %d, s: %d\n", p, s);
    int factor[MAX_FACTOR] = {0};
    int factorSize = 0;
    for (int i = 1; i * i <= abs(p); i++ ){
        if (abs(p) % i == 0) {
            factor[factorSize++] = i;
        }
    }

    for (int i = 0; i < factorSize; i++) {
        int sign1 = 1, sign2 = sign(p);
        for (int j = 0; j < 2; j++) {
            if (factor[i] * sign1 + (p / factor[i]) * sign2 == s) {
                if (factor[i] == p / factor[i]) {
                    printf("Найден один корень уравнения: %d", factor[i] * sign1);
                }
                else {
                    printf("Найдено два корня уравнения:\n1-ый корень: %d\n2-ой корень: %d", factor[i] * sign1, p / factor[i] * sign2);
                }
                return;
            }
            sign1 *= -1;
            sign2 *= -1;
        }
    }

    printf("Решений уравнения нет.");
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}