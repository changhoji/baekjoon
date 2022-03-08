#include <stdio.h>

int max(int a, int b, int c);

int main() {
    int t, n;
    scanf("%d", &t);

    for (int tc = 0; tc < t; tc++) {
        scanf("%d", &n);

        int upper_score[100001] = { 0,};
        int lower_score[100001] = { 0,};

        int score;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &upper_score[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &lower_score[i]);
        }

        for (int i = 2; i <= n; i++) {
            upper_score[i] += max(lower_score[i-1], upper_score[i-2], lower_score[i-2]);
            lower_score[i] += max(upper_score[i-1], upper_score[i-2], lower_score[i-2]);
        }
        
        int max_score = upper_score[n-1];
        int temp = max(upper_score[n], lower_score[n-1], lower_score[n]);
        if (max_score < temp) max_score = temp;

        printf("%d\n", max_score);
    }

    return 0;

}

int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    else return c;
}