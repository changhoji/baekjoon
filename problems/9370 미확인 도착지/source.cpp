#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

struct comp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }  
};

int dist[2001];

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, m, t, s, g, h;
        vector<int> to;
        vector<pair<int, int>> edge[2001];
        bool passed[2001] = { false,};

        cin >> n >> m >> t >> s >> g >> h;
        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
        }
        dist[s] = 0;
        int _g = g, _h = h;
        g = min(_g, _h);
        h = max(_g, _h);

        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            edge[a].push_back({b, d});
            edge[b].push_back({a, d});
        }
        
        for (int i = 0; i < t; i++) {
            int num;
            cin >> num;

            to.push_back(num);
        }

        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        pq.push({s, 0});

        while (!pq.empty()) {
            auto cur = pq.top(); //first: now node, second: now dist
            pq.pop();
            if (cur.second > dist[cur.first]) continue;

            for (auto p: edge[cur.first]) { //p-> first: to edge, second: weight
                if (dist[p.first] >= cur.second + p.second) {
                    int beforeDist = dist[p.first];
                    dist[p.first] = cur.second + p.second;
                    if (beforeDist > cur.second + p.second)
                        pq.push({p.first, dist[p.first]});
                    //p.first와 cur.first 가 g와 h이면
                    if ((g == min(p.first, cur.first) && h == max(p.first, cur.first)) || passed[cur.first]) {
                        passed[p.first] = true;
                    }
                    else if (beforeDist > cur.second + p.second)
                        passed[p.first] = false;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            //printf("dist[%d] = %d, passed[%d] = %d\n", i, dist[i], i, passed[i]);
        }

        sort(to.begin(), to.end());
        for (auto i: to) {
            if (passed[i]) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}