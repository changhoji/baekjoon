#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct paper {
    int num;
    int cnt;
    int sum;
};

struct pos {
    int row, col;
};

class tetromino {
    int n, m;
    paper **arr;
    bool is_valid_pos(pos location) {
        int row = location.row;
        int col = location.col;

        if (row < 0 || row >= n || col < 0 || col >= m)
            return false;
        if (member(location).cnt != -1) //이미 방문 했으면
            return false;
        
        return true;
    }
    paper& member(pos location) {
        return arr[location.row][location.col];
    }

  public:
    tetromino();
    ~tetromino();
    void reset_paper();
    int bfs_at_pos(pos location);
    int shape_u();
    int get_max_sum();
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
tetromino::tetromino() {
    cin >> n >> m;
    arr = new paper*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new paper[m];
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j].num;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////
void tetromino::reset_paper() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j].cnt = -1;
            arr[i][j].sum = 0;
        }
    }
}

int tetromino::bfs_at_pos(pos location) {
    reset_paper();
    int drow[] = {1, 0, -1, 0};
    int dcol[] = {0, 1, 0, -1};
    queue<pos> bfs_q;
    bfs_q.push(location);
    member(location).cnt = 1;
    member(location).sum = member(location).num;

    int max_sum = 0;
    while(!bfs_q.empty()) {
        pos cur_pos = bfs_q.front();
        bfs_q.pop();
        for (int k = 0; k < 4; k++) {
            pos new_pos = {cur_pos.row + drow[k], cur_pos.col + dcol[k]};
            if (is_valid_pos(new_pos) && member(cur_pos).cnt <= 3) {
                bfs_q.push(new_pos);
                member(new_pos).cnt = member(cur_pos).cnt + 1;
                member(new_pos).sum = member(cur_pos).sum + member(new_pos).num;
                if (member(new_pos).cnt == 4) {
                    if (max_sum < member(new_pos).sum)
                        max_sum = member(new_pos).sum;
                }
            }
        }
    }

    return max_sum;
}

int tetromino::shape_u() {
    int max_sum = 0;
    int cur_sum;
    int data[4];

    for (int row = 2; row < n; row++) {
        for (int col = 1; col < m; col++) {
            data[0] = arr[row-2][col-1].num;
            data[1] = arr[row-1][col-1].num;
            data[2] = arr[row][col-1].num;
            data[3] = arr[row-1][col].num;
            cur_sum = data[0] + data[1] + data[2] + data[3];
            max_sum = max(max_sum, cur_sum);

            data[0] = arr[row-2][col].num;
            data[2] = arr[row][col].num;
            cur_sum = data[0] + data[1] + data[2] + data[3];
            max_sum = max(max_sum, cur_sum);
        }
    }

    for (int row = 1; row < n; row++) {
        for (int col = 2; col < m; col++) {
            data[0] = arr[row-1][col-2].num;
            data[1] = arr[row-1][col-1].num;
            data[2] = arr[row-1][col].num;
            data[3] = arr[row][col-1].num;
            cur_sum = data[0] + data[1] + data[2] + data[3];
            max_sum = max(max_sum, cur_sum);

            data[0] = arr[row][col-2].num;
            data[2] = arr[row][col].num;
            cur_sum = data[0] + data[1] + data[2] + data[3];
            max_sum = max(max_sum, cur_sum);
        }
    }

    return max_sum;
}

int tetromino::get_max_sum() {
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            max_sum = max(max_sum, bfs_at_pos({i, j}));
        }
    }
    max_sum = max(max_sum, shape_u());
    return max_sum;
}
////////////////////////////////////////////////////////////////////////////////
tetromino::~tetromino() {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete arr;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
int main() {
    tetromino t;
    cout << t.get_max_sum();
    return 0;
}