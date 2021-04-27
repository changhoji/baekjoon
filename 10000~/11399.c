#include <stdio.h>
#include <stdlib.h>

int compare(const void* num1, const void* num2) {
    int a = *(int *)num1, b = *(int *)num2;
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int time[1001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &time[i]);
    }
    qsort(time, n, sizeof(int), compare);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += time[i] * (n-i);
    }
    printf("%d", sum);
    return 0;
}