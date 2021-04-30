#include <stdio.h>
#include <stack>
using namespace std;

int want_arr[100001];
char command[200000];
int num_in_arr[100001] = { 0,}; //0: not pushed, 1: pushed

int main() {
    stack<int> s;
    int n;
    int is_answer = 1;
    scanf("%d", &n);
    int cnt_command = 0;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &want_arr[i]);
    }

    int goal_index = 1;
    int push_num = 1;
    
    while (goal_index <= n) {
        if (num_in_arr[want_arr[goal_index]] == 0) {
            s.push(push_num);
            num_in_arr[push_num] = 1;
            push_num++;
            command[cnt_command++] = '+';
        }
        else if (num_in_arr[want_arr[goal_index]] == 1) {
            if (s.top() != want_arr[goal_index]) {
                is_answer = 0;
                break;
            }
            s.pop();
            goal_index++;
            command[cnt_command++] = '-';
        }
    }

    if (is_answer) {
        for (int i = 0; i < cnt_command; i++) {
            printf("%c\n", command[i]);
        }
    }
    else printf("NO\n");

    return 0;
}
