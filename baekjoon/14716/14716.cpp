#include <iostream>
using namespace std;

int map[252][252];
int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,1,-1,-1,1};

void DFS(int x, int y) {
    map[x][y] = 0;
    for(int i = 0; i < 8; i++) {
        if(map[x + dx[i]][y + dy[i]]) 
            DFS(x + dx[i], y + dy[i]);
    }
}

int main() {
    int M, N; cin >> M >> N;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(map[i][j]) {
                DFS(i, j); count++;
            }
        }
    }
    cout << count;

    return 0;
}