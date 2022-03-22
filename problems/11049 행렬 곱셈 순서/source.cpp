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
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = 1;
        }
    }

    for (int section_size = 1; section_size <= N-1; section_size++) {
        for (int left = 1; left <= N-section_size; left++) {
            int right = section_size + left;

            dp[left][right] = min(dp[left][right-1] + s[left].first*s[right].first*s[right].second,
                                  dp[left+1][right] + s[left].first*s[left].second*);
        }
    }

}

dp[i]: i번째까지 계산할때 연산수