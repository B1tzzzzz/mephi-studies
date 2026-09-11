#include <stdlib.h>
#include <stdio.h>
#include <math.h>  
#define E 1e-25
void solve() {
    /*double l = 1;
    int precision = 0;
    double r = 0;
    while (l - r > 0.0) {
        r = 1 - pow(10, -precision++);
    }
    precision -= 2;
    
    printf("Computer precision is %d digits after floating point.\n", precision);*/

    double l = E;
    double r = 1;
    while (r - l > E) {
        double mid = l + (r - l) * 0.5;
        if (1.0 - (1.0 - mid) > 0.0) r = mid;
        else l = mid;
    }
    printf("Computer precision is %.25f", r);
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}