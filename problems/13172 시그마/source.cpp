#include <iostream>
using namespace std;
#define MOD 1'000'000'007

typedef long long ll;

int GCD(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a%b) return GCD(b, a%b);
    else return b;
}

ll pow(ll n, ll x) {
    if (x == 0) return 1;
    else if (x == 1) return n;

    if (x % 2) return n*pow(n, x-1) % MOD;
    ll temp = pow(n, x/2);

    //cout << "리턴값: " << temp << '\n';

    return (temp*temp)%MOD;
}

int main() {
    ll M, N, S;;
    cin >> M;
    
    ll ans = 0;

    for (int i = 0; i < M; i++) {
        cin >> N >> S;

        int gcd = GCD(N, S);

        N /= gcd;
        S /= gcd;
        
        ans += S*pow(N, MOD-2);
        ans %= MOD;
    }
    ans %= MOD;
    cout << ans << '\n';

    return 0;
}