#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int in[20001] = { 0,};
        int out[20001] = { 0,};
        int n, m, s1, s2;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> s1 >> s2;
            out[s1]++;
            in[s2]++;
        }

        int noIn = 0;
        int noOut = 0;
        for (int i = 1; i <= n; i++) {
            if (!in[i]) noIn++;
            if (!out[i]) noOut++;
        }

        if (n == 1) cout << "0" << endl;
        else cout << max(noIn, noOut) << endl;
    }

    return 0;
}
