#include <stdio.h>

typedef long long ll;

int main() {
    ll dp[1001];
    dp[1] = 1;
    dp[2] = 3;

    int n;
    scanf("%d", &n);

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
    }

    printf("%d\n", dp[n]);

    return 0;
}
