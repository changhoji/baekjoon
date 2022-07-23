#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int arr[41];

void set_vec(int left, int right, int idx, int sum, int cnt, vector<int>& v) {
    if (idx > right) {
        if (cnt > 0)
            v.push_back(sum);
        return;
    }

    set_vec(left, right, idx+1, sum, cnt, v); //수를 포함x일때
    sum += arr[idx];
    set_vec(left, right, idx+1, sum, cnt+1, v); //수를 포함할때
}

int main() {
    int N, S;
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<int> left_vec;
    vector<int> right_vec;

    set_vec(1, N/2, 1, 0, 0, left_vec);
    set_vec(N/2+1, N, N/2+1, 0, 0, right_vec);

    sort(left_vec.begin(), left_vec.end());
    sort(right_vec.begin(), right_vec.end());

    ll ans = 0;
    for (auto i: left_vec) {
        int cnt = upper_bound(right_vec.begin(), right_vec.end(), S-i) - lower_bound(right_vec.begin(), right_vec.end(), S-i);
        ans += cnt;
    }
    ans += upper_bound(left_vec.begin(), left_vec.end(), S) - lower_bound(left_vec.begin(), left_vec.end(), S);
    ans += upper_bound(right_vec.begin(), right_vec.end(), S) - lower_bound(right_vec.begin(), right_vec.end(), S);

    cout << ans << '\n';

    return 0;
}
