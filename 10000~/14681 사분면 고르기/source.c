#include <stdio.h>
int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > 0) {
        if (y > 0) putchar('1');
        else putchar('4');
    }
    else {
        if (y > 0) putchar('2');
        else putchar('3');
    }
    return 0;
}