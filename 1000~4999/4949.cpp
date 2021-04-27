#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>
using namespace std;

int main() {

    char string[101] = "a";

    while (1) {
        stack<char> s;
        cin.getline(string, 101); //getline function
        if (!strcmp(string, ".")) break;
        int flag = 0;
        for (int i = 0; i < strlen(string); i++) {
            if (string[i] == '(') s.push('(');
            else if (string[i] == ')') {
                if (s.empty()) {
                    flag = 1;
                    break;
                }
                else if (s.top() !=  '(') {
                    flag = 1;
                    break;
                }
                else s.pop();
            }
            else if (string[i] == '[') s.push('[');
            else if (string[i] == ']') {
                if (s.empty()) {
                    flag = 1;
                    break;
                }
                else if (s.top() !=  '[') {
                    flag = 1;
                    break;
                }
                else s.pop();
            }
        }
        if (!flag && s.empty()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
