#include <stdio.h>

int main() {
    int n, m;
    char board[50][51];
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    } //input
    
    int min = 64;
    for (int i = 0; i < n-7; i++) {
        for (int j = 0; j < m-7; j++) { //for brute_force
            int color = 0;
            int cnt = 0;
            for (int k = i; k < i+8; k++) {
                for (int l = j; l < j+8; l++) {
                    if (color % 2 && board[k][l] == 'W') cnt++;
                    if (!(color % 2) && board[k][l] == 'B') cnt++;
                    color++;
                }
                color--;
            }
            cnt = (cnt < 64-cnt) ? cnt : 64-cnt;
            if (min > cnt) min = cnt;
        }
    }
    printf("%d", min);
    return 0;
}
