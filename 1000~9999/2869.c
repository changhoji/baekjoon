#include <stdio.h>
#include <math.h>

int main() {
    int a, b, v;
    int cnt = 0;
    scanf("%d %d %d", &a, &b, &v);
   
    cnt = (int)ceil((double)v/(double)(a-b));
    int temp = cnt*(a-b);
    while (temp+2*b-a >= v) {
        cnt--;
        temp -= (a-b);
    }
    printf("%d", cnt);
    return 0;
}
