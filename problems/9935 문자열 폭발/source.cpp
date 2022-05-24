#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, bomb, a;
    cin >> str >> bomb;

    for (char c: str) {
        a.push_back(c);
        if (a.size() >= bomb.size()) {
            bool flag = true;
            for (int i = a.size()-bomb.size(), j = 0; j < bomb.size(); i++, j++) {
                if (a[i] != bomb[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (int i = 0; i < bomb.size(); i++) {
                    a.pop_back();
                }
            }
        }
    }

    if (!a.empty()) cout << a << '\n';
    else cout << "FRULA\n";
    
    
}