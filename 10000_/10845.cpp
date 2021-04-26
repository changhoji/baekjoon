#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

/*
void print_queue(queue<int> q) {
    printf("now queue : ");
    while (!q.empty()) {
        printf("%d ", q.front());
        q.pop();
    }
    printf("\n");
    return;
}*/

int main() {
    int n;
    queue<int> q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);

        if (!strcmp(command, "push")) {
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        else if (!strcmp(command, "pop")) {
            if (q.empty()) printf("-1\n");
            else {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (!strcmp(command, "size")) {
            if (q.empty()) printf("0\n");
            else printf("%d\n", q.size());
        }
        else if (!strcmp(command, "empty")) {
            if (q.empty()) printf("1\n");
            else printf("0\n");
        }
        else if (!strcmp(command, "front")) {
            if (q.empty()) printf("-1\n");
            else printf("%d\n", q.front());
        }
        else {
            if (q.empty()) printf("-1\n");
            else printf("%d\n", q.back());
        }
        //print_queue(q);
    }
    return 0;
}
