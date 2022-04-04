#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321
typedef long long ll;

struct edge {
    int from;
    int to;
    int cost;

    bool comp(edge e1, edge e2) {
        return e1.cost > e2.cost;
    }
};

void dijkstra(int start);

int N, E;
int dist[801];
vector<edge> edges[801];

int main() {
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;

        edge e1 = {v1, v2, c};
        edge e2 = {v2, v1, c};
        edges[v1].push_back(e1);
        edges[v2].push_back(e2);
    }

    int th1, th2;
    cin >> th1 >> th2;

    dijkstra(1);
    int one2N = dist[N], one2th1 = dist[th1], one2th2 = dist[th2];

    dijkstra(N);
    int N2th1 = dist[th1], N2th2 = dist[th2];

    dijkstra(th1);
    int th12th2 = dist[th2];

    ll res = min((ll)one2th1 + th12th2 + N2th2, (ll)one2th2 + th12th2 + N2th1);
    if (res >= INF) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}

void dijkstra(int start) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        auto cur = pq.top();
        int nowDist = -cur.first;
        int nowNode = cur.second;
        pq.pop();
        if (nowDist > dist[nowNode]) continue;

        for (auto e: edges[nowNode]) {
            if (nowDist + e.cost < dist[e.to]) {
                dist[e.to] = nowDist + e.cost;
                pq.push(make_pair(-dist[e.to], e.to));
            }
        }
    }
}