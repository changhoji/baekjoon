#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <cctype>
using namespace std;

string pokemon2[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<string, int> pokemon1;
    vector<string> pokemon2;
    pokemon2.push_back("1");
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        pokemon1[name] = i;
        pokemon2.push_back(name);
    }

    for (int i = 0; i < m; i++) {
        string command;
        char buf;
        cin >> command;
        if (isdigit(command[0])) {
            cout << pokemon2[atoi(command.c_str())] << '\n'; //string -> char*
        }
        else {
            cout << pokemon1[command] << '\n';
        }
    }

    return 0;
}
