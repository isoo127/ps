#include <iostream>
#include <queue>
using namespace std;

int map[52][52];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int BFS(int M, int N, int K) {
    queue<pair<int, int>> coord;
    for(int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        coord.push(make_pair(x + 1, y + 1));
        map[x + 1][y + 1] = 1;
    }

    int count = 0;
    while(!coord.empty()) {
        int x = coord.front().first, y = coord.front().second;
        coord.pop();
        if(!map[x][y]) continue;

        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        map[x][y] = 0;
        while(!q.empty()) {
            int a = q.front().first, b = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                if(map[a + dx[i]][b + dy[i]]) {
                    q.push(make_pair(a + dx[i], b + dy[i]));
                    map[a + dx[i]][b + dy[i]] = 0;
                }
            }
        }
        count++;
    }
    return count;
}

int main() {
    int T; cin >> T;

    queue<int> ans;
    for(int i = 0; i < T; i++) {
        int M, N, K; cin >> M >> N >> K;
        ans.push(BFS(M, N, K));
    }
    while(!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop();
    }

    return 0;
}