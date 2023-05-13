#include <iostream>
using namespace std;

int info[301][301];
int dp[301][301];

int main() {
    int N, M; cin >> N >> M;;
    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= M; j++) 
            cin >> info[i][j];

    int ans = -1;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + info[i][j];
            if(ans < dp[i][j]) ans = dp[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}
