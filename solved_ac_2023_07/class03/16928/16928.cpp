#include <iostream>
#include <queue>
using namespace std;

int N, M;
int branch[106];
int node[106];
queue<pair<int, int>> q;
int ans = 99 / 6 + 1;

int main() {
    cin >> N >> M;
    for(int i = 1; i <= 100; i++) branch[i] = i;
    for(int i = 101; i <= 105; i++) branch[i] = 100;
    for(int i = 1; i <= 105; i++) node[i] = 1000;
    for(int i = 0; i < N + M; i++) {
        int s, e; cin >> s >> e;
        branch[s] = e;
    }
    q.push(make_pair(1, 0));

    while(!q.empty()) {
        //cout << q.front().first << " : " << q.front().second << endl;
        if(ans < q.front().second) {
            q.pop(); continue;
        }
        if(q.front().first == 100) {
            ans = q.front().second;
            q.pop(); continue;
        }
        for(int i = 1; i <= 6; i++) {
            if(q.front().second + 1 < node[branch[q.front().first + i]]) {
                q.push(make_pair(branch[q.front().first + i], q.front().second + 1));
                node[branch[q.front().first + i]] = q.front().second + 1;
            }
        }
        q.pop();
    }

    cout << ans;

    return 0;
}