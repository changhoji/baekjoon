#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int compare(const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

int n, m;
int num[8];
int sequence[8];

void Backtracking(int cnt, int now);

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    qsort(num, n, sizeof(int), compare);
    Backtracking(0, 0);
    return 0;
}

void Backtracking(int cnt, int now) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", sequence[i]);
        }
        putchar('\n');
        return;
    }

    for (int next = now; next < n; next++) {
        sequence[cnt] = num[next];
        Backtracking(cnt+1, next);
    }
}