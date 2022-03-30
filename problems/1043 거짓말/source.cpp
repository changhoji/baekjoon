#include <iostream>
#include <vector>
using namespace std;

bool know[51] = { false,};
bool isPar[51] = { false,};

int par[51];

int find(int a) {
    if (par[a] == a) return a;
    else return par[a] = find(par[a]);
}

void union_(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    if (aa < bb) par[bb] = aa;
    else par[aa] = bb;
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
        know[num] = true;
    }

    for (int i = 0; i < M; i++) {
        int partySize;
        cin >> partySize;

        vector<int> participant;

        bool skip = false;
        for (int i = 0; i < partySize; i++) {
            int num;
            cin >> num;
            participant.push_back(num);
        }
        if (!skip) {
            for (int i = 1; i < participant.size(); i++) {
                union_(participant[0], participant[i]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        isPar[par[i]] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (know[i]) continue;
        if (isPar[i]) cnt++;
    }

    cout << cnt << endl;

    return 0;
}