#include <stdio.h>
#include <vector>
#include <queue>
#define INF 10987654321
using namespace std;

typedef long long ll; //�ּ� �Ÿ��� int�� �ִ뺸�� Ŭ�� ����! long long ���

int n, m; //n : vertex, m : edge
int sight[100001];
ll dist[100001];
vector<pair<int, int>> edges[100001]; //edges(to, weight)

int main() {
    fill(dist, dist+100001, INF);
    dist[1] = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &sight[i]);
    sight[n] = 0; //������ ���� �ֱ⶧���� 0�� ����� ����
    for (int i = 0; i < m; i++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        a++;
        b++;
        if (sight[a] || sight[b]) continue;//���� ���̴°��� ������ �����߰� ����
        edges[a].push_back({b, t});
        edges[b].push_back({a, t});
    }

    priority_queue<pair<ll, int>> pq; //pq(-dist, vertex)
    pq.push({0, 1});
    while (!pq.empty()) {
        ll now_distance = -pq.top().first; //�ּ��� �켱������ ���� -�Ÿ��� ��������
        int now_node = pq.top().second;
        pq.pop();

        if (now_distance > dist[now_node]) continue;
        for (pair<int, int> p: edges[now_node]) { //���� ����� ������ Ž��
            ll new_distance = now_distance + (ll)p.second;
            if (new_distance < dist[p.first]) { //���� �� �Ÿ��� ���� ����� dist������ �۴ٸ�
                dist[p.first] = new_distance;
                pq.push({-new_distance, p.first});
            }
        }
    }

    if (dist[n] == INF) printf("-1\n");
    else printf("%lld\n", dist[n]);

    return 0;
}