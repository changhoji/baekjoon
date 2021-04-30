#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    while (n > 0) {
        if (cnt == 0) n--;
        else n -= cnt*6;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}
