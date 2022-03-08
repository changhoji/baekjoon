#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int a, b;
    for (int tc = 0; tc < t; tc++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", a+b);
    }
    return 0;
}