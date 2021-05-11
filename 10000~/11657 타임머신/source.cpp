#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

typedef long long ll;

typedef struct {
    int from;
    int to;
    int weight;
} edge;

vector<edge> edges;
ll dist[501]; //underflow가 일어날 수 있기 때문에 long long으로 선언

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    fill(dist, dist+501, INF);
    dist[1] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back({a, b, c});
    }

    for (int i = 1; i < n; i++) {
        for (edge e: edges) {
            ll new_dist = dist[e.from] + e.weight;
            if (dist[e.from] == INF) continue; //여기서 틀렸었음. from이 INF이고 가중치가 음수이면 갱신되기때문에 틀림!
            if (new_dist < dist[e.to]) dist[e.to] = new_dist; //갱신
        }
    }

    int flag = 0;
    for (edge e: edges) {
        ll new_dist = dist[e.from] + e.weight;
        if (dist[e.from] == INF) continue;
        if (new_dist < dist[e.to]) flag = 1; //n번째에도 갱신하면 음수 사이클 존재
    }

    if (flag) printf("-1\n");
    else for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) printf("-1\n");
        else printf("%lld\n", dist[i]);
    }

    return 0;
}