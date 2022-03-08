#include <stdio.h>

int prime_number(int x) {
    if (x == 1) return 0;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (prime_number(x) == 1) answer++;
    }
    printf("%d", answer);
    return 0;
}
