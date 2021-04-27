#include <stdio.h> //memset error? (in baekjoon)
#include <string.h> //-> wrong use..

int n, m;

int baechu[50][50];
int visited[50][50];
int answer = 0;

//up, right, down, left
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

void DFS(int row, int col);

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 0; test_case < t; test_case++) {
        int k;
        scanf("%d %d %d", &m, &n, &k);

        //reset
        int answer = 0;
        memset(baechu, 0, sizeof(int)*2500); //<- memset(baechu, 0, 2500);
        memset(visited, 0, sizeof(int)*2500); //<- memset(visited, 0, 2500);

        /*for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                baechu[i][j] = 0;
                visited[i][j] = 0;
            }
        }*/

        for (int i = 0; i < k; i++) {
            int row, col;
            scanf("%d %d", &col, &row);
            baechu[row][col] = 1;
        } //test_case input

        /*printf("----------<graph>----------\n");
        for (int i = 0; i < n; i++) {
            printf("|");
            for (int j = 0; j < m; j++) {
                printf("%2d", baechu[i][j]);
            }
            printf("\n");
        }*/
        //baechu[][]
        

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && baechu[i][j]) {
                    answer++;
                    DFS(i, j);
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}

void DFS(int row, int col) {
    //printf("now : baechu[%d][%d]\n", row, col);
    visited[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int new_row = row + y[i];
        int new_col = col + x[i];
        if (new_row < 0 || new_row >= n || new_col < 0 || new_col >= m) continue;
        
        if (!visited[new_row][new_col] && baechu[new_row][new_col]) {
            DFS(new_row, new_col);
        }
    }
}
