#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

int edge[101][101];
vector<int> path[101][101];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) edge[i][j] = 0;
            else {
                edge[i][j] = INF;
                path[i][j].push_back(i);
                path[i][j].push_back(j);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (edge[a][b] < c) continue;
        edge[a][b] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (edge[i][j] > edge[i][k] + edge[k][j]) {                    
                    edge[i][j] = edge[i][k] + edge[k][j]; //최단거리 갱신
                    if (i == j) continue; //출발, 목적지 같으면 항상 0
                    else if (k == i || k == j) continue; //경유지가 없으면 딱히 할일x
                    else {
                        path[i][j] = path[i][k];
                        path[i][j].pop_back();
                        path[i][j].insert(path[i][j].end(), path[k][j].begin(), path[k][j].end());
                    }
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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || edge[i][j] == INF) printf("0\n");
            else {
                printf("%d ", path[i][j].size());
                for (int v: path[i][j]) {
                    printf("%d ", v);
                }
                printf("\n");
            }
        }
    }

    return 0;
}