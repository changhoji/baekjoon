#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    n %= 7;

    switch (n) {
        case 1: //a:1
        case 3: //a:3
        case 4: //a:4
        case 5: //a:3 -> b:1 -> a:1
        case 6: //a:4 -> b:1 -> a:1
            cout << "SK" << endl;
            break;
        case 0:
        case 2: //a:1, b:1
            cout << "CY" << endl;
            break;
    }

    return 0;
}