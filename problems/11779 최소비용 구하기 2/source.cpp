#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

pair<int, vector<int>> dist[1001];
vector<pair<int, int>> edges[1001];

struct comp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second > b.second) return true;
        return false;
    }
};



int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dist[i].first = INF;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
    }

    int from, to;
    cin >> from >> to;

    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    dist[from].first = 0;
    dist[from].second.push_back(from);

    pq.push(make_pair(from, 0));

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (cur.second > dist[cur.first].first) continue;

        for (auto p: edges[cur.first]) {
            if (cur.second + p.second < dist[p.first].first) {
                dist[p.first].first = dist[cur.first].first + p.second;
                dist[p.first].second = vector<int> (dist[cur.first].second);
                dist[p.first].second.push_back(p.first);
                pq.push(make_pair(p.first, dist[p.first].first));
            }
        }
    }

    cout << dist[to].first << '\n' << dist[to].second.size() << '\n';

    for (auto i: dist[to].second) {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}
