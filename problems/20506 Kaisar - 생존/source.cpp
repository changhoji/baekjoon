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

//tree의 한 정점에서 서브트리들의 정점 개수를 저장.
//dp[12] = 5, dp[2] = 5, dp[7] = 1
//dp[9] = 12
//조상이 9인 순서쌍의 개수: 1 + 2(5*5 + 5*1 + 1*5  +  )


//조상이 1인 순서쌍의 개수: 1 + 2(3*1 + 1*1 + 1*3) = 1 + 14 => 부모노드, 각각의 서브트리를 각각 하나로 보고 번갈아가면서 곱
//                          ->투포인터로 합 구하기!




