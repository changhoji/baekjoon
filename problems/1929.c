#include <stdio.h>
#include <math.h>
int prime_number[1000001];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    for (int i = 2; i <= n; i++) {
        prime_number[i] = i;
    }
    
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (prime_number[i]){ //if it is prime_number
            for (int j = i+1; j <= n; j++) {
                if (prime_number[j]%i == 0)
                    prime_number[j] = 0;
            }
        }
    }
    for (int i = m; i <= n; i++) {
        if (prime_number[i]) printf("%d\n", prime_number[i]);
    }

    return 0;
}
