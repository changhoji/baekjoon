#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int parent[200001];
vector<int> childs[200001];
ll dp[200001];
ll lcaCnt[200001];

int dfs(int n);

int main() {
    int N;
    cin >> N;
    int root;

    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        if (!p) root = i;
        parent[i] = p;
        childs[p].push_back(i);
    }

    dfs(root);

    ll cnt1 = 0;
    ll cnt2 = 0;

    ll untilCnt = 0;
    for (ll i = 1; i <= N; i++) {
        if (lcaCnt[i]%2 == 0) {
            cnt1 += i*(lcaCnt[i]/2);
            cnt2 += i*(lcaCnt[i]/2);
        }
        else {
            if (untilCnt%2 == 0) {
                cnt1 += i*(lcaCnt[i]/2+1);
                cnt2 += i*(lcaCnt[i]/2);
            }
            else {
                cnt1 += i*(lcaCnt[i]/2);
                cnt2 += i*(lcaCnt[i]/2+1);
            }
        }

        untilCnt += lcaCnt[i];
    }

    cout << cnt2 << " " << cnt1 << endl;

    return 0;

}

int dfs(int n) {
    dp[n] = 1;
    ll cnt = 0;
    for (auto child: childs[n]) {
        dp[n] += dfs(child);
        cnt -= dp[child]*dp[child];
    }
    cnt += dp[n]*dp[n];
    
    lcaCnt[n] = cnt;
    return dp[n];
}
