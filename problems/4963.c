#include <stdio.h>
#include <string.h>

int n, m;
int map[50][50];
int visited[50][50] = { 0,};

void DFS(int start_row, int start_col);

int x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {   
    scanf("%d %d", &m, &n);
    while (n) {
        memset(map, 0, 2500*sizeof(int));
        memset(visited, 0, 2500*sizeof(int));
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] && !visited[i][j]) {
                    DFS(i, j);
                    answer++;
                }
            }
            //printf("----------\n");
        }
        printf("%d\n", answer);
        scanf("%d %d", &m, &n);
    }
    return 0;
}

void DFS(int start_row, int start_col) {
    visited[start_row][start_col] = 1;
    for (int k = 0; k < 8; k++) {
        int new_row = start_row + y[k];
        int new_col = start_col + x[k];
        if(0 <= new_row && new_row < n && 0 <= new_col && new_col < m)
            if (!visited[new_row][new_col] && map[new_row][new_col]) {
                //printf("Å½»ö : %d %d\n", new_row, new_col);
                DFS(new_row, new_col);
            }
    }
}