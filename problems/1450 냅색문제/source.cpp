#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a = 1'000'000'000;

typedef long long ll;

ll arr[31];

void set_vec(int left, int right, int idx, ll sum, vector<ll>& v) {
    if (idx > right) {
        v.push_back(sum);
        return;
    }

    set_vec(left, right, idx+1, sum, v); //수를 포함x일때
    sum += arr[idx];
    set_vec(left, right, idx+1, sum, v); //수를 포함할때
}

int main() {
    int N, C;
    cin >> N >> C;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<ll> left_vec;
    vector<ll> right_vec;

    set_vec(1, N/2, 1, 0, left_vec);
    set_vec(N/2+1, N, N/2+1, 0, right_vec);

    sort(left_vec.begin(), left_vec.end());
    sort(right_vec.begin(), right_vec.end());

    int ans = 0;
    for (auto i: left_vec) {
        ans += upper_bound(right_vec.begin(), right_vec.end(), C-i)-right_vec.begin();
    }

    cout << ans << '\n';

    return 0;
}
