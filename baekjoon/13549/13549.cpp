#include <iostream>
#include <queue>
#define MAX_RANGE 100000
using namespace std;

int num[MAX_RANGE + 1];

int main() {
    int N, K; cin >> N >> K;

    queue<int> q;
    q.push(N);
    num[N] = 1;

    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(num[K] != 0 && num[x] > num[K]) continue;

        int n1 = x*2, n2 = x+1, n3 = x-1;
        if(n1 <= MAX_RANGE && (num[n1] == 0 || num[x] < num[n1]) && x < K) {
            num[n1] = num[x];
            q.push(n1);
        }
        if(n2 <= MAX_RANGE && (num[n2] == 0 || num[x] + 1 < num[n2]) && x < K) {
            num[n2] = num[x] + 1;
            q.push(n2);
        }
        if(n3 >= 0 && (num[n3] == 0 || num[x] + 1 < num[n3])) {
            num[n3] = num[x] + 1;
            q.push(n3);
        }
    }

    cout << num[K] - 1;

    return 0;
}