#include <stdio.h>
#include <queue>
using namespace std;

int tomato[1000][1000];
int n, m;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

int answer() {
    int max = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0) return -1;
            if (max < tomato[i][j]) max = tomato[i][j];
        }
    }
    return max-1;
}

void now_tomato() {
    printf("------------------------\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d", tomato[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

int main() {
    queue<pair<int, int>> q;
    int is_answer = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &tomato[i][j]);
            if (tomato[i][j] == 1) q.push({i, j});
        }
    } //init

    while (!q.empty()) {
        pair<int, int> temp = {q.front().first, q.front().second};
        q.pop();
        for (int k = 0; k < 4; k++) {
            int new_row = temp.first + y[k];
            int new_col = temp.second + x[k];
            if (0 <= new_row && new_row < n && 0 <= new_col && new_col < m)
                if (tomato[new_row][new_col] == 0) {
                    tomato[new_row][new_col] = tomato[temp.first][temp.second]+1;
                    q.push({new_row, new_col});
                }
        }
    }

    printf("%d\n", answer());
    return 0;
}