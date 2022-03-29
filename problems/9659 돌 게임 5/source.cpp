#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    if (n % 2 == 0) cout << "CY" << endl;
    else cout << "SK" << endl;

    return 0;
}

//짝수개면 짝수번째에 가져가는 창영이가
//홀수개면 홀수번째에 가져가는 상근이가 이김