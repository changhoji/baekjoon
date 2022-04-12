#include <iostream>
using namespace std;

#define DIV 1000000007

typedef long long ll;

void print();

ll arr[1000001];
ll seg[4000001];
bool isZero[4000001] = { false,};

ll makeSegTree(int node, int left, int right) {
    seg[node] = 1;
    if (left == right) return seg[node] = arr[left];

    int mid = (left + right) / 2;
    seg[node] *= (makeSegTree(2*node, left, mid) % DIV);
    seg[node] *= (makeSegTree(2*node+1, mid+1, right) % DIV);
    seg[node] %= DIV;

    return seg[node];
}

void updateSegTree(int node, int idx, int left, int right, ll num) {
    if (idx < left || idx > right) return;
    
    seg[node] = ((seg[node] / arr[idx]) * num) % DIV;

    if (left == right) return;

    int mid = (left + right) / 2;

    updateSegTree(node*2, idx, left, mid, num);
    updateSegTree(node*2+1, idx, mid+1, right, num);
}

void updateZero(int node, int idx, int left, int right, bool value) {
    //printf("node = %d, left = %d, right = %d, idx = %d\n", node, left, right, idx);
    if (idx < left || idx > right) return;
    
    isZero[node] = value;

    if (left == right) return;

    int mid = (left + right) / 2;
    
    updateZero(node*2, idx, left, mid, value);
    updateZero(node*2+1, idx, mid+1, right, value);
}

ll getFromSegTree(int node, int left, int right, int leftIdx, int rightIdx) {
    //printf("node = %d, left = %d, right = %d\n", node, left, right);
    if (rightIdx < left || right < leftIdx) return 1;
    if (leftIdx <= left && rightIdx >= right) return (isZero[node]) ? 0 : seg[node];

    int mid = (left+right)/2;
    return ((getFromSegTree(node*2, left, mid, leftIdx, rightIdx) % DIV) * (getFromSegTree(node*2+1, mid+1, right, leftIdx, rightIdx) % DIV)) % DIV;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    makeSegTree(1, 1, N);

    for (int i = 0; i < M+K; i++) {
        //print();
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            if (c == 0) {
                updateZero(1, b, 1, N, true);
            }
            else if (isZero[b] == 0 && c != 0) {
                updateZero(1, b, 1, N, false);
                updateSegTree(1, b, 1, N, c);
                arr[b] = c;
            }
            else {
                updateSegTree(1, b, 1, N, c);
                arr[b] = c;
            }
        }
        else {
            cout << getFromSegTree(1, 1, N, b, c) << '\n';
        }
    }

    return 0;
}

void print() {
    for (int i = 1; i <= 8; i++) {
        printf("seg[%d] = %lld, isZero[%d] = %d\n", i, seg[i], i, isZero[i]);
    }
}
