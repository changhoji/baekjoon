#include <stdio.h>

int main() {
    int n;
    int cnt_two = 0;
    int cnt_five = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (!(i % 2)) {
            int temp = i;
            while (!(temp%2)) {
                cnt_two++;
                temp /= 2;
            }
        }
        if (!(i % 5)) {
            int temp = i;
            while (!(temp%5)) {
                cnt_five++;
                temp /= 5;
            }
        }
    }

    int answer = (cnt_two < cnt_five) ? cnt_two : cnt_five;

    printf("%d\n", answer);

    return 0;
}