#include <iostream>
#include <queue>
using namespace std;

#define MAX_NUM 1000000000

int main() {
    int from, to;
    cin >> from >> to;

    int answer = -1;
    queue<pair<int, int>> q;
    q.push({from, 1});

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();


        if (cur.first == to) {
            answer = cur.second;
            break;
        }

        if (cur.first*2 <= MAX_NUM)
            q.push({cur.first*2, cur.second+1});
        if (cur.first <= 99999999)
            q.push({cur.first*10+1, cur.second+1});
    }

    cout << answer;

    return 0;
}