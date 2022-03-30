#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

int ctoi(char c) {
    return c - '0';
}

vector<ll> nums;

struct operation{
    char op;
    int idx;
};
deque<operation> dq;

bool frontIsHigh();
int getPriority(char op);
ll evaluate(operation op);

int main() {
    string str;
    cin >> str;

    for (int i = 0; i < (int)str.size(); i++) {
        vector<int> term;

        bool isMinus = false;
        if (i == 0 && str[i] == '-') {
            isMinus = true;
            i++;
        }
        while (isdigit(str[i])) {
            term.push_back(ctoi(str[i]));
            i++;
        }        

        ll mul = 1;
        ll num = 0;
        for (auto iter = term.rbegin(); iter != term.rend(); iter++) {
            num += mul*(*iter);
            mul *= 10;
        }

        if (isMinus) nums.push_back(-num);
        else nums.push_back(num);

        if (i == str.size()) break;

        char op = str[i];
        dq.push_back({op, (int)nums.size()-1});
    }

    ll res = nums[0];
    while (!dq.empty()) {
        if (frontIsHigh()) {
            nums[dq.front().idx+1] = evaluate(dq.front());
            res = nums[dq.front().idx+1];
            dq.pop_front();
            //printf("true\n");
        }
        else {
            nums[dq.back().idx] = evaluate(dq.back());
            res = nums[dq.back().idx];
            dq.pop_back();
            //printf("false\n");
        }
    }

    cout << res << endl;

    return 0;
}

bool frontIsHigh() {
    operation op1 = dq.front();
    operation op2 = dq.back();

    //printf("op1.op = %c, op2.op = %c\n", op1.op, op2.op);
    if (getPriority(op1.op) > getPriority(op2.op)) return true; //2번조건
    else if (getPriority(op1.op) < getPriority(op2.op)) return false;
    
    if (evaluate(op1) > evaluate(op2)) return true; //3번조건
    else if (evaluate(op1) < evaluate(op2)) return false;

    return true;
}

int getPriority(char op) {
    if (op == '*' || op == '/') return 2;
    else return 1;
}

ll evaluate(operation op) {
    switch (op.op) {
        case '*':
            return nums[op.idx]*nums[op.idx+1];
        case '/':
            return nums[op.idx]/nums[op.idx+1];
        case '+':
            return nums[op.idx]+nums[op.idx+1];
        case '-':
            return nums[op.idx]-nums[op.idx+1];
    }
}