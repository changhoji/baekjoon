#include <stdio.h>
#include <vector>
using namespace std;

pair<int, int> dp[41];

int main() {
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    for (int i = 2; i <= 40; i++) {
        dp[i] = {dp[i-2].first + dp[i-1].first, dp[i-2].second + dp[i-1].second};
    }

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int num;
        scanf("%d", &num);
        printf("%d %d\n", dp[num].first, dp[num].second);
    }
    return 0;
}