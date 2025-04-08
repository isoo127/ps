#include <iostream>
#include <queue>
using namespace std;

int N;
int num[100000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    unsigned int idx = 0, tmp;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        if(!tmp) {
            if(q.empty()) num[idx++] = 0;
            else {
                num[idx++] = q.top();
                q.pop();
            }
        } else {
            q.push(tmp);
        }
    }

    for(int i = 0; i < idx; i++)
        cout << num[i] << "\n";

    return 0;
}