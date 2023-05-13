#include <iostream>
using namespace std;

int rock[21][2];
int dp[21][2];

int main() {
    int N; cin >> N;
    for(int i = 1; i < N; i++) {
        cin >> rock[i][0] >> rock[i][1];
    }
    int k; cin >> k;

    for(int i = 0; i <= N; i++) {
        dp[i][0] = 1000000;
        dp[i][1] = 1000000;
    }
    dp[1][0] = 0;
    dp[2][0] = rock[1][0];
    dp[3][0] = min(rock[1][1], rock[1][0] + rock[2][0]);

    for(int i = 4; i <= N; i++) {
        dp[i][0] = min(dp[i-1][0] + rock[i-1][0], dp[i-2][0] + rock[i-2][1]);
        dp[i][1] = min(k + dp[i-3][0], min(dp[i-1][1] + rock[i-1][0], dp[i-2][1] + rock[i-2][1]));
    }

    cout << min(dp[N][0], dp[N][1]);

    return 0;
}