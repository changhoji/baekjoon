#include <iostream>
#include <set>
#include <queue>
using namespace std;

#define INAIR 0
#define CHEESE 1
#define OUTAIR 2

//첨에 가장자리에서 시작해 공기 체크하고
//치즈가 한번 지워질때마다 그 지워진 자리에서 bfs로 내부공기 외부공기로 바꾸기

int map[100][100];
int cheese_cnt = 0;
int d_row[] = {0, 1, 0, -1};
int d_col[] = {1, 0, -1, 0};

void printMap(int N, int M);

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> cheese_pos;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j]) {
                cheese_cnt++;
                cheese_pos.insert({i, j});
            }
        }
    }
    map[0][0] = OUTAIR;

    //처음 외부 공기 체크하는 bfs
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int new_row = cur.first + d_row[k];
            int new_col = cur.second + d_col[k];

            if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= M) continue;
            if (map[new_row][new_col] == INAIR) {
                map[new_row][new_col] = OUTAIR;
                q.push({new_row, new_col});
            }
        }
    }

    int time = 0;

    while (cheese_cnt) {
        vector<pair<int, int>> melted_pos;

        //각각의 치즈에 대해 녹는지 검사하는 포문
        for (auto iter = cheese_pos.begin(); iter != cheese_pos.end();) {
            auto p = *iter;
            int air_cnt = 0;
            for (int k = 0; k < 4; k++) {
                int new_row = p.first + d_row[k];
                int new_col = p.second + d_col[k];

                if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= M) continue;
                if (map[new_row][new_col] == OUTAIR) air_cnt++;
                
            }
            if (air_cnt >= 2) {
                //printf("erase -> row = %d, col = %d\n", p.first, p.second);
                melted_pos.push_back(p);
                iter = cheese_pos.erase(iter);
                cheese_cnt--;
                //printf("cnt = %d\n", cheese_cnt);
                //printMap(N, M);
                }
            else iter++;
        }

        queue<pair<int, int>> q;
        //녹은 치즈에서 시작해 내부공기를 외부공기로 바꾸는 bfs
        for (auto p: melted_pos) {
            q.push(p);
            //printf("(%d, %d)\n", p.first, p.second);
            map[p.first][p.second] = OUTAIR;
        }
        melted_pos.clear();

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int new_row = cur.first + d_row[k];
                int new_col = cur.second + d_col[k];

                if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= M) continue;
                if (map[new_row][new_col] == INAIR) {
                    map[new_row][new_col] = OUTAIR;
                    q.push({new_row, new_col});
                }
            }
        }

        time++;
    }

    cout << time << endl;

    return 0;
}

void printMap(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == OUTAIR) printf("%d ", 0);
            else printf("%d ", map[i][j]);
        }
        putchar('\n');
    }
}
