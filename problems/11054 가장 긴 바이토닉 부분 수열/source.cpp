#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001][2] = { 0,}; //0: increasing, 1: decreasing

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) { //i가 추가할 원소
        dp[i][0] = 1;
        dp[i][1] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
            else if (arr[i] < arr[j]) {
                dp[i][1] = max(dp[i][1], max(dp[j][0]+1, dp[j][1]+1));
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << '\n';

    return 0;
}
