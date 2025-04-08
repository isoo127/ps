#include <iostream>
#include <stack>
using namespace std;

enum status { HORIZANTAL, VERTICAL, DIAGONAL };

int N;
int map[18][18];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int tmp; cin >> tmp;
            map[i][j] = !tmp;
        }
    }

    int ans = 0;
    stack<pair<pair<int, int>, status>> s;
    s.push(make_pair(make_pair(1, 2), HORIZANTAL));

    while(!s.empty()) {
        pair<pair<int, int>, status> tmp = s.top();
        // cout << tmp.first.first << ", " << tmp.first.second << ", " << tmp.second << endl;
        s.pop();
        if(tmp.first.first == N && tmp.first.second == N) {
            ans++; continue;
        }
        if(tmp.second == HORIZANTAL) {
            if(map[tmp.first.first][tmp.first.second + 1])
                s.push(make_pair(make_pair(tmp.first.first, tmp.first.second + 1), HORIZANTAL));
            if(map[tmp.first.first][tmp.first.second + 1] && map[tmp.first.first + 1][tmp.first.second] && map[tmp.first.first + 1][tmp.first.second + 1])
                s.push(make_pair(make_pair(tmp.first.first + 1, tmp.first.second + 1), DIAGONAL));
        } else if(tmp.second == VERTICAL) {
            if(map[tmp.first.first + 1][tmp.first.second])
                s.push(make_pair(make_pair(tmp.first.first + 1, tmp.first.second), VERTICAL));
            if(map[tmp.first.first][tmp.first.second + 1] && map[tmp.first.first + 1][tmp.first.second] && map[tmp.first.first + 1][tmp.first.second + 1])
                s.push(make_pair(make_pair(tmp.first.first + 1, tmp.first.second + 1), DIAGONAL));
        } else {
            if(map[tmp.first.first][tmp.first.second + 1])
                s.push(make_pair(make_pair(tmp.first.first, tmp.first.second + 1), HORIZANTAL));
            if(map[tmp.first.first + 1][tmp.first.second])
                s.push(make_pair(make_pair(tmp.first.first + 1, tmp.first.second), VERTICAL));
            if(map[tmp.first.first][tmp.first.second + 1] && map[tmp.first.first + 1][tmp.first.second] && map[tmp.first.first + 1][tmp.first.second + 1])
                s.push(make_pair(make_pair(tmp.first.first + 1, tmp.first.second + 1), DIAGONAL));
        }
    }

    cout << ans;

    return 0;
}