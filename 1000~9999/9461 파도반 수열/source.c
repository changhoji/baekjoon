#include <stdio.h>
//dp[i-1] + dp[i-5] = dp[i]
typedef long long ll;

ll dp[101];

int main() {
    int t;
    scanf("%d", &t);
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}