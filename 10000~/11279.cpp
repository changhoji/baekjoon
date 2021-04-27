#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int> max_heap;
    int n, command;
    scanf("%d", &n);
    for (int test_case = 0; test_case < n; test_case++) {
        scanf("%d", &command);
        if (command == 0) {
            if (max_heap.empty()) printf("0\n");
            else {
                printf("%d\n", max_heap.top());
                max_heap.pop();
            }
        }
        else {
            max_heap.push(command);
        }
    }
    return 0;
}