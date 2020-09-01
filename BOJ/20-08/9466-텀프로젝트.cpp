// https://www.acmicpc.net/problem/9466

//�ð�����  �޸�
//3 ��	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define MAX 100001

using namespace std;

int T, N;
bool visited[MAX];
int arrow[MAX];
int teamed[MAX];

void solve() {
    int tmp, i;
    for (int i = 1; i <= N ; i++) {
        if (visited[i]) continue;

        stack<int> s;
        tmp = i;        

        while (!visited[tmp]) {
            s.push(tmp);
            visited[tmp] = true;

            tmp = arrow[tmp];

            if (visited[tmp] == false) continue;  // �湮���� ���� ����� ��� ��� Ž��

            else if (teamed[tmp] == -1) {   // �湮�� ����� ���� �������� ���� ��带 ������ ��� ����Ŭ Ž��, ����Ŭ�� �ִ� ��� ������ �� ����
                while (!s.empty()) {                
                    //cout << s.top() << ' ';

                    if (tmp != s.top()) {
                        teamed[s.top()] = 1;
                        s.pop();
                    }
                        
                    else if (tmp == s.top()) {
                        teamed[s.top()] = 1;
                        s.pop();
                        while (!s.empty()) {
                            //cout << "   " << s.top() << ' ';
                            teamed[s.top()] = 0;
                            s.pop();
                        }
                    }
                                        
                }                
                //cout << el;
            }
            
            else if (teamed[tmp] > -1) { // �湮�� ����� ���� ������ ��带 ������ ��� ���ÿ� �ִ� ��� ����� ���� ����
                while (!s.empty()) {
                    //cout << s.top() << ' ';
                    
                    teamed[s.top()] = 0;
                    s.pop();
                }
                //cout << el;
                break;
            }
            
        }
    }
}

int main() {
    FAIO;

    int cnt = 0;

    cin >> T;
    for (int i = 0; i < T; i++) {
        memset(visited, false, sizeof(visited));
        memset(arrow, false, sizeof(arrow));
        memset(teamed, -1, sizeof(teamed));
        cnt = 0;

        cin >> N;
        for (int j = 1; j <= N; j++) {
            cin >> arrow[j];
        }


        solve();
        for (int i = 1; i <= N; i++) {
            if (teamed[i] == 0) {
                cnt++;
            }
        }
        
        cout<< cnt << el;
    }    

    return 0;
}


/*
    Algorithm : Stack

    Time complexity : O(N)

*/