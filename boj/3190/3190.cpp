#include <iostream>
#include <queue>
using namespace std;

#define EMPTY 0
#define APPLE 1
#define SNAKE 2
#define LEFT 'L'
#define RIGHT 'D'

int map[101][101];
int bound;

int chgDir[100][2];
int cdIdx;

queue<pair<int, int>> snake;
int moves[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} }; // ruld
int dir;

int sec = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> bound;
    
    int n, x, y;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        map[x][y] = APPLE;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> c;
        chgDir[i][0] = x;
        chgDir[i][1] = c;
    }

    map[1][1] = SNAKE;
    snake.push(make_pair(1, 1));
    while (true) {
        sec++;

        x = snake.back().first + moves[dir][0];
        y = snake.back().second + moves[dir][1];

        if (map[x][y] == EMPTY) {
            if (x > bound || x < 1 || y > bound || y < 1) break;

            map[x][y] = SNAKE;
            snake.push(make_pair(x, y));
            map[snake.front().first][snake.front().second] = EMPTY;
            snake.pop();
        } else if (map[x][y] == APPLE) {
            map[x][y] = SNAKE;
            snake.push(make_pair(x, y));
        } else if (map[x][y] == SNAKE) {
            break;
        }

        if (chgDir[cdIdx][0] == sec) {
            if (chgDir[cdIdx][1] == LEFT) {
                dir++;
                if (dir == 4) dir = 0;
            }
            if (chgDir[cdIdx][1] == RIGHT) {
                dir--;
                if (dir == -1) dir = 3;
            }
            cdIdx++;
        }
    }

    cout << sec;
}