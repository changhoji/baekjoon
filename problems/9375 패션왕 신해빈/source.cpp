#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        map<string, int> m;
        string buf, kind;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> buf >> kind;
            if (m.find(kind) == m.end()) { //데이터 없으면
                m[kind] = 1;
            }
            else {
                m[kind]++;
            }
        }

        int cnt = 1;
        for (auto iter: m) {
            cnt *= iter.second+1; //약수 구하는 것과 같은 방식
        }
        cnt--;
        cout << cnt << '\n';
    }
    return 0;
}
