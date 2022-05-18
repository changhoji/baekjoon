#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define row first
#define col second

typedef pair<int, int> pos;

int d_row[] = { 1, 0, -1, 0 };
int d_col[] = { 0, 1, 0, -1 };

char map[1001][1001];
int dist[1001][1001][2] = { 0,};

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    queue<pair<pos, int>> q;
    q.push(make_pair(make_pair(1, 1), 0));
    dist[1][1][0] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        //printf("pos = (%d, %d), second: %d\n", cur.first.row, cur.first.col, cur.second);

        for (int k = 0; k < 4; k++) {
            pos next = make_pair(cur.first.row+d_row[k], cur.first.col+d_col[k]);
            if (next.row <= 0 || next.row > N || next.col <= 0 || next.col > M) continue;
            if (map[next.row][next.col] == '1' && cur.second == 1) continue; //벽인데 이미 부쉈으면 x

            if (cur.second == 1) {
                if (dist[next.row][next.col][1]) continue;
                dist[next.row][next.col][1] = dist[cur.first.row][cur.first.second][1]+1;
                q.push(make_pair(next, 1));
            }
            else {
                if (map[next.row][next.col] == '1') { //뚫어야 할때
                    if (dist[next.row][next.col][1]) continue;
                    dist[next.row][next.col][1] = dist[cur.first.row][cur.first.col][0]+1;
                    q.push(make_pair(next, 1));
                }
                else {
                    if (dist[next.row][next.col][0]) continue;
                    dist[next.row][next.col][0] = dist[cur.first.row][cur.first.col][0]+1;
                    q.push(make_pair(next, 0));
                }
            }
        }
    }

    int res = min(dist[N][M][0], dist[N][M][1]);

    if (dist[N][M][0] == 0) res = dist[N][M][1];
    if (dist[N][M][1] == 0) res = dist[N][M][0];

    if (res) std::cout << res << '\n';
    else std::cout << "-1\n";

    return 0;
}