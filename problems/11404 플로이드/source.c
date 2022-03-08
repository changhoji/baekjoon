#include <stdio.h>
#define INF 1000000000

long long edge[101][101];

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) edge[i][j] = 0;
            else edge[i][j] = INF; //이부분 -1로 초기화하는것도 생각해보기
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (edge[a][b] > c)
            edge[a][b] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (edge[i][j] > edge[i][k] + edge[k][j]) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (edge[i][j] == INF) printf("0 ");
            else printf("%d ", edge[i][j]);
        }
        printf("\n");
    }
    return 0;
}