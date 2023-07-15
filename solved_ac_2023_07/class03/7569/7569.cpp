#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

int M, N, H;
int tm[102][102][102];
int dx[6][3] = { {-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1} };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N >> H;
    int tmp; 
    stack<tuple<int,int,int>> s[2];
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= M; k++) {
                cin >> tmp;
                if(tmp == -1) tm[i][j][k] = 0; // 빈 상자
                else if(tmp == 0) tm[i][j][k] = -1; // 익지 않은
                else if(tmp == 1) { 
                    tm[i][j][k] = 1; // 익은
                    s[0].push(make_tuple(i,j,k));
                }
            }
        }
    }

    int day = 0, change = 0, x, y, z;
    while(true) {
        change = 0;
        while(!s[day%2].empty()) {
            x = get<0>(s[day%2].top());
            y = get<1>(s[day%2].top());
            z = get<2>(s[day%2].top());
            //cout << x << ", " << y << ", " << z << " : " << endl;
            for(int i = 0; i < 6; i++) {
                if(tm[x + dx[i][0]][y + dx[i][1]][z + dx[i][2]] == -1) {
                    //cout << x + dx[i][0] << ", " << y + dx[i][1] << ", " << z + dx[i][2] << endl;
                    change = 1;
                    tm[x + dx[i][0]][y + dx[i][1]][z + dx[i][2]] = 1;
                    s[(day+1)%2].push(make_tuple(x + dx[i][0], y + dx[i][1], z + dx[i][2]));
                }
            }
            s[day%2].pop();
        }
        if(!change) break;
        day++;
        //cout << "day : " << day << endl << endl;
    }

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= M; k++) {
                //cout << tm[i][j][k] << " ";
                if(tm[i][j][k] == -1) {
                    cout << -1; return 0;
                }
            }
            //cout << endl;
        }
        //cout << endl << endl;
    }
    cout << day;

    return 0;
}