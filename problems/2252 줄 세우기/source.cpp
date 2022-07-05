#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int degree[32001] = { 0,};
vector<int> adj[32001];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        degree[b]++;        
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) q.push(i);
    }

    for (int i = 1; i <= N; i++) {
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for (auto n: adj[cur]) {
            degree[n]--;
            if (degree[n] == 0) q.push(n);
        }
    }

    cout << '\n';

    return 0;
}
