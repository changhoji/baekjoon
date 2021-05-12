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

    for (int k = 1; k <= n; k++) { //edge ����
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (edge[i][j] > edge[i][k] + edge[k][j]) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) { //farthest ����
        for (int j = 1; j <= n; j++) {
            if (edge[i][j] == INF) continue;
            if (farthest[i] < edge[i][j]) farthest[i] = edge[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!connected[i]) { //���� Ȯ�� �ȵǾ�����
            connected[i] = true; //����Ȱ����� ó���ϰ�
            int rep = i; //�켱 ��ǥ�� �ڱ� �ڽ����� ����
            for (int j = i; j <= n; j++) { //������ ������̱⶧���� �տ��� �ٽ� �� �ʿ�� ����
                if (edge[i][j] != INF) { //����Ǿ� ������
                    connected[j] = true;
                    if (farthest[rep] > farthest[j]) rep = j;
                } //����� ����� �ϳ��� ��忡�� ���� �ָ��ִ� �������� �Ÿ��� ���� ª���� ��ǥ�� ��
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