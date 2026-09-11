#include <stdlib.h>
#include <stdio.h>
#include <math.h>  
void solve() {
    int eps = 1;
    while (1.0 / (1ll << eps) + 1.0 != 1.0)
    {
        eps++;
    }
    printf("Computer precision is %.25f", 1.0 / (1ll << (eps - 1)));
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}