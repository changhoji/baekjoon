#include <iostream>
#include <queue>
using namespace std;

struct pos {
    int row, col;
};

class baby_shark {
  private:
    int n;
    int area[20][20];
    int shark_size;
    int size_cnt;
    pos shark_pos;

    int pos_to_num(pos check_pos) { return area[check_pos.row][check_pos.col]; }
    bool is_valid_pos(pos check_pos);
    void eat_a_fish(pos eat_pos) {
        //printf("(%d, %d) -> (%d, %d)\n", shark_pos.row, shark_pos.col, eat_pos.row, eat_pos.col);
        shark_pos = eat_pos;
        area[eat_pos.row][eat_pos.col] = 0;

        size_cnt++;
        if (size_cnt == shark_size) {
            size_cnt = 0;
            shark_size++;
            //printf("size up!(%d)\n", shark_size);
        }
    }
    bool left_is_high_prio(pos pos1, pos pos2, int (&dist)[20][20]) {
        int dist1 = dist[pos1.row][pos1.col];
        int dist2 = dist[pos2.row][pos2.col];

        if (dist1 < dist2) return true;
        else if (dist1 > dist2) return false;
        else { //길이가 같으면
            if (pos1.row < pos2.row) return true;
            else if (pos1.row > pos2.row) return false;
            else {
                if (pos1.col < pos2.col) return true;
                else return false;
            }
        }
    }

  public:
    baby_shark();
    int eat_near_fish();
};
////////////////////////////////////////////////////

////////////////////////////////////////////////////
bool baby_shark::is_valid_pos(pos check_pos) {
    int row = check_pos.row;
    int col = check_pos.col;
    if (row < 0 || row >= n || col < 0 || col >= n)
        return false;
    if (pos_to_num(check_pos) > shark_size)
        return false;
    
    return true;
}

baby_shark::baby_shark() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
            if (area[i][j] == 9) {
                area[i][j] = 0;
                shark_pos = {i, j};
            }
        }
    }

    shark_size = 2;
    size_cnt = 0;
}

int baby_shark::eat_near_fish() {
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int visit_time[20][20];

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            visit_time[i][j] = -1;

    queue<pos> eatable_q;
    queue<pos> bfs_q; //<row, col>
    bfs_q.push(shark_pos);
    visit_time[shark_pos.row][shark_pos.col] = 0;
    int max_time = 0;
    int flag = 0;

    while(!bfs_q.empty()) {
        pos now_pos = bfs_q.front();
        bfs_q.pop();
        for (int k = 0; k < 4; k++) {
            pos new_pos = {now_pos.row + dy[k], now_pos.col + dx[k]};
            if(is_valid_pos(new_pos) && visit_time[new_pos.row][new_pos.col] == -1) {
                bfs_q.push(new_pos);
                visit_time[new_pos.row][new_pos.col] = visit_time[now_pos.row][now_pos.col] + 1;
                if (pos_to_num(new_pos) != 0 && pos_to_num(new_pos) < shark_size)
                    eatable_q.push(new_pos);
            }
        }
    }


    if (eatable_q.empty()) return 0; //먹을수 있는게 없으면

    pos eat_pos;
    eat_pos = eatable_q.front();
    if (shark_size == 5) {
        //printf("##---(%d, %d)에서 (%d, %d)까지 dist = %d---##\n", shark_pos.row, shark_pos.col, 
        //eat_pos.row, eat_pos.col, visit_time[eat_pos.row][eat_pos.col]);
    }
    eatable_q.pop();
    while(!eatable_q.empty()) {
        pos next_pos = eatable_q.front();
        if (left_is_high_prio(eat_pos, next_pos, visit_time) == false) //next_pos를 먼저 방문해야 하면
            eat_pos = next_pos;
        eatable_q.pop();
        if (shark_size == 5) {
        //printf("##---(%d, %d)에서 (%d, %d)까지 dist = %d---##\n", shark_pos.row, shark_pos.col, 
        //next_pos.row, next_pos.col, visit_time[next_pos.row][next_pos.col]);
        //printf("eat_pos = (%d, %d)\n", eat_pos.row, eat_pos.col);
        //printf("prio(bool) = %d\n", left_is_high_prio(eat_pos, next_pos, visit_time));
        }
        
    }

    eat_a_fish(eat_pos);

    //cout << "eat_pos = " << "(" << eat_pos.row << ", " << eat_pos.col << ")\n";

    return visit_time[eat_pos.row][eat_pos.col];
}
////////////////////////////////////////////////////

////////////////////////////////////////////////////
int main() {
    baby_shark bs;
    int max_time = 0;
    int cur_time;
    while (cur_time = bs.eat_near_fish()) {
        //cout << "cur_time = " << cur_time << endl << endl;
        max_time += cur_time;
    }
    
    cout << max_time << endl;
    return 0;
}