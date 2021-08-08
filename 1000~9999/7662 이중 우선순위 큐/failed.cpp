#include <iostream>
#include <queue>

const int DPQ_MAX = 1000001;

class dual_priority_queue {
    static int num_of_data;
    static int num_of_check;
    static bool is_deleted[DPQ_MAX];
    std::priority_queue<std::pair<int, int>> max_pq;
    std::priority_queue<std::pair<int, int>, 
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>> min_pq;

  public:
    dual_priority_queue() {}
    void insert_data(int data);
    void delete_data(int direct);
    int size() { return num_of_data; }
    int empty();
    int max() { return max_pq.top().first; }
    int min() { return min_pq.top().first; }

    ~dual_priority_queue() { 
        num_of_data = 0;
        num_of_check = 0;
        for (int i = 0; i < DPQ_MAX; i++)
            is_deleted[i] = false;
    }
};
int dual_priority_queue::num_of_data = 0;
int dual_priority_queue::num_of_check = 0;
bool dual_priority_queue::is_deleted[DPQ_MAX] = { false };

int dual_priority_queue::empty() {
    if (size() == 0)
        return 1;
    else
        return 0;
}

void dual_priority_queue::insert_data(int data) {
    min_pq.push({data, num_of_check});
    max_pq.push({data, num_of_check});
    num_of_data++;
    num_of_check++;
}

void dual_priority_queue::delete_data(int direct) {
    if (empty())
        return;

    if (direct == 1) {
        while (is_deleted[max_pq.top().second]) {
            max_pq.pop();
        }
        is_deleted[max_pq.top().second] = true;
        max_pq.pop();
    }
    else if (direct == -1) {
        while (is_deleted[min_pq.top().second]) {
            min_pq.pop();
        }
        is_deleted[min_pq.top().second] = true;
        min_pq.pop();
    }
    else
        return;

    num_of_data--;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    std::cin >> t;
    for (int test_case = 0; test_case < t; test_case++) {
        dual_priority_queue *dpq = new dual_priority_queue;
        int k;
        std::cin >> k;
        for (int i = 0; i < k; i++) {
            char op;
            int num;
            std::cin >> op >> num;

            if (op == 'I')
                dpq->insert_data(num);
            else
                dpq->delete_data(num);
        }
        if (dpq->empty())
            std::cout << "EMPTY" << std::endl;
        else
            std::cout << dpq->max() << " " << dpq->min() << std::endl;
        
        delete dpq;
    }
    return 0;
}