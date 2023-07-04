#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visit[101];
vector<int> link[101];

int main() {
    int n; cin >> n;
    int s, e; cin >> s >> e;
    int a; cin >> a;

    for(int i = 0; i < a; i++) {
        int x, y; cin >> x >> y;
        link[x].push_back(y);
        link[y].push_back(x);
    }

    queue<int> q;
    q.push(s);
    visit[s] = 1;

    while(!q.empty()) {
        vector<int>::iterator it = link[q.front()].begin();
        for(; it != link[q.front()].end(); it++) {
            if(!visit[*it]) {
                q.push(*it);
                visit[*it] = visit[q.front()] + 1;
            }
        }
        q.pop();
    }

    cout << visit[e] - 1;

    return 0;
}