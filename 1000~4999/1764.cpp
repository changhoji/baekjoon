#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> hear;
vector<string> see;
vector<string> answer;

int main() {
    int n, m;
    cin >> n >> m;
    string temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        hear.push_back(temp);
    }
    sort(hear.begin(), hear.end());

    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (binary_search(hear.begin(), hear.end(), temp)) {//is_answer.
            answer.push_back(temp);
        }
    }
    
    sort(answer.begin(), answer.end());
    cout << answer.end() - answer.begin() << endl;
    for (int i = 0; i < answer.end() - answer.begin(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}