#include <iostream>
using namespace std;

int N;

void recursion(int cnt) {
    for (int i = 0; i < 4*cnt; i++) {
        cout << '_';
    }
    cout << "\"����Լ��� ������?\"" << '\n';

    if (cnt != N) {
        for (int i = 0; i < 4*cnt; i++) {
            cout << '_';
        }
        cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";

        for (int i = 0; i < 4*cnt; i++) {
            cout << '_';
        }
        cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";

        for (int i = 0; i < 4*cnt; i++) {
            cout << '_';
        }
        cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

        recursion(cnt+1);
    }
    else {
        for (int i = 0; i < 4*cnt; i++) {
            cout << '_';
        }
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    }

    for (int i = 0; i < 4*cnt; i++) {
        cout << '_';
    }
    cout << "��� �亯�Ͽ���.\n";
}

int main() {
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    cin >> N;
    recursion(0);

    return 0;
}