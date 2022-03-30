#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define V_MAX 60
#define MAX 987654321

int charToInt(char c) {
    if ('a' <= c && c <= 'z') return c-'a';
    return c-'A'+26;
}



//adj matrix
int capacity[V_MAX][V_MAX] = { 0,};
int flow[V_MAX][V_MAX] = { 0,};

//edmonds-karp
int edmonds_karp (int source, int sink, int numOfVertex) {
    int result = 0;

    //each case of finding a path
    while (true) {
        vector<int> parent(V_MAX, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        //find a path(bfs)
        while (!q.empty() && parent[sink] == -1) {
            int cur = q.front();
            q.pop();
            for (int to = 0; to < numOfVertex; to++) {
                if (capacity[cur][to] - flow[cur][to] > 0 && parent[to] == -1) {
                    q.push(to);
                    parent[to] = cur;
                }
            }
        }

        //if there's no more path
        if (parent[sink] == -1) break;

        //if there's a path
        int amount = MAX;

        //find minimum residual capacity
        int now;
        for (now = sink; now != source; now = parent[now]) {
            amount = min(capacity[parent[now]][now] - flow[parent[now]][now], amount);
        }

        //edit flow
        for (int now = sink; now != source; now = parent[now]) {
            flow[parent[now]][now] += amount;
            flow[now][parent[now]] -= amount;
        }

        result += amount;
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b;
        int f;
        cin >> a >> b >> f;

        capacity[charToInt(a)][charToInt(b)] += f;
        capacity[charToInt(b)][charToInt(a)] += f;
    }

    cout << edmonds_karp(charToInt('A'), charToInt('Z'), 60) << endl;

    return 0;
}