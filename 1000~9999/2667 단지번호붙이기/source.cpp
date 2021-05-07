#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int now_size = 0;
int map[25][25] = { 0,};
bool visited[25][25] = {false};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void search(int row, int col);

int main() {
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char temp[26];
        scanf("%s", temp);
        for (int j = 0; j < n; j++) {
            map[i][j] = temp[j]-48;
        }
    }
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] && !visited[i][j]) {
                cnt++;
                search(i, j);
                v.push_back(now_size);
                now_size = 0;
            }        
        }
    }
    sort(v.begin(), v.end());
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d\n", v[i]);
    }
    return 0;
}

void search(int row, int col) {
    now_size++;
    visited[row][col] = true;
    for (int k = 0; k < 4; k++) {
        int new_row = row + dy[k];
        int new_col = col + dx[k];
        if (new_row < 0 || new_row >= n || new_col < 0 || new_col >= n) continue;
        if (map[new_row][new_col] && !visited[new_row][new_col]) search(new_row, new_col);
    }
}