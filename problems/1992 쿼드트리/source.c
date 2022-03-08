#include <stdio.h>

int Compression(int row, int col, int size);
void ShowQuadTree(int row, int col, int size);

char arr[65][65];

int main() {
    int n;
    scanf("%d", &n);
    char buf;
    buf = getchar();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = getchar();
        }
        buf = getchar();
    }

    ShowQuadTree(1, 1, n);

    return 0;
}

int Compression(int row, int col, int size) {
    
    if (size == 1)
        return arr[row][col]-'0';
    
    size /= 2;
    int div1 = Compression(row, col, size);
    int div2 = Compression(row, col+size, size);
    int div3 = Compression(row+size, col, size);
    int div4 = Compression(row+size, col+size, size);

    int combine;

    if (div1 == div2 && div2 == div3 && div3 == div4 && div4 == div1)
        combine = div1;
    else
        combine = -1;
    
    return combine;
}

void ShowQuadTree(int row, int col, int size) {
    int tok;
    if ((tok = Compression(row, col, size)) != -1) 
        printf("%d", tok);
    else {
        size /= 2;
        putchar('(');
        ShowQuadTree(row, col, size);
        ShowQuadTree(row, col+size, size);
        ShowQuadTree(row+size, col, size);
        ShowQuadTree(row+size, col+size, size);
        putchar(')');
    }
}