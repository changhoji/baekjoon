#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int num[1000001];
int sorted[1000001];
//int answer[1000001] = { 0,};

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for (int i = 0; i < n; i++) {
        int answer = lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin();
        printf("%d ", answer);
    }

    //for (int i = 0; i < n; i++) printf("v[%d] = %d, sorted[%d] = %d\n", i, v[i], i, sorted[i]);

    return 0;
}
