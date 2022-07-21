#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

vector<int> capacity;
vector<pair<int, int>> jewel;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N, K;
    cin >> N >> K;

    int M, V;

    for (int i = 0; i < N; i++) {
        cin >> M >> V;
        jewel.push_back(make_pair(M, V));
    }
    sort(jewel.begin(), jewel.end());

    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        capacity.push_back(num);
    }
    sort(capacity.begin(), capacity.end());

    priority_queue<int> pq;
    
    ll ans = 0;
    int idx = 0;
    for (int i = 0; i < K; i++) {
        while (idx < N && jewel[idx].first <= capacity[i])
            pq.push(jewel[idx++].second); //보석 넣을 수 있으면 value만 따지면 됨

        //만약 위에서 아무것도 안넣었다면 그 전에 있던것은 무조건 넣을수 있으므로
        //전의 것중 가장 값이 큰걸 사용!
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';

    return 0;
}