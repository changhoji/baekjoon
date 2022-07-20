#include <iostream>
#include <algorithm>
using namespace std;

int inorder[100001];
int inIdx[1000001];
int postorder[100001];

void printPreOrder(int inLeft, int inRight, int postLeft, int postRight);

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        inIdx[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }

    printPreOrder(1, n, 1, n);

    return 0;
    
}
/*
           2
        1     4
       3 5   6 7

       in:   3 1 5 2 6 4 7
       post: 3 5 1 6 7 4 2 
*/

void printPreOrder(int inLeft, int inRight, int postLeft, int postRight) {
    if (inLeft > inRight || postLeft > postRight) return;

    int rootIdx = inIdx[postorder[postRight]];
    int a = rootIdx - inLeft;
    int b = inRight - rootIdx;

    cout << inorder[rootIdx] << " ";

    printPreOrder(inLeft, rootIdx-1, postLeft, postLeft + a - 1);    
    printPreOrder(rootIdx+1, inRight, postLeft+a, postRight-1);
}