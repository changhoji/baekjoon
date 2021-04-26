#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* num1, const void* num2) {
    int a = *(int *)num1, b = *(int *)num2;
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

int main() {
    int n, arr[500000], many_arr[8001] = { 0,};
    int many;

    int sum = 0, min = 4000, max = -4000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        many_arr[arr[i]+4000]++;
    }
    qsort(arr, n, sizeof(int), compare);
    
    int mean = round((float)sum/(float)n);
    
    int many_max = 0;
    int is_second = 0;
    for (int i = 0; i <= 8000; i++) {
        if (many_arr[i] > many_max) {
            many_max = many_arr[i];
            is_second = 0;
            many = i-4000;
        }
        else if (many_arr[i] == many_max && !is_second) {
            is_second = 1;
            many = i-4000;
        }
    }

    printf("%d\n%d\n%d\n%d", mean, arr[(n-1)/2], many, arr[n-1]-arr[0]);
    return 0;
}