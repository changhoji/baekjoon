#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int dist[101][101];
int item[101];

int main() {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) dist[i][j] = INF;
    }
    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
        dist[i][i] = 0;
    }

    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k]+dist[k][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m) cnt += item[j];
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}