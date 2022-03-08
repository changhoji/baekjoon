#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

#define TRUE 1
#define FALSE 0

int n, m;

int num[8];
int sequence[8];
int used[8] = { FALSE,};

void Backtracking(int cnt, int now);

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    qsort(num, n, sizeof(int), compare);

    Backtracking(0, -1);
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

    for (int next = now+1; next < n; next++) {
        if (!used[next]) {
            sequence[cnt] = num[next];
            used[next] = TRUE;
            Backtracking(cnt+1, next);
            used[next] = FALSE;
        }
    }
}