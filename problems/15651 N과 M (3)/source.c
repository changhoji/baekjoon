#include <stdio.h>

int n, m;
int sequence[7];

void Backtracking(int cnt);

int main() {
    scanf("%d %d", &n, &m);
    Backtracking(0);
}

void Backtracking(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", sequence[i]);
        }
        putchar('\n');
        return;
    }

    for (int next = 1; next <= n; next++) {
        sequence[cnt] = next;
        Backtracking(cnt+1);
    }
}