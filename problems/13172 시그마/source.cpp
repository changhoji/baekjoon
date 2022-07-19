#include <iostream>
#include <cmath>
using namespace std;
#define MOD 1'000'000'007

typedef long long ll;

ll pow(ll n, ll x) {
    if (x == 0) return 1;
    else if (x == 1) return n;

    if (x % 2) return n*pow(n, x-1) % MOD;
    ll temp = pow(n, x/2);

    return (temp*temp)%MOD;
}

int main() {
    ll M, N, S;;
    cin >> M;
    
    ll ans = 0;

    for (int i = 0; i < M; i++) {
        cin >> N >> S;
        ans += (int)S*(int)pow(S, MOD-2)%MOD;
        ans %= MOD;
    }
    ans %= MOD;
    cout << ans << '\n';

    return 0;
}