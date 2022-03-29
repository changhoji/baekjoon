#include <iostream>
#include <algorithm>
using namespace std;

int arr[8] = { 0,};
int cnt = 0;
int N, W, T, K;

void TimeFlow() {

}

void BackTracking(int t, int w) {
    int last[7];
    int onCnt = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i-1] > 0 && arr[i+1] > 0) last[i] = 1;
        else if (arr[i-1] > 0 || arr[i+1] > 0) last[i] = 2;
        else last[i] = 3;
    }
    for (int i = 1; i <= N; i++) {
        arr[i] -= last[i];
        if (arr[i] > 0) onCnt++;
    }

    if (onCnt < K) {
        for (int i = 1; i <= N; i++) {
            arr[i] += last[i];
        }
        return;
    }
    else if (t == T) {
        for (int i = 1; i <= N; i++) {
            arr[i] += last[i];
        }
        cnt++;
        return;
    }

    for (int i = max(1, w-1); i <= min(N, w+1); i++) {
        bool alreadyOff = (arr[i] <= 0);
        if (arr[i] > 0) arr[i]++;
        BackTracking(t+1, i);
        if (!alreadyOff) arr[i]--;
    }

    for (int i = 1; i <= N; i++) {
        arr[i] += last[i];
    }
}

int main() {
    cin >> N >> W >> T >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    BackTracking(1, W);

    cout << cnt << endl;
    
}