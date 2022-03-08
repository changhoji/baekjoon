#include <iostream>
using namespace std;

int n, m;
int num[500][500];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num[i][j];
        }
    }

    int max_sum = 0;
    int now_sum;

    //'ㅣ'모양
    for (int i = 3; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            now_sum = num[i-3][j] + num[i-2][j] + num[i-1][j] + num[i][j];
            if (max_sum < now_sum) max_sum = now_sum;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 3; j < m; j++) {
            now_sum = num[i][j-3] + num[i][j-2] + num[i][j-1] + num[i][j];
            if (max_sum < now_sum) max_sum = now_sum;
        }
    }

    //'ㅁ'모양
    for(int i = 1; i < n; i++) { 
        for (int j = 1; j < m; j++) {
            now_sum = num[i-1][j-1] + num[i-1][j] + num[i][j-1] + num[i][j];
            if (max_sum < now_sum) max_sum = now_sum;
        }
    }

    //'ㄴ'모양
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < m; j++) {
            now_sum = num[i-2][j-1] + num[i-1][j-1] + num[i][j-1] + num[i][j];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i-2][j] + num[i-1][j] + num[i][j] + num[i][j-1];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i-2][j-1] + num[i-2][j] + num[i-1][j] + num[i][j];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i-2][j] + num[i-2][j-1] + num[i-1][j-1] + num[i][j-1];
            if (max_sum < now_sum) max_sum = now_sum;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 2; j < m; j++) {
            now_sum = num[i-1][j-2] + num[i-1][j-1] + num[i-1][j] + num[i][j-2];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i][j-2] + num[i][j-1] + num[i][j] + num[i-1][j-2];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i-1][j] + num[i][j-2] + num[i][j-1] + num[i][j];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i][j] + num[i-1][j-2] + num[i-1][j-1] + num[i-1][j];
            if (max_sum < now_sum) max_sum = now_sum;
        }
    }

    //'ㅈ'모양
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < m; j++) {
            now_sum = num[i-2][j-1] + num[i-1][j-1] + num[i-1][j] + num[i][j];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i-2][j] + num[i-1][j] + num[i-1][j-1] + num[i][j-1];
            if (max_sum < now_sum) max_sum = now_sum;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 2; j < m; j++) {
            now_sum = num[i][j-2] + num[i][j-1] + num[i-1][j-1] + num[i-1][j];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i-1][j-2] + num[i-1][j-1] + num[i][j-1] + num[i][j];
            if (max_sum < now_sum) max_sum = now_sum;
        }
    }

    //'ㅏ'모양
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < m; j++) {
            now_sum = num[i-2][j-1] + num[i-1][j-1] + num[i][j-1] + num[i-1][j];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i-2][j] + num[i-1][j] + num[i][j] + num[i-1][j-1];
            if (max_sum < now_sum) max_sum = now_sum;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 2; j < m; j++) {
            now_sum = num[i-1][j-2] + num[i-1][j-1] + num[i-1][j] + num[i][j-1];
            if (max_sum < now_sum) max_sum = now_sum;
            now_sum = num[i][j-2] + num[i][j-1] + num[i][j] + num[i-1][j-1];
            if (max_sum < now_sum) max_sum = now_sum;
        }
    }

    cout << max_sum << endl;

    return 0;
}