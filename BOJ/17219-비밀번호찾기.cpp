#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m; string input1, input2;
vector <pair<string, string> > list;

int search(int l, int r, string a) {
    int mid = (l + r) / 2; // �������� �߾����� ��´�.
    if (list[mid].first == a) return mid; // �������� ã�� �ּҰ� ������ �������� ��ȯ���ش�.

    return list[mid].first >= a ? search(l, mid, a) : search(mid + 1, r, a);
    // �迭�� �������� �ش��ϴ� �ּҺ��� ������ ����, ũ�� ������ ã�´�.
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input1 >> input2;
        list.push_back({ input1,input2 }); // �ּҿ� ��й�ȣ�� pair�� ���� ���Ϳ� �־��ش�.
    }
    sort(list.begin(), list.end()); // �迭�� ������������ �������ش�.

    for (int i = 0; i < m; i++) {
        cin >> input1;
        int x = search(0, n - 1, input1);
        cout << list[x].second << '\n';
    }
}