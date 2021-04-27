#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n, command;
    scanf("%d", &n);
    for (int test_case = 0; test_case < n; test_case++) {
        scanf("%d", &command);
        if (command == 0) {
            if (min_heap.empty()) printf("0\n");
            else {
                printf("%d\n", min_heap.top());
                min_heap.pop();
            }
        }
        else {
            min_heap.push(command);
        }
    }
    return 0;
}