#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001] = { 0,};

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        
        dp[i] = max(dp[i-1]+num, num);
    }

    cout << *max_element(dp+1, dp+1+n) << '\n';

    return 0;
}
