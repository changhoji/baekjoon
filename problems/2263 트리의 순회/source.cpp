#include <iostream>
#include <algorithm>
using namespace std;

int inorder[100001];
int inIdx[1000001];
int postorder[100001];

void printPreOrder(int root, int left, int right);

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

    for (int i = 1; i <= n; i++) {
        printf("inIdx[%d] = %d\n", i, inIdx[i]);
    }

    printPreOrder(postorder[n], 1, n);


    return 0;
    
}
/*
           2
        1     4
       3 5   6 7

       in:   3 1 5 2 6 4 7
       post: 3 5 1 6 7 4 2 
*/

void printPreOrder(int root, int left, int right) {
    //printf("root = %d, rootIdx = %d, left = %d, right = %d\n", root, inIdx[root], left, right);
    if (left == right) {
        printf("%d ", root);
        return;
    }
    int rootIdx = inIdx[root];
    
    printf("%d ", root);
    //if (rootIdx-1 >= left)
        printPreOrder(postorder[rootIdx-1], left, rootIdx-1);
    //if (rootIdx+1 <= right)
        printPreOrder(postorder[right-1], rootIdx+1, right);
}