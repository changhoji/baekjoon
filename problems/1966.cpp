#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int num;
    int importance;
} printer_queue;

int main() {
    int case_num;
    scanf("%d", &case_num);
    for (int i = 0; i < case_num; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        queue<printer_queue> q;
        for (int j = 0; j < n; j++) {
            int k;
            scanf("%d", &k);
            q.push({j, k});
        }
        
        int answer = 1;
        while (!q.empty()) {
            queue<printer_queue> temp_q = q;
            temp_q.pop();
            int now_importance = q.front().importance;
            int max_importance = 0;
            for (int l = 1; l < q.size(); l++) {
                if (temp_q.front().importance > max_importance)
                    max_importance = temp_q.front().importance;
                temp_q.pop();
            }
            if (max_importance > now_importance) {
                q.push(q.front());
                q.pop();
            }
            else {
                if (q.front().num == m) {
                    printf("%d\n", answer);
                    break;
                }
                q.pop();
                answer++;
            }
        }
    }

    return 0;
}
