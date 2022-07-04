#include <iostream>
#include <stack>
using namespace std;

bool visited[26] = { false,};
int ans = 0;

int drow[] = { 0, 1, 0, -1 };
int dcol[] = { 1, 0, -1, 0 };

void backTracking(pair<int, int> pos, int dist);
char map[20][20];

int R, C;

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }

    visited[map[0][0]-'A'] = true;
    backTracking(make_pair(0, 0), 1);

    cout << ans << '\n';

    return 0;
}

void backTracking(pair<int, int> pos, int dist) {
    //printf("pos = ( %d, %d ), dist = %d\n", pos.first, pos.second, dist);
    for (int k = 0; k < 4; k++) {
        pair<int, int> npos = make_pair(pos.first+drow[k], pos.second+dcol[k]);
        if (npos.first < 0 || npos.first >= R || npos.second < 0 || npos.second >= C) continue;
        if (!visited[map[npos.first][npos.second]-'A']) {
            visited[map[npos.first][npos.second]-'A'] = true;
            backTracking(npos, dist+1);
            visited[map[npos.first][npos.second]-'A'] = false;
        }
    }

    ans = max(ans, dist);
}
