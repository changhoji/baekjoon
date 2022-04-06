#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct pos {
    int row;
    int col;
    int direction;  // 0: 가로, 1: 세로, 2: 대각
};

struct DP {
    int arr[16][16][3] = { 0,};
    int &operator[](pos p) { return arr[p.row][p.col][p.direction]; }
    int getDp(int row, int col) {
        return arr[row][col][0] + arr[row][col][1] + arr[row][col][2];
    }
};

int map[16][16];
int d_row[] = {0, 1, 1};
int d_col[] = {1, 0, 1};

int main() {
    DP dp;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    dp.arr[0][1][0] = 1;
    
    set<pair<pos, pos>> check;
    queue<pos> q;
    q.push({0, 1, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int k = 0; k < 3; k++) {
            if ((cur.direction == 0 && k == 1) || (cur.direction == 1 && k == 0)) continue;
            if (k == 2) { //대각으로 갈때 장애물 있으면
                if (map[cur.row+1][cur.col] || map[cur.row][cur.col+1]) continue;
            }

            int new_row = cur.row + d_row[k];
            int new_col = cur.col + d_col[k];
            int new_direction = (new_col - cur.col - 1) + 2 * (new_row - cur.row);

            pos new_pos = {new_row, new_col, new_direction};

            if (new_pos.row >= N || new_pos.col >= N || map[new_pos.row][new_pos.col])
                continue;

            //printf("dp[%d][%d][%d] += dp[%d][%d][%d] (%d): (%d) -> (%d)\n", new_pos.row, new_pos.col, new_pos.direction, cur.row, cur.col, cur.direction, dp[cur], dp[new_pos], dp[new_pos]+dp[cur]);
            dp[new_pos] += dp[cur];
            q.push(new_pos);
        }

        if (cur.row != N-1 || cur.col != N-1)
            dp[cur] = 0;
    }

    cout << dp.getDp(N-1, N-1) << endl;

    return 0;
}
