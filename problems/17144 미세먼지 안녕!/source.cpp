#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, T;
int map[51][51];
int add[51][51] = { 0,};

int d_row[] = {1, 0, -1, 0};
int d_col[] = {0, 1, 0, -1};

void printMap() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            printf("%3d ", map[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    cin >> R >> C >> T;
    int flag = false;
    int cleaner;
    int sum = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> map[r][c];
            if (map[r][c] == -1 && flag == false) {
                flag = true;
                cleaner = r;
            }
            if (map[r][c] > 0) sum += map[r][c];
        }
    }


    for (int t = 1; t <= T; t++) {
        //미세먼지 확산
        
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (map[i][j] <= 0) continue;
                int spread_cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int new_row = i + d_row[k];
                    int new_col = j + d_col[k];
                    if (new_row <= 0 || new_row > R || new_col <= 0 || new_col > C || map[new_row][new_col] == -1) continue;

                    add[new_row][new_col] += map[i][j] / 5;
                    spread_cnt++;
                }

                map[i][j] -= map[i][j]/5*spread_cnt;
            }
        }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                map[i][j] += add[i][j];
                add[i][j] = 0;
            }
        }

        //printf("----------확산-----------\n");
        //printMap();

        sum -= map[cleaner+2][1];
        for (int r = cleaner+2; r <= R-1; r++) {
            map[r][1] = map[r+1][1];
        }
        for (int c = 1; c <= C-1; c++) {
            map[R][c] = map[R][c+1];
        }
        for (int r = R; r >= cleaner+2; r--) {
            map[r][C] = map[r-1][C];
        }
        for (int c = C; c >= 3; c--) {
            map[cleaner+1][c] = map[cleaner+1][c-1];
        }
        map[cleaner+1][2] = 0;

        

        sum -= map[cleaner-1][1];
        for (int r = cleaner-1; r >= 2; r--) {
            map[r][1] = map[r-1][1];
        }
        for (int c = 1; c <= C-1; c++) {
            map[1][c] = map[1][c+1];
        }
        for (int r = 1; r <= cleaner-1; r++) {
            map[r][C] = map[r+1][C];
        }
        for (int c = C; c >= 3; c--) {
            map[cleaner][c] = map[cleaner][c-1];
        }
        map[cleaner][2] = 0;

        //printf("t = %d---------------------\n", t);
        //printMap();
    }
    
    cout << sum << endl;

    return 0;
}
