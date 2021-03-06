#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

vector<pair<int, int>> edges[100001];

int main() {
    int V;
    cin >> V;

    for (int i = 1; i <= V; i++) {
        int from, to, cost;

        cin >> from >> to;

        while (to != -1) {
            cin >> cost;
            edges[from].push_back({to, cost});
            cin >> to;
        }
    }

    int dist[100001];

    memset(dist, -1, sizeof(dist));

    dist[1] = 0;
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        auto cur = s.top();
        s.pop();

        for (auto p: edges[cur]) {
            if (dist[p.first] != -1) continue;
            dist[p.first] = dist[cur] + p.second;
            s.push(p.first);
        }
    }

    pair<int, int> max = {0, 0};
    for (int i = 1; i <= V; i++) {
        //printf("dist[%d] = %d\n", i, dist[i]);
        if (dist[i] > max.second) max = {i, dist[i]};
    }
    //printf("first: %d\n", max.first);

    memset(dist, -1, sizeof(dist));

    dist[max.first] = 0;
    s.push(max.first);
    while (!s.empty()) {
        auto cur = s.top();
        s.pop();

        for (auto p: edges[cur]) {
            if (dist[p.first] != -1) continue;
            dist[p.first] = dist[cur] + p.second;
            s.push(p.first);
        }
    }

    pair<int, int> ans = {0, 0};
    for (int i = 1; i <= V; i++) {
        //printf("dist[%d] = %d\n", i, dist[i]);
        if (dist[i] > ans.second) ans = {i, dist[i]};
    }
    //printf("first: %d\n", ans.first);

    cout << ans.second << endl;

    return 0;
}
