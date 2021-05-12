#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int edge[101][101];
int farthest[101];
bool connected[101] = {false};
vector<int> answer;

int main() {
    for (int i = 0; i <= 101; i++)
        for (int j = 0; j <= 101; j++) {
            if (i == j) edge[i][j] = 0;
            else edge[i][j] = INF;
        }
    fill(farthest, farthest+101, 0);

    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) { //edge 갱신
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (edge[i][j] > edge[i][k] + edge[k][j]) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) { //farthest 갱신
        for (int j = 1; j <= n; j++) {
            if (edge[i][j] == INF) continue;
            if (farthest[i] < edge[i][j]) farthest[i] = edge[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!connected[i]) { //아직 확인 안되었으면
            connected[i] = true; //연결된것으로 처리하고
            int rep = i; //우선 대표를 자기 자신으로 설정
            for (int j = i; j <= n; j++) { //연결이 양방향이기때문에 앞에걸 다시 볼 필요는 없음
                if (edge[i][j] != INF) { //연결되어 있으면
                    connected[j] = true;
                    if (farthest[rep] > farthest[j]) rep = j;
                } //연결된 노드중 하나의 노드에서 가장 멀리있는 노드까지의 거리가 가장 짧은게 대표가 됨
            }
            answer.push_back(rep);
        }
    }

    sort(answer.begin(), answer.end());
    printf("%d\n", answer.size());
    for (int ans: answer) {
        printf("%d\n", ans);
    }
    return 0;
}