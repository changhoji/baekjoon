#include <stdio.h>
#include <queue>
using namespace std;

int tomato[100][100][100];
int n, m, h;
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

typedef struct {
    int row, col, hei;
} pos;

int answer() {
    int max = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < h; l++) {
                if (tomato[i][j][l] == 0) return -1;
                if (max < tomato[i][j][l]) max = tomato[i][j][l];
            }
        }
    }
    return max-1;
}

int main() {
    queue<pos> q;
    int is_answer = 0;
    scanf("%d %d %d", &m, &n, &h);
    for (int l = 0; l < h; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &tomato[i][j][l]);
                if (tomato[i][j][l] == 1) q.push({i, j, l});
            }
        }
    } //init

    while (!q.empty()) {
        pos temp = {q.front().row, q.front().col, q.front().hei};
        q.pop();
        for (int k = 0; k < 6; k++) {
            int new_row = temp.row + dy[k];
            int new_col = temp.col + dx[k];
            int new_hei = temp.hei + dz[k];

            if (0 <= new_row && new_row < n && 0 <= new_col && new_col < m && 0 <= new_hei && new_hei < h)
                if (tomato[new_row][new_col][new_hei] == 0) {
                    tomato[new_row][new_col] [new_hei]= tomato[temp.row][temp.col][temp.hei]+1;
                    q.push({new_row, new_col, new_hei});
                }
        }
    }

    printf("%d\n", answer());
    return 0;
}