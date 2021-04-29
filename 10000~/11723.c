#include <stdio.h>
#include <string.h>

int main() {
    int arr[21] = { 0,};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);

        if (!strcmp(command, "add")) {
            int x;
            scanf("%d", &x);
            arr[x] = 1;
        }
        else if (!strcmp(command, "remove")) {
            int x;
            scanf("%d", &x);
            arr[x] = 0;
        }
        else if (!strcmp(command, "check")) {
            int x;
            scanf("%d", &x);
            if (arr[x]) printf("1\n");
            else printf("0\n");
        }
        else if (!strcmp(command, "toggle")) {
            int x;
            scanf("%d", &x);
            if (arr[x]) arr[x] = 0;
            else arr[x] = 1;
        }
        else if (!strcmp(command, "all")) {
            memset(arr+1, 1, 20*sizeof(int));
        }
        else {
            memset(arr+1, 0, 20*sizeof(int));
        }
    }
    return 0;
}