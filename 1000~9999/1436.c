#include <stdio.h>
int main() {
    int cnt = 0, num = 665, n;
    scanf("%d", &n);
    
    while (cnt < n) {
        num++;
        int temp = num;
        int cnt_six = 0;
        int is_answer = 0;
        while (temp > 0) {
            if (temp%10 == 6) {
                cnt_six++;
            }
            else cnt_six = 0;
            if (cnt_six == 3) is_answer = 1;
            temp /= 10;
        }
        if (is_answer) cnt++;
    }

    printf("%d", num);
    return 0;
}
