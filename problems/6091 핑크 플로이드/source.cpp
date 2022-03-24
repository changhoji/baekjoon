#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dist[1025][1025] = { 0,};
int par[1025];
vector<int> nearNode[1025];

int find(int a) {
    if (par[a] == a) return a;
    else return par[a] = find(par[a]);
}

void union_(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    if (aa < bb) par[bb] = aa;
    else par[aa] = bb;
}

int main() {
    priority_queue<pair<int, pair<int, int>>> pq;
    int N;   //정점개수
    cin >> N;
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j <= N; j++) {
            int d;
            cin >> d;
            pq.push({-d, {i, j}});
        }
    }
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int vA = pq.top().second.first;
        int vB = pq.top().second.second;
        pq.pop();
        if (find(vA) != find(vB)) {
            nearNode[vA].push_back(vB);
            nearNode[vB].push_back(vA);
            union_(vA, vB);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << nearNode[i].size() << " ";
        sort(nearNode[i].begin(), nearNode[i].end());
        for (auto i: nearNode[i]) {
            cout << i << " ";
        }
        cout << '\n';
    }

   return 0; 
}
