#include <iostream>
#include <vector>
#include <map>
using namespace std;

int wordCnt = 0;
vec

struct trie {
    int num;
    trie* childs[26];
    trie() {
        num = 0;
        for (int i = 0; i < 26; i++) {
            childs[i] = nullptr;
        }
    }
    ~trie() {
        for (int i = 0; i < 26; i++) {
            if (childs[i] != nullptr) delete childs[i];
        }
    }
    int insert(char* word) {
        if (*word == '\0') {
            if (num == 0) {
                num = wordCnt++;
            }
            return num;
        }
        if (childs[*word - 'A'] == nullptr) {
            childs[*word - 'A'] = new trie();
        }
        childs[*word - 'A']->insert(word+1);
    }
};

int main() {
    int n;
    cin >> n;
    trie* top = new trie();
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            char str[16];
            cin >> str;
            top->insert(str);
        }
    }

    

    return 0;
}