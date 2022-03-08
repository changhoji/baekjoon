#include <stdio.h>
#include <queue>
using namespace std;

int n, from, to;
int node[101][101] = { 0,};
bool visited[101] = {false};
int dis[101] = { 0,};

int main() {
    bool is_answer = false;
    scanf("%d", &n);
    scanf("%d %d", &from, &to);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int temp_a, temp_b;
        scanf("%d %d", &temp_a, &temp_b);
        node[temp_a][temp_b] = 1;
        node[temp_b][temp_a] = 1;
    }

    queue<int> q;
    visited[from] = true;
    q.push(from);

    while (!q.empty()) {
        int temp_from = q.front();
        if (temp_from == to) is_answer = true;
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (node[temp_from][i] && !visited[i]) {
                visited[i] = true;
                dis[i] = dis[temp_from] + 1;
                q.push(i);
            }
        }
    }

    if (is_answer) printf("%d\n", dis[to]);
    else printf("-1\n");

    return 0;
}
