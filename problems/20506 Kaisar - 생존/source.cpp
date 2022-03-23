#include <iostream>
#include <vector>
using namespace std;


int parent[200001];
vector<int> childs[200001];
int dp[200001];

int dfs(int n);

int main() {
    int N;
    cin >> N;
    int root;

    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        if (!p) root = i;
        parent[i] = p;
        childs[p].push_back(i);
    }

    dfs(root);

    for (int i = 1; i <= N; i++) {
        printf("dp[%d] = %d\n", i, dp[i]);
    }

    return 0;

}

int dfs(int n) {
    dp[n] = 1;
    for (auto child: childs[n]) {
        dp[n] += dfs(child);
    }
    return dp[n];
}

//tree�� �� �������� ����Ʈ������ ���� ������ ����.
//dp[12] = 5, dp[2] = 5, dp[7] = 1
//dp[9] = 12
//������ 9�� �������� ����: 1 + 2(5*5 + 5*1 + 1*5  +  )


//������ 1�� �������� ����: 1 + 2(3*1 + 1*1 + 1*3) = 1 + 14 => �θ���, ������ ����Ʈ���� ���� �ϳ��� ���� �����ư��鼭 ��
//                          ->�������ͷ� �� ���ϱ�!




