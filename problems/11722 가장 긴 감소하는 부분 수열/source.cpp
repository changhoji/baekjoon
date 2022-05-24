#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[1001];
    int dp[1001];

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1] = 1;
    for (int i = 2; i <= N; i++) { //now
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[i] < arr[j]) dp[i] = max(dp[j]+1, dp[i]);
        }
    }

    cout << *max_element(dp+1, dp+N+1) << '\n';

    return 0;
}