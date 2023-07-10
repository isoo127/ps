#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[100000][3];
int dp[2][3];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
            cin >> num[i][j];

    dp[0][0] = num[0][0];
    dp[0][1] = num[0][1];
    dp[0][2] = num[0][2];
    for(int i = 1; i < N; i++) {
        dp[i%2][0] = max(dp[(i+1)%2][0], dp[(i+1)%2][1]) + num[i][0];
        dp[i%2][1] = max({dp[(i+1)%2][0], dp[(i+1)%2][1], dp[(i+1)%2][2]}) + num[i][1];
        dp[i%2][2] = max(dp[(i+1)%2][1], dp[(i+1)%2][2]) + num[i][2];
    }

    cout << max({dp[(N-1)%2][0], dp[(N-1)%2][1], dp[(N-1)%2][2]}) << " ";

    dp[0][0] = num[0][0];
    dp[0][1] = num[0][1];
    dp[0][2] = num[0][2];
    for(int i = 1; i < N; i++) {
        dp[i%2][0] = min(dp[(i+1)%2][0], dp[(i+1)%2][1]) + num[i][0];
        dp[i%2][1] = min({dp[(i+1)%2][0], dp[(i+1)%2][1], dp[(i+1)%2][2]}) + num[i][1];
        dp[i%2][2] = min(dp[(i+1)%2][1], dp[(i+1)%2][2]) + num[i][2];
    }

    cout << min({dp[(N-1)%2][0], dp[(N-1)%2][1], dp[(N-1)%2][2]});
    
    return 0;
}