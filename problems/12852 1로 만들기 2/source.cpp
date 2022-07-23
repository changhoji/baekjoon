#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        dp[i] = i;
    }

    for (int i = 2; i <= N; i++) {
        if (!(i%2)) dp[i] = min(dp[i], dp[i/2]);
        if (!(i%3)) dp[i] = min(dp[i], dp[i/3]);
        dp[i] = min(dp[i], dp[i-1]);
        dp[i]++;
    }

    cout << dp[N]-1 << '\n';

    while (N) {
        cout << N << " ";
        if (!(N%2) && dp[N] == dp[N/2]+1) N /= 2;
        else if (!(N%3) && dp[N] == dp[N/3]+1) N /= 3;
        else N--;
    }

    return 0;
}
