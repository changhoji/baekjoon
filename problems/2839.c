#include <stdio.h>

int main() {
    int n, min = 2000;
    scanf("%d", &n);
    for (int i = 0; i <= n/3; i++) {
        int sum = i;
        int rest = n - i*5;
        while (rest > 0) {
            sum++;
            rest -= 3;
        }
        if (!rest) min = sum; 
    }

    if (min == 2000) printf("-1");
    else printf("%d", min);
    return 0;
}