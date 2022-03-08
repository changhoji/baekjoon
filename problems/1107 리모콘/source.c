//¹Ý·Ê: 40ÁÙ
#include <stdio.h>

int init_cnt(int num, int is_broken[]) {
    if (num == 0) {
        if (is_broken[0]) return -1;
        else return 1;
    }
        
    int div_num = 100000;
    while (num / div_num == 0) {
        div_num /= 10;
    }

    int cnt = 0;
    for (; div_num >= 1; div_num /= 10) {
        int a_num = num / div_num;
        num -= a_num * div_num;

        if (is_broken[a_num])
            return -1;
        
        cnt++;
    }
    return cnt;
}

int main() {
    int n, m;
    int is_broken[10] = { 0,};
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        is_broken[temp] = 1;
    }

    int min_cnt = (n > 100) ? (n-100) : (100-n);
    //for (int now_num = 0; now_num <= 2*n; now_num++) { ¹Ý·Ê: 0 1 0 -> Á¤´ä: 0, °á°ú: 100
    for (int now_num = 0; now_num <= 2*n+9; now_num++) { 
        int now_cnt = init_cnt(now_num, is_broken);
        if (now_cnt == -1) {
            continue;
        }

        now_cnt += (n > now_num) ? (n - now_num) : (now_num - n);
        if (min_cnt > now_cnt)
            min_cnt = now_cnt;
        
    }

    printf("%d\n", min_cnt);

    return 0;
}