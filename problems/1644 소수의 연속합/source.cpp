#include <iostream>
#include <vector>
using namespace std;

#define MAX 4000000

bool invalid[MAX+1] = { 0,};

int main() {
    vector<int> primes;
    invalid[1] = true;

    for (int i = 2; i <= MAX; i++) {
        if (invalid[i]) continue;
        for (int j = i*2; j <= MAX; j += i) {
            invalid[j] = true;
        }
        primes.push_back(i);
    }

    int N;
    cin >> N;
    
    int left = 0;
    int right = 0;

    int sum = 0;
    int ans = 0;

    while (1) {
        if (sum >= N) {
            sum -= primes[left++];
        }
        else if (right == primes.size()) break;
        else {
            sum += primes[right++];
        }

        if (sum == N) {
            ans++;
        }
    }

    cout << ans << '\n';



    return 0;
}
