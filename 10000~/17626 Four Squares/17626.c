#include <stdio.h>

int dp[500001];

int main() {
    int n;
    dp[0] = 0;
    dp[1] = 1;
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++) { //dp를 차례대로 구하는 for문
    dp[i] = 4;
        for (int j = 1; j*j <= i; j++) { //i보다 j제곱이 크지 않게 돌리는 for문
            int temp = dp[j*j] + dp[i-j*j];
            if (j*j == i) temp = 1;
            if (dp[i] > temp) dp[i] = temp;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}