#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> edges[100001];

int main() {
    int V;
    cin >> V;

    for (int i = 0; i < V; i++) {
        int from, to, cost;

        cin >> from >> to;

        while (to != -1) {
            cin >> cost;
            edges[i].push_back({to, cost});
            printf("%d¿¡ push\n", from);
            cin >> to;
        }
    }

    for (int i = 1; i <= 5; i++) {
        for (auto p: edges[i]) {
            printf("(%d, %d) ", p.first, p.second);
        }
        putchar('\n');
    }
}
