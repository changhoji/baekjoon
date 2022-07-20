#include <iostream>
using namespace std;
#define MOD 1'000'000'007

typedef long long ll;

class matrix {
public:
    ll num[2][2] = {{1, 1}, {1, 0}};
    matrix operator*(matrix b) {
        
    }
};

matrix operator*(matrix a, matrix b) {
    matrix res;
    res.num[0][0] = a.num[0][0]*b.num[0][0]%MOD; + a.num[0][1]*b.num[1][0];
}

matrix



matrix pow(int x) {
    
}

int main() {
    int n;
    cin >> n;

    
}