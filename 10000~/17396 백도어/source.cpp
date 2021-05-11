#include <stdio.h>
#include <vector>
#include <queue>
#define INF 10987654321
using namespace std;

typedef long long ll; //최소 거리가 int형 최대보다 클수 있음! long long 사용

int n, m; //n : vertex, m : edge
int sight[100001];
ll dist[100001];
vector<pair<int, int>> edges[100001]; //edges(to, weight)

int main() {
    fill(dist, dist+100001, INF);
    dist[1] = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &sight[i]);
    sight[n] = 0; //보여도 갈수 있기때문에 0과 취급이 같음
    for (int i = 0; i < m; i++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        a++;
        b++;
        if (sight[a] || sight[b]) continue;//둘중 보이는곳이 있으면 간선추가 안함
        edges[a].push_back({b, t});
        edges[b].push_back({a, t});
    }

    priority_queue<pair<ll, int>> pq; //pq(-dist, vertex)
    pq.push({0, 1});
    while (!pq.empty()) {
        ll now_distance = -pq.top().first; //최소힙 우선순위를 위해 -거리로 저장했음
        int now_node = pq.top().second;
        pq.pop();

        if (now_distance > dist[now_node]) continue;
        for (pair<int, int> p: edges[now_node]) { //현재 노드의 엣지로 탐색
            ll new_distance = now_distance + (ll)p.second;
            if (new_distance < dist[p.first]) { //새로 본 거리가 다음 노드의 dist값보다 작다면
                dist[p.first] = new_distance;
                pq.push({-new_distance, p.first});
            }
        }
    }

    if (dist[n] == INF) printf("-1\n");
    else printf("%lld\n", dist[n]);

    return 0;
}