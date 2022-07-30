#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int a[41];

void set_bitmask(int left, int right, int idx, int sum, int bitmask, vector<pair<int, int>>& v) { //return: sum, bitmask
    if (idx > right) {
        v.push_back(make_pair(sum, bitmask));
        return;
    }

    set_bitmask(left, right, idx+1, sum, bitmask, v);
    int new_bitmask;
    if (left > 1) bitmask |= (1 << idx-(right/2));
    else bitmask |= (1 << idx);
    set_bitmask(left, right, idx+1, sum + a[idx], bitmask, v);
}

int main() {
    int n, K;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> K;

    vector<pair<int, int>> left_vec;
    vector<pair<int, int>> right_vec;

    set_bitmask(1, n/2, 1, 0, 0, left_vec);
    set_bitmask(n/2+1, n, n/2+1, 0, 0, right_vec);

    sort(right_vec.begin(), right_vec.end());

    for (auto p: left_vec) {
        //printf("p: %d %d\n", p.first, p.second);
        int lower_idx = lower_bound(right_vec.begin(), right_vec.end(), make_pair(K-p.first, 1), comp) - right_vec.begin();

        if (lower_idx == right_vec.size()) continue;

        if (p.first + right_vec[lower_idx].first == K) {
            for (int i = 1; i <= n/2; i++) cout << ((p.second & (1 << i)) ? 1 : 0);
            for (int i = 1; i <= n-n/2; i++) cout << ((right_vec[lower_idx].second & (1 << i)) ? 1 : 0);
            break;
        }
    }

    return 0;
}