#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        int time[1001];
        int res[1001] = { 0,};
        vector<int> edges[1001];
        int inDegree[1001] = { 0,};

        int N, K;
        cin >> N >> K;

        for (int i = 1; i <= N; i++) {
            cin >> time[i];
        }

        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;

            edges[X].push_back(Y);
            inDegree[Y]++;
        }

        int W;
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (inDegree[W] > 0) {
            auto cur = q.front();
            q.pop();

            for (int i: edges[cur]) {
                res[i] = max(res[i], res[cur]+time[cur]);
                inDegree[i]--;
                if (inDegree[i] == 0) q.push(i);
            }
        }
        cout << res[W] + time[W] << '\n';
    }
    return 0;
}
