#include <iostream>
#include <vector>
using namespace std;

vector<int> know;

int par[51];

int find(int a) {
    if (par[a] == a) return a;
    else return par[a] = find(par[a]);
}

void union_(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    par[aa] = bb;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }

    int knowCnt;
    cin >> knowCnt;
    for (int i = 0; i < knowCnt; i++) {
        int num;
        cin >> num;
        know.push_back(num);
    }

    vector<int> participant[50];

    for (int i = 0; i < M; i++) {
        int partySize;
        cin >> partySize;

        int before;

        for (int j = 0; j < partySize; j++) {
            int num;
            cin >> num;
            participant[i].push_back(num);

            if (j) 
                union_(before, num);
                
            before = num;         
        }
    }

    int cnt = 0;

    for (int i = 0; i < M; i++) {
        bool flag = false;
        for (auto j: participant[i]) {
            for (auto k: know) {
                if (find(j) == find(k)) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        //printf("\n");
        if (!flag) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}