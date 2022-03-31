#include <iostream>
#include <stack>
using namespace std;

int NGE[1000001];
int num[1000001];

int main() {
    int N;
    cin >> N;
    
    
    for (int i = 1; i <= N; i++) {
        NGE[i] = -1;
        cin >> num[i];
    }

    stack<int> s; //first: idx, second: num

    for (int i = N; i > 0; i--) {
        while (!s.empty() && s.top() <= num[i]) {
            s.pop();
        }

        if (!s.empty()) {
            NGE[i] = s.top();
        }
        s.push(num[i]);
    }

    for (int i = 1; i <= N; i++) {
        cout << NGE[i] << " ";
    }
    cout << endl;

    return 0;
}
