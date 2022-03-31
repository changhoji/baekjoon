#include <stdio.h>

void hanoi(int n, int from, int middle, int to);

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", (1 << n) - 1);
    hanoi(n, 1, 2, 3);
    
    return 0;
}

void hanoi(int n, int from, int middle, int to) {
    if (n == 1) {
        printf("%d %d\n", from, to);
        return;
    }
    hanoi(n-1, from, to, middle);
    printf("%d %d\n", from, to);
    hanoi(n-1, middle, from, to);
}