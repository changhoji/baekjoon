#include <stdio.h>

int n, m;
int visited[9] = { 0,};

void Backtracking(int cnt, int idx);
void PrintSequence();

int main() {
    scanf("%d %d", &n, &m);

    Backtracking(0, 0);
}

void Backtracking(int cnt, int now) {
    visited[now] = 1;
    if (cnt == m) {
        PrintSequence();
        visited[now] = 0;
        return;
    }

    for (int next = now+1; next <= n; next++) { //오름차순으로 하기 위해서
        Backtracking(cnt+1, next);
        visited[next] = 0;
    }
}

void PrintSequence() {
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            printf("%d ", i);
    }
    putchar('\n');
}