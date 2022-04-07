#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_happy[1000001]; //min_happy[i]: i년까지 최소행복
int max_happy[1000001]; //max_happy[i]: i년부터 최대행복
int max_tired[1000001]; //max_tired[i]: i년까지 최대피로
int min_tired[1000001]; //min_tired[i]: i년부터 최소피로

int main() {
    int N;
    cin >> N;

    vector<int> happy(N+1);
    vector<int> tired(N+1);  

    min_happy[0] = 1000000000;
    max_happy[0] = 0;
    max_tired[0] = 0;
    min_tired[0] = 1000000000;

    for (int i = 1; i <= N; i++) {
        int u, v;
        cin >> u >> v;

        happy[i] = u;
        
        tired[i] = v;
       
    }

    for (int i = 1; i <= N; i++) {
        if (happy[i] == 0) 1;
    }


}