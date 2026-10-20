#include <time.h>
#include "array.h"
void fillArray(float* m, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        m[i] = rand() % 101 / 10.;
    }
}
float sumArray(const float* m, int n) {
    float s = 0;
    for (int i = 0; i < n; i++) {
        s += m[i];
    }
    return s;
}