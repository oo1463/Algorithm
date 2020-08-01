#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 4000000
using namespace std;

vector<int> vec;

void getChe() {
    int i;
    int arr[MAX+1];

    for (i = 2; i <= MAX; i++) {
        arr[i] = i;
    }

    for (i = 2; i <= MAX; i++) {
        if (arr[i] == 0) // �̹� üũ�� ���� ����� Ȯ������ �ʴ´�
            continue;
        
        for (int j = i + i; j <= MAX; j += i) { // i�� ������ i�� ������� 0���� üũ
            arr[j] = 0;
        }
        vec.push_back(i);
    }
}

int main() {

    int N;

    cin >> N;

    getChe();

    int size = vec.size();
    int sum = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            sum += vec[j];
            if (sum == N) {
                count++;
                break;
            }
            else if (sum > N) break;
        }
        sum = 0;
    }

    cout << count;

    return 0;
}