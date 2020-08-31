// https://www.acmicpc.net/problem/1647

//�ð�����  �޸�
//2 ��	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define MAX_SIZE 100001
using namespace std;

int root[MAX_SIZE];
int rankk[MAX_SIZE]; // Ʈ���� ���̸� ������ �迭
int N, M;

typedef struct ft {
    int from;
    int to;
    int cost;
}edge;

vector<edge> ed;

bool cmp(edge a, edge b) { return a.cost < b.cost; }

int findd(int x) {
    if (root[x] == x) return x;
    else return root[x] = findd(root[x]);
}

void uni(int x, int y) {
    x = findd(x);
    y = findd(y);

    if (x == y) return;

    if (rankk[x] < rankk[y]) {
        root[x] = y;
    }
    else {
        root[y] = x;

        if (rankk[x] == rankk[y])
            rankk[x]++;
    }
}

int main() {
    FAIO;

    for (int i = 0; i < MAX_SIZE; i++) {
        root[i] = i;
        rankk[i] = 0; // Ʈ���� ���� �ʱ�ȭ
    }

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edge tmp = { x,y,z };
        ed.push_back(tmp);
    }
    
    sort(ed.begin(), ed.end(), cmp);

    int sum = 0;
    int last = 0;
    for (auto v : ed) {
        if (findd(v.from) != findd(v.to)) {
            uni(v.from, v.to);
            sum += v.cost;
            last = v.cost;
        }
    }
    cout << sum - last;
    return 0;
}


/*
    Algorithm : Kruskal (minimum spanning tree)

    Time complexity : O(MlogN)

*/