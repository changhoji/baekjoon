#include <stdio.h>

typedef struct _bTreeNode {
    char data;
    int leftIdx;
    int rightIdx;
} BTNode;

void preorder_traversal(int idx);
void inorder_traversal(int idx);
void postorder_traversal(int idx);

BTNode node[26];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        node[i].data = 'A' + i;
        node[i].leftIdx = -1;
        node[i].rightIdx = -1;
    }

    char parent, left, right;
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c %c", &parent, &left, &right);
        parent -= 'A';
        if (left == '.')
            node[parent].leftIdx = -1;
        else
            node[parent].leftIdx = left - 'A';
        
        if (right == '.')
            node[parent].rightIdx = -1;
        else
            node[parent].rightIdx = right - 'A';
    }

    preorder_traversal(0);
    putchar('\n');
    inorder_traversal(0);
    putchar('\n');
    postorder_traversal(0);
    putchar('\n');

    return 0;
}

void preorder_traversal(int idx) {
    if (idx == -1) return;

    putchar(node[idx].data);
    preorder_traversal(node[idx].leftIdx);
    preorder_traversal(node[idx].rightIdx);
}

void inorder_traversal(int idx) {
    if (idx == -1) return;

    inorder_traversal(node[idx].leftIdx);
    putchar(node[idx].data);
    inorder_traversal(node[idx].rightIdx);
}

void postorder_traversal(int idx) {
    if (idx == -1) return;

    postorder_traversal(node[idx].leftIdx);
    postorder_traversal(node[idx].rightIdx);
    putchar(node[idx].data);
}