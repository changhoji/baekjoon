#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int time[10001];
int res[10001] = { 0,};
int inDegree[10001] = { 0,};
vector<int> edges[10001];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> time[i];
        
        while (1) {
            int num;
            cin >> num;
            if (num == -1) break;

            edges[num].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    for (int i = 1; i <= N; i++) {
        auto cur = q.front();
        q.pop();
        res[cur] += time[cur];

        for (auto j: edges[cur]) {
            res[j] = max(res[j], res[cur]);
            inDegree[j]--;
            if (inDegree[j] == 0) q.push(j);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}