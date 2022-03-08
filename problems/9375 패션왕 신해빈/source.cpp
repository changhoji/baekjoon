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
            if (m.find(kind) == m.end()) { //������ ������
                m[kind] = 1;
            }
            else {
                m[kind]++;
            }
        }

        int cnt = 1;
        for (auto iter: m) {
            cnt *= iter.second+1; //��� ���ϴ� �Ͱ� ���� ���
        }
        cnt--;
        cout << cnt << '\n';
    }
    return 0;
}
