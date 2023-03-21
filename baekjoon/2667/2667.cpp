#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[27][27];
vector<pair<int, int>> s;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int DFS(int x, int y) {
    int count = 1;
    map[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        if(map[x + dx[i]][y + dy[i]]) {
            count += DFS(x + dx[i], y + dy[i]);
        }
    }
    return count;
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            char buf; cin >> buf;
            map[i][j] = (buf - '0');
            if(map[i][j]) s.push_back(make_pair(i, j));
        }
    }

    vector<int> ans;

    while(!s.empty()) {
        int x = s.back().first, y = s.back().second;
        s.pop_back();
        if(map[x][y]) ans.push_back(DFS(x, y));
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    vector<int>::iterator it = ans.begin();
    for(; it != ans.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}