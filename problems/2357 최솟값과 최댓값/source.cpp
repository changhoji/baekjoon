#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> initPair = {1000000001, 0};
pair<int, int> seg[400001]; //min, max
int arr[100001];

pair<int, int> makeSegTree(int node, int left, int right) {
    if (left == right) return seg[node] = make_pair(arr[left], arr[left]);

    int mid = (left + right) / 2;

    auto a = makeSegTree(node*2, left, mid);
    auto b = makeSegTree(node*2+1, mid+1, right);

    return seg[node] = make_pair(min(a.first, b.first), max(a.second, b.second));
}

pair<int, int> getFromSegTree(int node, int left, int right, int leftIdx, int rightIdx) {
    if (left > rightIdx || right < leftIdx) return initPair;
    if (leftIdx <= left && right <= rightIdx) return seg[node];

    int mid = (left + right) / 2;

    auto a = getFromSegTree(node*2, left, mid, leftIdx, rightIdx);
    auto b = getFromSegTree(node*2+1, mid+1, right, leftIdx, rightIdx);

    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

void print(int N);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    makeSegTree(1, 1, N);
    //print(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        auto res = getFromSegTree(1, 1, N, a, b);
        cout << res.first << " " << res.second << '\n';
    }

    return 0;
}

void print(int N) {
    for (int i = 1; i <= 25; i++) {
        printf("seg[%d] = (%d, %d)\n", i, seg[i].first, seg[i].second);
    }
    putchar('\n');
}