#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    while (true) {
        getline(cin, str);
        if (str == ".") break;

        bool flag = true;
        stack<char> s;

        /*
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
        */
        for (char c: str) { //위 주석 두줄과 교체가능
            if (c == '(' || c == '[') s.push(c);    //여는 괄호일때
            if (c == ')') {                         //닫는 괄호일때
                if (s.empty() || s.top() != '(') {  //스택이 비어있거나 괄호매칭이 안되면
                    flag = false;
                    break;
                }
                else {                              //정상적
                    s.pop();
                }
            }
            if (c == ']') {                         //닫는 괄호일때
                if (s.empty() || s.top() != '[') {  //스택이 비어있거나 괄호매칭이 안되면
                    flag = false;
                    break;
                }
                else {                              //정상적
                    s.pop();
                }
            }
        }
        if (!s.empty()) flag = false;               //스택에 데이터가 남아있으면 오답

        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;

    }

    return 0;
}
