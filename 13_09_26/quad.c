#include <stdlib.h>
#include <stdio.h>
#include <math.h>  
#include <stdbool.h>
#define E 1e-12

int sign(int x) {
    return 1 - 2 * (x < 0);
}

int signD(double x) {
    return 1 - 2 * (x < 0);
}
void solve() {
    double a, b, c;
    printf("Введите коэффициенты квадратного уравнения:");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Неверный ввод!");
        return;
    }

    int p = fabs(c / a) * signD(c / a), s = fabs(-b / a) * signD(-b / a);
    //printf("p: %d, s: %d\n", p, s);
    for (int i = 1; i * i <= abs(p); i++ ){
        if (abs(p) % i == 0) {
            int sign1 = 1, sign2 = sign(p);
            for (int j = 0; j < 2; j++) {
                if (i * sign1 + (p / i) * sign2 == s) {
                    if (i == p / i) {
                        printf("Найден один корень уравнения: %d", i * sign1);
                    }
                    else {
                        printf("Найдено два корня уравнения:\n1-ый корень: %d\n2-ой корень: %d", i * sign1, p / i * sign2);
                    }
                    return;
                }
                sign1 *= -1;
                sign2 *= -1;
            }
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