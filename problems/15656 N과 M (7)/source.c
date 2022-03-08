#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int compare(const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

int n, m;
int num[7];
int sequence[7];

void Backtracking(int cnt);

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    qsort(num, n, sizeof(int), compare);
    Backtracking(0);
    return 0;
}

void Backtracking(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", sequence[i]);
        }
        putchar('\n');
        return;
    }

    for (int next = 0; next < n; next++) {
        sequence[cnt] = num[next];
        Backtracking(cnt+1);
    }
}