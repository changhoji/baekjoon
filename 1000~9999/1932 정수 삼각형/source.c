#include <stdio.h>
int dp[501][501];
int num[501][501];

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }

    dp[1][1] = num[1][1];
    dp[2][1] = dp[1][1] + num[2][1];
    dp[2][2] = dp[1][1] + num[2][2];

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + num[i][j];
        }
    }
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < dp[n][i]) max = dp[n][i];
    }
    printf("%d\n", max);
    return 0;
}