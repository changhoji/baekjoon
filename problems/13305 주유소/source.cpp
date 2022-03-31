#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll length[100000]; //length[i]: i도시와 i+1도시를 잇는 도로의 길이
ll cost[100001];   //cost[i]: i도시에서의 기름가격

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N-1; i++) {
        cin >> length[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    ll minCost = cost[1];
    ll res = 0;

    for (int i = 1; i <= N-1; i++) {
        if (cost[i] < minCost) minCost = cost[i];

        res += minCost*length[i];
    }

    cout << res << endl;

    return 0;
}