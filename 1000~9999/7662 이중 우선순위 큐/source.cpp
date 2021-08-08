#include <iostream>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test_case = 0; test_case < t; test_case++) {
        multiset<int> ms;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I')
                ms.insert(num);
            else {
                if (ms.empty())
                    continue;

                if (num == 1) {
                    auto iter = ms.end();
                    ms.erase(--iter);
                }
                else {
                    ms.erase(ms.begin());
                }
            }
        }

        if (ms.empty())
            cout << "EMPTY" << endl;
        else {
            auto iter = ms.end();
            iter--;
            cout << *iter << " " << *ms.begin() << endl;
        }
    }

    return 0;
}