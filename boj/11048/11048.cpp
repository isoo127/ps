#include <iostream>
using namespace std;

int map[1002][1002];
int candy[1002][1002];

int main() {
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            candy[i][j] = map[i][j];
            if(candy[i-1][j] > candy[i][j-1]) candy[i][j] += candy[i-1][j];
            else candy[i][j] += candy[i][j-1];
        }
    }

    cout << candy[N][M];

    return 0;
}