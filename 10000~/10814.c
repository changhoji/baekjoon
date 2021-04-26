#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    int num;
    char name[101];
} person;

person arr[100000];

int compare (const void *num1, const void *num2) {
    person a = *(person *)num1;
    person b = *(person *)num2;
    if (a.age > b.age) return 1;
    else if (a.age < b.age) return -1;
    else {
        if (a.num > b.num) return 1;
        else if (a.num < b.num) return -1;
        else return 0;
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &arr[i].age, arr[i].name);
        arr[i].num = i;
    }
    qsort(arr, n, sizeof(person), compare);
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }
    return 0;
}
