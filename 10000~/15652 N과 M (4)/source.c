#include <stdio.h>

int n, m;
int sequence[8];

void Backtracking(int cnt, int now);

int main() {
    scanf("%d %d", &n, &m);

    Backtracking(0, 1);
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

    for (int next = now; next <= n; next++) {
        sequence[cnt] = next;
        Backtracking(cnt+1, next);
    }
}