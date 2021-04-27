#include <stdio.h>

int n;
int cnt = 0;
int visited[101] = { 0,};
int node[101][101] = { 0,};

void DFS(int start) {
    for(int i = 1; i <= n; i++) {
        if (!visited[i] && node[start][i]) {
            cnt++;
            visited[i] = 1;
            DFS(i);
        }
    }
}

int main() {
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    visited[1] = 1;
    for (int i = 0; i < m; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        node[from][to] = 1;
        node[to][from] = 1;
    }
    DFS(1);
    printf("%d", cnt);
    return 0;
}