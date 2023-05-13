#include <iostream>
using namespace std;

int dp[1001];
int eat[1001];

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> eat[i];
    dp[1] = eat[1];
    int ans = eat[1];
    for(int i = 2; i <= N; i++) {
        dp[i] = eat[i];
        for(int j = 1; j < i; j++) {
            if(eat[j] < eat[i]) dp[i] = max(dp[i], dp[j] + eat[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}