#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll arr[1000001];
ll seg[4000001] = { 0,};

ll makeSegTree(int node, int left, int right) {
    if (left == right) {
        seg[node] = arr[left];
        return seg[node];
    }

    int mid = (left+right)/2;
    seg[node] += makeSegTree(node*2, left, mid);
    seg[node] += makeSegTree(node*2+1, mid+1, right);

    return seg[node];
}

ll getSum(int node, int left, int right, int leftIdx, int rightIdx) {
    if (rightIdx < left || right < leftIdx) return 0;
    if (leftIdx <= left && rightIdx >= right) return seg[node];

    int mid = (left+right)/2;
    return getSum(node*2, left, mid, leftIdx, rightIdx) + getSum(node*2+1, mid+1, right, leftIdx, rightIdx);
}

void updateSegTree(int node, int left, int right, int idx, ll diff) {
    if (idx < left || idx > right) return;
    seg[node] += diff;

    if (left != right) {
        int mid = (left+right)/2;
        updateSegTree(node*2, left, mid, idx, diff);
        updateSegTree(node*2+1, mid+1, right, idx, diff);
    }
}

void printSeg() {
    printf("-------------\n");
    for (int i = 1; i <= 20; i++) {
        printf("seg[%d] = %d\n", i, seg[i]);
    }
    printf("-------------\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    makeSegTree(1, 1, N);
    //printSeg();

    for (int i = 0; i < M+K; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        if (a == 1) {
            updateSegTree(1, 1, N, b, c-arr[b]); //diff만큼 더해줘야함
            arr[b] = c;
        }
        else {
            cout << getSum(1, 1, N, b, c) << "\n";
        }
        //printSeg();
    }

    return 0;
}
