#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

vector<pair<int, int>> points(20);
bool used[20] = { false,};
double ans = 987654321;

void brute_force(int N, int idx, int cnt);

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> points[i].first >> points[i].second;
        }

        ans = 987654321;
        brute_force(N, 0, 0);

        printf("%.7lf\n", ans);
    }
    
    return 0;
}

void brute_force(int N, int idx, int cnt) { //cnt = n -> 지금까지 n개 사용했다.
    if (idx == N && cnt < N/2) return;
    else if (cnt == N/2) {
        pair<ll, ll> vec = make_pair(0, 0);
        for (int i = 0; i < N; i++) {
            if (used[i]) {
                vec.first += points[i].first;
                vec.second += points[i].second;
            }
            else {
                vec.first -= points[i].first;
                vec.second -= points[i].second;
            }
        }
        ans = min(ans, sqrt(vec.first*vec.first + vec.second*vec.second));
        return;
    }
    
    brute_force(N, idx+1, cnt);
    used[idx] = true;
    brute_force(N, idx+1, cnt+1);
    used[idx] = false;
}