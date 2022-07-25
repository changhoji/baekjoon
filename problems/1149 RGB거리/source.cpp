#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

#define RED 0
#define GREEN 1
#define BLUE 2

int cost[1001][3];
int dp[1001][3] = { 0,};

int set_dp(int n, int color);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    cout << min(min(set_dp(N, RED), set_dp(N, GREEN)), set_dp(N, BLUE)) << '\n';

    return 0;
}

int set_dp(int n, int color) {
    if (n == 1) return dp[n][color] = cost[n][color];

    if (dp[n][color]) return dp[n][color];

    int res = INF;

    for (int i = 0; i < 3; i++) {
        if (color == i) continue;
        res = min(res, set_dp(n-1, i) + cost[n][color]);
    }

    return dp[n][color] = res;
}