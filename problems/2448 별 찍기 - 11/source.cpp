#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int arr[1024*3+1][1024*6+1] = { 0,};

void draw(int k, int r, int c);

int main() {
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int K = log2(N/3);

    draw(K, 1, 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 6*pow(2, K)-1; j++) {
            if (arr[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

}

void draw(int k, int r, int c) {
    //printf("k = %d, r = %d, c = %d\n", k, r, c);
    if (k == 0) {
        arr[r][c+2] = 1;
        arr[r+1][c+1] = 1;
        arr[r+1][c+3] = 1;
        for (int i = c; i <= c+4; i++) {
            arr[r+2][i] = 1;
        }
        return;
    }

    draw(k-1, r, c+3*pow(2, k-1));
    draw(k-1, r+3*pow(2, k-1), c);
    draw(k-1, r+3*pow(2, k-1), c+3*pow(2, k));
}
