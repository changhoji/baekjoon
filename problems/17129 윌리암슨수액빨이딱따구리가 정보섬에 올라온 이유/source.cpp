#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int n, m;
int map[3000][3000];
int len[3000][3000];

int main() {
    cin >> n >> m;

    pair<int, int> start;

    char c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            map[i][j] = c-'0';
            if (map[i][j] == 2) {
                start = make_pair(i, j);
            }
        }
    }

    memset(len, -1, sizeof(len));

    int answer = -1;
    

    len[start.first][start.second] = 0;

    queue<pair<int, int>> q;
    q.push(start);

    bool flag = false;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            pair<int, int> new_pair = make_pair(cur.first+dr[k], cur.second+dc[k]);
            
            if (new_pair.first < 0 || new_pair.first >= n || new_pair.second < 0 || new_pair.second >= m) continue; //맵 밖일때
            if (map[new_pair.first][new_pair.second] == 1 || len[new_pair.first][new_pair.second] != -1) continue; //벽이거나 이미 갔으면

            if (map[new_pair.first][new_pair.second] >= 3) {
                answer = len[cur.first][cur.second]+1;
                flag = true;
                break;
            }
            len[new_pair.first][new_pair.second] = len[cur.first][cur.second]+1;
            q.push(new_pair);
        }

        if (flag) break;
    }

    if (~answer) cout << "TAK\n" << answer << '\n';
    else cout << "NIE\n";
    
    return 0;
}