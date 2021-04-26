#include <stdio.h>

int main() {
    int t, h, w, n;
    scanf("%d", &t);
    
    for (int test_case = 0; test_case < t; test_case++) {
        scanf("%d %d %d", &h, &w, &n);
        int col = 1;
        while (n > h) {
            n -= h;
            col++;
        }
        printf("%d\n", 100*n+col);
    }
    return 0;
}