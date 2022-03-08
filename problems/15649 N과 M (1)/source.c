#include <stdio.h>
#define TRUE 1
#define FALSE 0

int n, m;
int sequence[8]; //출력에 이용할 배열
int visited[9] = { FALSE,};

void dfs(int cnt);

int main() {
    scanf("%d %d", &n, &m);

    dfs(0);
    return 0;
}

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", sequence[i]);
        }
        putchar('\n');
        return;
    }

    for (int next = 1; next <= n; next++) {
        if (!visited[next]) {
            visited[next] = TRUE;
            sequence[cnt] = next;
            dfs(cnt+1);
            visited[next] = FALSE;
        }
    }
}