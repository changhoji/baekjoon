#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    bool flag = true;
    stack<char> s;

    for (auto c: str) {
        s.push(c);

        if (s.size() >= 4) {
            string temp;
            temp.resize(4);
            for (int i = 3; i >= 0; i--) {
                temp[i] = s.top();
                s.pop();
            }

            //cout << "temp: " << temp << endl;

            if (temp == "PPAP") s.push('P');
            else {
                //printf("else\n");
                for (int i = 0; i < 4; i++) {
                    s.push(temp[i]);
                }
            }
        }
    }

    if (s.size() == 1 && s.top() == 'P') cout << "PPAP" << endl;
    else cout << "NP" << endl;

    return 0;
}