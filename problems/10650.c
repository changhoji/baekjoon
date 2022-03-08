#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} coordinate;

int compare(const void *a, const void *b) {
    coordinate num1 = *(coordinate *)a;
    coordinate num2 = *(coordinate *)b;
    if (num1.x > num2.x) return 1;
    if (num1.x < num2.x) return -1;
    else {
        if (num1.y > num2.y) return 1;
        if (num1.y < num2.y) return -1;
        else return 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    coordinate arr[100000];
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, n, sizeof(coordinate), compare);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }

    return 0;
}