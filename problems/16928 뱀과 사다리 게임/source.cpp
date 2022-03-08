#include <iostream>
#include <queue>
using namespace std;

int main() {
    int path[101] = { 0,};
    int dist[101] = { 0,};
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        path[x] = y;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        path[u] = v;
    }

    for (int i = 0; i <= 100; i++) {
        dist[i] = -1;
    }
    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int from = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int to = from + i;
            if (to > 100)
                continue;
            
            if (path[to] != 0) {
                to = path[to];
            }
            if (dist[to] == -1) {
                q.push(to);
                dist[to] = dist[from] + 1;
            }
        }
    }

    cout << dist[100] << endl;

    return 0;
}