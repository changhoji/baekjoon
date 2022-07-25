#include <iostream>
#include <algorithm>
using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

int cost[1001][3];
int dp[1001][3] = { 0,};

int set_dp(int n, int color);

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    dp[N][RED] = set_dp(N, RED);
    dp[N][GREEN] = set_dp(N, GREEN);
    dp[N][BLUE] = set_dp(N, BLUE);

    cout << min(min(dp[N][RED], dp[N][GREEN]), dp[N][BLUE]) << '\n';

    return 0;
}

int set_dp(int n, int color) {
    if (n == 1) return dp[n][color] = cost[n][color];
    for (int i = 0; i < 3; i++) {
        if (color == i) continue;

        if (dp[n][color]) return dp[n][color] = min(dp[n][color], set_dp(n-1, i)+cost[n][color]);
        else return dp[n][color] = set_dp(n-1, i)+cost[n][color];
    }
}