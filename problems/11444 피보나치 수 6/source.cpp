#include <iostream>
using namespace std;
#define MOD 1'000'000'007

typedef long long ll;

class matrix {
public:
    ll num[2][2] = {{1, 1}, {1, 0}};

    matrix operator*(matrix b) {
        matrix res;
        res.num[0][0] = ((num[0][0]*b.num[0][0])%MOD + (num[0][1]*b.num[1][0])%MOD)%MOD;
        res.num[0][1] = ((num[0][0]*b.num[0][1])%MOD + (num[0][1]*b.num[1][1])%MOD)%MOD;
        res.num[1][0] = res.num[0][1];
        res.num[1][1] = ((num[1][0]*b.num[0][1])%MOD + (num[1][1]*b.num[1][1])%MOD)%MOD;

        return res;
    }
};

      
matrix pow(ll x) {
    matrix temp;
    if (x == 1) {
        return temp;
    }

    if (x%2) return temp*pow(--x);
    matrix half = pow(x/2);

    return half*half;
}

int main() {
    ll n;
    cin >> n;

    cout << pow(n).num[0][1]%MOD << '\n';

    return 0;
}