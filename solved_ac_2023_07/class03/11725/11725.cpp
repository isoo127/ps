#include <iostream>
#include <queue>
using namespace std;

int N;
vector<int> node[100001];
int ans[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        node[a].push_back(b); node[b].push_back(a);
    }

    queue<int> q;
    q.push(1); ans[1] = -1;

    while(!q.empty()) {
        int tmp = q.front();
        for(int i = 0; i < node[tmp].size(); i++) {
            if(!ans[node[tmp].at(i)]) {
                ans[node[tmp].at(i)] = tmp;
                q.push(node[tmp].at(i));
            }
        }
        q.pop();
    }

    for(int i = 2; i <= N; i++) cout << ans[i] << "\n";

    return 0;
}