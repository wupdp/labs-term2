#include <stdlib.h>
#include <stdio.h>

int main() {
    int t = 0;
    scanf("%d", &t);
    int t1 = t;
    auto *mas = (long long*)calloc(t, sizeof(long long));
    long long a = 0, b = 0, x = 0;
    long long *p = mas;
    while (t--) {
        scanf("%lld %lld %lld", &a, &b, &x);
        long long f_x = x - b + 1;
        while (x <= a) {
            x = f_x + b;
            f_x++;
        }
        *p++ = f_x;
    }
    p = mas;
    while (t1--) {
        printf("%lld\n", *p++);
    }
    free(mas);
    return 0;
}