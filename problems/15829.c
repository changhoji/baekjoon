#include <stdio.h>

int main() {
    int l;
    int M = 1234567891;
    char str[50];
    scanf("%d", &l);
    scanf("%s", str);
    int value[50];
    long long sum = 0;
    long long r = 1;
    for (int i = 0; i < l; i++) {
        value[i] = (int)str[i] - 96;
        sum = (sum + value[i]*r)%M;
        r *= 31;
    }

    printf("%d", sum);

    return 0;
}