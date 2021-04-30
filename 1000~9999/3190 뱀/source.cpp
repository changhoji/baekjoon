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
queue<pair<int, char>> rotate_pos; //�����ð�, ����
deque<pos> snake_pos; //��ġ�� ��, ��

int next_map(pos next_pos);
int map[101][101] = { 0,};

int main() {
    int k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < k; i++) {
        int temp_row, temp_col;
        scanf("%d %d", &temp_row, &temp_col);
        map[temp_row][temp_col] = 1;
    } //map[][] = 1�� ���� ���
    int l;
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        int temp_int;
        char temp_char;
        scanf("%d %c", &temp_int, &temp_char);
        rotate_pos.push({temp_int, temp_char});
    } //�Է�

    snake_pos.push_front({1, 1});
    map[1][1] = -1;

    int time = 0;
    while(1) {
        pos next_pos;
        //print_now_map();
        //printf("now_time = %d\n", time);
        
        if (rotate_pos.front().first == time) {
            if (rotate_pos.front().second == 'D') { //���������� ȸ��
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
        next_pos.col = snake_pos.front().col + dx[direction]; //�Ӹ��� ���� ��ǥ
        //printf("now_next_pos = (%d, %d)\n", next_pos.row, next_pos.col);

        int next_do = next_map(next_pos);
        if (next_do == -1) break; //���� ����
        
        map[next_pos.row][next_pos.col] = -1;
        snake_pos.push_front(next_pos); //�Ӹ� ����

        if (next_do == 0) { //����� ���� �ʾҴٸ�
            map[snake_pos.back().row][snake_pos.back().col] = 0; //-1���� 0���� �ǵ���
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
} //������ -1, ���������� 0, �����ְ� ����� ������ 1

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