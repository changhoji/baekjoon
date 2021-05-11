#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

typedef struct {
    int from;
    int to;
    int weight; 
} edge;

int dist[501];

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 0; test_case < t; test_case++) {
        fill(dist, dist+501, INF);
        dist[1] = 0;
        vector<edge> edges;
        int n, m, w;
        scanf("%d %d %d", &n, &m, &w);
        for (int i = 0; i < m; i++) { //도로 간선
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for (int i = 0; i < w; i++) {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back({s, e, -t});
        }

        for (int i = 1; i < n; i++) {
            for (edge e: edges) {
                if (dist[e.from] == INF) continue; //11657과 다르게 여기선 이걸 빼니까 맞음.
                if (dist[e.from] + e.weight < dist[e.to]) //도로 간선이 양방향이기 때문에?
                    dist[e.to] = dist[e.from] + e.weight;
            }
        }

        int cycle = 0;
        for (edge e: edges) {
            if (dist[e.from] == INF) continue;
            if (dist[e.from] + e.weight < dist[e.to]) {
                cycle = 1;
                break;
            }
        }
        
        //for (int i = 1; i <= n; i++) printf("%d\n", dist[i]);

        if (cycle) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}