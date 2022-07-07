#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int arr[100001];

int main() {
    int ans = INF;
    int N, S;
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;
    int sum = arr[0];

    while (right < N) {
        if (sum < S) {
            right++;
            sum += arr[right];
        }
        else {
            ans = min(ans, right-left+1);
            //printf("ans = %d, left = %d, right = %d\n", ans, left, right);
            if (left < right) {
                sum -= arr[left];
                left++;
            }
            else {
                right++;
                sum += arr[right];
            }
        }
    }

    if (ans == INF) cout << "0\n";
    else cout << ans << '\n';

    return 0;
}
