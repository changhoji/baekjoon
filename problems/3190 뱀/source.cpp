#include <stdio.h>
#include <queue>
using namespace std;

int n;
typedef struct {
    int row, col;
} pos;

void print_now_map();

int direction = 0; //0 : right, 1 : down, 2 : left, 3 : up
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, char>> rotate_pos; //지난시간, 방향
deque<pos> snake_pos; //위치의 행, 열

int next_map(pos next_pos);
int map[101][101] = { 0,};

int main() {
    int k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < k; i++) {
        int temp_row, temp_col;
        scanf("%d %d", &temp_row, &temp_col);
        map[temp_row][temp_col] = 1;
    } //map[][] = 1인 곳에 사과
    int l;
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        int temp_int;
        char temp_char;
        scanf("%d %c", &temp_int, &temp_char);
        rotate_pos.push({temp_int, temp_char});
    } //입력

    snake_pos.push_front({1, 1});
    map[1][1] = -1;

    int time = 0;
    while(1) {
        pos next_pos;
        //print_now_map();
        //printf("now_time = %d\n", time);
        
        if (rotate_pos.front().first == time) {
            if (rotate_pos.front().second == 'D') { //오른쪽으로 회전
                direction++;
                direction %= 4;
            }
            else {
                direction += 4;
                direction--;
                direction %= 4;
            }
            rotate_pos.pop();
        }
        //printf("direction = %d\n", direction);
        
        next_pos.row = snake_pos.front().row + dy[direction];
        next_pos.col = snake_pos.front().col + dx[direction]; //머리의 다음 좌표
        //printf("now_next_pos = (%d, %d)\n", next_pos.row, next_pos.col);

        int next_do = next_map(next_pos);
        if (next_do == -1) break; //게임 종료
        
        map[next_pos.row][next_pos.col] = -1;
        snake_pos.push_front(next_pos); //머리 변경

        if (next_do == 0) { //사과를 먹지 않았다면
            map[snake_pos.back().row][snake_pos.back().col] = 0; //-1에서 0으로 되돌림
            snake_pos.pop_back();
        }
        time++;
    }
    printf("%d\n", time+1);
    return 0;
}

int next_map(pos next_pos) {
    if (next_pos.row < 1 || next_pos.row > n || next_pos.col < 1 || next_pos.col > n) 
        return -1;
    return map[next_pos.row][next_pos.col];
} //못가면 -1, 갈수있으면 0, 갈수있고 사과가 있으면 1

void print_now_map() {
    printf("---------------------\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d", map[i][j]);
        }
        printf("\n");
    }
    printf("----------------------");
}