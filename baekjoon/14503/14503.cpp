#include <iostream>
using namespace std;

enum Direction {
    NORTH, EAST, SOUTH, WEST
};
enum Status {
    NOT_CLEAN, WALL, CLEAN
};

int map[50][50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int N, M; cin >> N >> M;
    int x, y, direction; cin >> x >> y >> direction;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    while(true) {
        if(map[x][y] == NOT_CLEAN) {
            map[x][y] = CLEAN; count++;
        }
        int flag = 0;
        for(int i = 0; i < 4; i++) {
            if(map[x + dx[i]][y + dy[i]] == NOT_CLEAN) {
                direction = (4 + ((direction - 1) % 4)) % 4;
                if(map[x + dx[direction]][y + dy[direction]] == NOT_CLEAN) {
                    x = x + dx[direction]; y = y + dy[direction];
                }
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        if(map[x + dx[(direction + 2) % 4]][y + dy[(direction + 2) % 4]] != WALL) {
            x = x + dx[(direction + 2) % 4]; y = y + dy[(direction + 2) % 4];
        } else {
            break;
        }
    }

    cout << count;

    return 0;
}