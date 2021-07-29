#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct comp {
    bool operator()(int num1, int num2) {
        if(abs(num1) > abs(num2)) return true; //오른쪽이 우선순위 높음
        else if (abs(num1) == abs(num2)) {
            if (num1 >= num2) return true;
            else return false;
        }
        else return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, comp> pq;
    int n, command;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command) pq.push(command);
        else {
            if(pq.empty()) cout << 0 << endl;
            else {
            cout << pq.top() << endl;
            pq.pop();
            }
        }
    }

    return 0;
}
