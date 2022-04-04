#include <iostream>
using namespace std;

typedef long long ll;

ll dp[91][2] = { 0,};  
//dp[i][0]: 끝이 0인 i자리 이친수
//dp[i][1]: 끝이 1인 i자리 이친수

int main() {
    int N;
    cin >> N;

    dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[N][0] + dp[N][1] << endl;

    return 0;
}
