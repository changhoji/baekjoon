#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000001];
int lis[1000001];

void print(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lis[i]);
    }
    printf("\n");
}

int main() {
    int N;
    cin >> N;

    int idx = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> arr[i];

        if (idx == 0) { //비어있으면 그냥 넣기
            lis[idx++] = arr[i];
        }
        else {
            if (lis[idx-1] < arr[i]) lis[idx++] = arr[i];
            else lis[lower_bound(lis, lis+idx, arr[i])-lis] = arr[i];
        }
        //print(idx);
    }
    
    cout << idx << '\n';;
}
