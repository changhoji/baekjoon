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
        int M;
        cin >> M;

        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            edges[i].push_back(num);
            inDegree[num]++;
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

    cout << *max_element(res+1, res+1+N) << '\n';

    return 0;
}