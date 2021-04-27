#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

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

    return 0;
}
