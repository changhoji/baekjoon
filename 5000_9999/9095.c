#include <stdio.h>

int factorial(int x) {
    if (x == 1 || x == 0) return 1;
    else return x*factorial(x-1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int test_case = 0; test_case < n; test_case++) {
        int num;
        scanf("%d", &num);

        int cnt = 0;
        for (int one = 0; one <= 10; one++) {
            for (int two = 0; two <= 5; two++) {
                for (int three = 0; three <= 4; three++) {
                    if (one+two*2+three*3 == num) 
                        cnt += factorial(one+two+three)/(factorial(one)*factorial(two)*factorial(three));
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
