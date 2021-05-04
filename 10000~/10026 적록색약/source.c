#include <stdio.h>
#include <string.h>

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char map[100][101];
int visited[100][100] = { 0,};

void R_G_B(int row, int col);
void RG_B(int row, int col);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    int r_g_b = 0;
    int rg_b = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                r_g_b++;
                R_G_B(i, j);
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                rg_b++;
                RG_B(i, j);
            }
        }
    }
    printf("%d %d", r_g_b, rg_b);

    return 0;
}

void R_G_B(int row, int col) {
    visited[row][col] = 1;
    for (int k = 0; k < 4; k++) {
        int new_row = row + dy[k];
        int new_col = col + dx[k];
        if (new_row < 0 || new_row >= n || new_col < 0 || new_col >= n) continue;
        if (map[row][col] == map[new_row][new_col] && !visited[new_row][new_col]) R_G_B(new_row, new_col);
    }
}

void RG_B(int row, int col) {
    visited[row][col] = 1;
    for (int k = 0; k < 4; k++) {
        int new_row = row + dy[k];
        int new_col = col + dx[k];
        if (new_row < 0 || new_row >= n || new_col < 0 || new_col >= n) continue;
        int from = (map[row][col] == 'B') ? 0 : 1;
        int to = (map[new_row][new_col] == 'B') ? 0 : 1;
        if (from == to && !visited[new_row][new_col]) RG_B(new_row, new_col);
    }
}