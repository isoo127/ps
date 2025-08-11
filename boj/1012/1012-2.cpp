#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, M, N, K;

    cin >> T;
    for (int i = 0; i < T; i++) {
        int map[52][52] = { 0 };

        cin >> M >> N >> K;
        for (int j = 0; j < K; j++) {
            int a, b; cin >> a >> b;
            map[a + 1][b + 1] = 1;
        }

        int ans = 0;
        for (int x = 1; x <= M; x++) {
            for (int y = 1; y <= N; y++) {
                if (!map[x][y]) continue;

                queue<pair<int, int>> q;
                q.push(make_pair(x, y));
                map[x][y] = 0;
                while (!q.empty()) {
                    auto p = q.front();
                    if (map[p.first + 1][p.second]) q.push(make_pair(p.first + 1, p.second));
                    if (map[p.first - 1][p.second]) q.push(make_pair(p.first - 1, p.second));
                    if (map[p.first][p.second + 1]) q.push(make_pair(p.first, p.second + 1));
                    if (map[p.first][p.second - 1]) q.push(make_pair(p.first, p.second - 1));
                    map[p.first + 1][p.second] = 0;
                    map[p.first - 1][p.second] = 0;
                    map[p.first][p.second + 1] = 0;
                    map[p.first][p.second - 1] = 0;
                    q.pop();
                }

                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}