#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> s;
int now_size = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[100][100] = { 0,};
bool visited[100][100] = {false};

void DFS(int y, int x);

int main() {
    int k;
    scanf("%d %d %d", &n, &m, &k);

    for (int test_case = 0; test_case < k; test_case++) {
        int from_y, to_y, from_x, to_x;
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        for (int x = from_x; x < to_x; x++) {
            for (int y = from_y; y < to_y; y++) {
                map[y][x] = 1;
            }
        }
    } //입력과 맵 초기화
    
    int cnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (!map[y][x] && !visited[y][x]) {
                now_size = 0;
                DFS(y, x);
                s.push_back(now_size);
                cnt++;
            }
        }
    }

    sort(s.begin(), s.end());
    printf("%d\n", cnt);
    for (int i = 0; i < s.end()-s.begin(); i++) {
        printf("%d ", s[i]);
    }

    /*
    printf("\nmap : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}

void DFS(int y, int x) {
    now_size++;
    //printf("size = %d, y = %d, x = %d, this_map = %d\n", now_size, y, x, map[y][x]);
    visited[y][x] = true;
    for (int k = 0; k < 4; k++) {
        int new_y = y + dy[k];
        int new_x = x + dx[k];
        if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) continue;
        if (!visited[new_y][new_x] && !map[new_y][new_x]) {
            DFS(new_y, new_x);
        }
    }
}