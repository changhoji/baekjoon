#include <stdio.h> //used merge_sort by len and string
#include <stdlib.h>
#include <string.h>

typedef struct {
    char content[51];
    int len;
} word;

word words[20001];
word sorted[20001];

int compare(int first, int second) { //first >= second -> 1, first < second -> -1
    if (words[first].len > words[second].len) return 1;
    else if (words[first].len < words[second].len) return -1;
    else return strcmp(words[first].content, words[second].content);
}

void merge_sort(int start, int end);
void merge(int start, int mid, int end);

int main() { //main
    int n;
    scanf("%d", &n);
    int index = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i].content);
        words[i].len = strlen(words[i].content);
    }

    merge_sort(0, n-1);
    
    for (int i = 0; i < n; i++) {
        if (i != n && strcmp(words[i].content, words[i+1].content)) {
            printf("%s\n", words[i].content);
        }
    }
    return 0;
}

void merge_sort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, mid, end);
    }
}

void merge(int start, int mid, int end) {
    int i_first = start;
    int i_second = mid+1;
    int i_sorted = start;

    while (i_first <= mid && i_second <= end) {
        int temp = compare(i_first, i_second);
        if (temp >= 0) //first >= second -> need to change
            sorted[i_sorted++] = words[i_second++];
        else //first < second
            sorted[i_sorted++] = words[i_first++];
    }

    if (i_first > mid) //insert words[seconds]
        while (i_second <= end)
            sorted[i_sorted++] = words[i_second++];
    else
        while (i_first <= mid)
            sorted[i_sorted++] = words[i_first++];

    for (int i = start; i <= end; i++) { //overwrite sorted to words
        words[i] = sorted[i];
    }
}
