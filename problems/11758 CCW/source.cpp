#include <iostream>
#include <tuple>
using namespace std;

int main() {
    int x1, x2, x3, y1, y2, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    tuple<int, int, int> v1 = make_tuple(x2-x1, y2-y1, 0);
    tuple<int, int, int> v2 = make_tuple(x3-x2, y3-y2, 0);

    int cross_value = (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);

    if (cross_value > 0) cout << "1\n";
    else if (cross_value == 0) cout << "0\n";
    else cout << "-1\n";

    return 0;
}