#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        deque<int> deq;
        string p;
        int n;
        cin >> p;
        cin >> n;

        if (!n) {
            string buf;
            cin >> buf;
        }
        int cnt = 0;
        char tok;

        int num;
        while(cnt < n) { //n개 입력받을때까지
            tok = cin.get();
            if (tok == ',' || tok == ']') {
                deq.push_back(num);
                num = 0;
                cnt++;
            }
            else if (tok == '[') {
                num = 0;
                continue;
            }
            else {
                num *= 10;
                num += (tok - '0');
            }
            
        }
        cin.get(); //input

        int rotate = 0; //0: front, 1: back
        int error = 0;
        for (auto iter: p) {
            if (iter == 'R') {
                rotate += 1;
                rotate %= 2;
            }
            else {
                if (deq.empty()) {
                    error = 1;
                    break;
                }
                if (rotate == 0) 
                    deq.pop_front();
                else 
                    deq.pop_back();
            }
        } //명령어 수행하는 포문

        if (error) {
            cout << "error" << '\n';
            continue;
        } //에러시

        cout << '[';
        if (deq.empty()) { //에러는 아닌데 비어있으면
            cout << "]\n";
            continue;
        }
        while(1) {
            int data;
            if (!rotate) {
                data = deq.front();
                deq.pop_front();
            }
            else {
                data = deq.back();
                deq.pop_back();
            }
            cout << data;
            if (deq.empty()) {
                cout << ']';
                break;
            }
            cout << ',';
        }
        cout << '\n';
    }

    return 0;
}