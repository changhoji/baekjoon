#include <iostream>
using namespace std;

struct trie {
    trie* childs[10];
    bool isEnd;
    trie() {
        for (int i = 0; i < 10; i++) {
            childs[i] = nullptr;
        }
        isEnd = false;
    }
    ~trie() {
        for (int i = 0; i < 10; i++) {
            if (childs[i] != nullptr) delete childs[i];
        }
    }

    bool insert(char* str) {
        if (*str == '\0') {
            if (isEnd == false) {
                isEnd = true;
                return true;
            }
            return false;
        }
        if (isEnd) return false;
        if (childs[*str-'0'] == nullptr) childs[*str-'0'] = new trie();
        childs[*str-'0']->insert(str+1);
    }
};

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        trie* nums = new trie();
        int n;
        cin >> n;

        bool flag = true;
        for (int i = 0; i < n; i++) {
            char str[11];
            cin >> str;
            if (!nums->insert(str)) {
                flag = false;
            }
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";

        delete nums;
    }

    return 0;
}