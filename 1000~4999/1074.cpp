#include <stdio.h>
#include <math.h>

int cnt = 0;
int r, c;

void search(int row, int col, int size);

int main() {
    int n;
    scanf("%d %d %d", &n, &r, &c);
    search(0, 0, pow(2,n));
    return 0;
}

void search(int row, int col, int size) {
    //printf("row = %d, col = %d, size = %d, cnt = %d\n", row, col, size, cnt);
    if (r == row && c == col) { //is answer
        printf("%d\n", cnt);
        return;
    }
    if (row <= r && r < row+size && col <= c && c < col+size) { //in this search
        search(row, col, size/2); //1
        search(row, col+size/2, size/2); //2
        search(row+size/2, col, size/2); //3
        search(row+size/2, col+size/2, size/2); //4
    }
    else cnt += size*size; //no in this search
}
