#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    pair<int, int> s[501];
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        s[i] = make_pair(a, b);
    }

    int dp[501][501];


    for (int section_size = 1; section_size <= N-1; section_size++) {
        for (int left = 1; left <= N-section_size; left++) {
            int right = section_size + left;

            for (int connection = left; connection <= right; connection++) {
                if (connection == left) dp[left][right] = dp[left][connection] + dp[connection+1][right] + s[left].first*s[connection].second*s[right].second;
                else dp[left][right] = min(dp[left][right], dp[left][connection] + dp[connection+1][right] + s[left].first*s[connection].second*s[right].second);
            }
        }
    }

    cout << dp[1][N] << endl;

    return 0;
}

