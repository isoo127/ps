#include <iostream>
#define NON_BLIND 0
#define BLIND 1
using namespace std;

char map[102][102];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void RGB(int x, int y, int blind) {
    char color = map[x][y];
    if(color == 'G' && blind == NON_BLIND) {
        map[x][y] = 'R' + BLIND;
    } else {
        map[x][y] += BLIND;
    }
    for(int i = 0; i < 4; i++) {
        if(map[x + dx[i]][y + dy[i]] == color)
            RGB(x + dx[i], y + dy[i], blind);
    }
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(map[i][j] == 'R' || map[i][j] == 'G' || map[i][j] == 'B') {
                RGB(i, j, NON_BLIND); count++;
            }
        }
    }
    cout << count << " ";
    count = 0;
        for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(map[i][j] == 'R' + BLIND || map[i][j] == 'G' + BLIND || map[i][j] == 'B' + BLIND) {
                RGB(i, j, BLIND); count++;
            }
        }
    }
    cout << count;

    return 0;
}