#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int inDegree[1001] = { 0,};
vector<int> edges[1001];
vector<int> res;

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;

        int a, b;
        cin >> a;

        for (int j = 1; j < K; j++) {
            cin >> b;
            edges[a].push_back(b);
            inDegree[b]++;
            a = b;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    bool ansExsit = true;
    for (int n = 1; n <= N; n++) {
        if (q.empty()) {
            ansExsit = false;
            break;
        }

        auto cur = q.front();
        q.pop();
        res.push_back(cur);

        for (auto i: edges[cur]) {
            inDegree[i]--;
            if (inDegree[i] == 0) q.push(i);
        }
    }

    if (ansExsit)
        for (auto i: res) {
            cout << i << '\n';
        }
    else 
        cout << "0\n";

    return 0;
}
