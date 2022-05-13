#include <iostream>
using namespace std;

int map[9][9];

bool row_check[9][10] = { false,};
bool col_check[9][10] = { false,};
bool block_check[9][10] = { false,};

bool isValid(int i, int j, int num) {
    if (row_check[i][num] || col_check[j][num] || block_check[(i/3)*3+(j/3)][num]) return false;
    return true;
}

void backTracking(int idx);
void printNow(int i, int j) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c;
            cin >> c;

            int num = c-'0';
            map[i][j] = num;

            if (num > 0) {
                row_check[i][num] = true;
                col_check[j][num] = true;
                block_check[(i/3)*3+(j/3)][num] = true;
            }
        }
    }

    backTracking(0);

    return 0;
}

bool flag = false;

void backTracking(int idx) {

    int i = idx/9, j = idx%9;

    //printf("[idx = %d]\n", idx);
    //if (idx == 27) printNow(i, j);


    if (idx == 81) {
        flag = true;
        printNow(i, j);    
        return;
    }

    if (map[i][j]) {
        //printf("skip(idx=%d)\n", idx);
        backTracking(idx+1);
    }
    else {
    for (int num = 1; num <= 9; num++) {
        if (flag) return;

        if (isValid(i, j, num)) {
            map[i][j] = num;
            row_check[i][num] = true;
            col_check[j][num] = true;
            block_check[(i/3)*3+(j/3)][num] = true;

            backTracking(idx+1);
            
            block_check[(i/3)*3+(j/3)][num] = false;
            col_check[j][num] = false;
            row_check[i][num] = false;
            map[i][j] = 0;
                //if (map[3][0] == 0) printf("idx = %d, now!!!!!!!!1\n", idx);
        }
    }
    }
}