#include <iostream>
using namespace std;

int dp[50001];

int main() {
    for(int i = 1; i * i <= 50000; i++) {
        dp[i * i] = 1;
    }
    for(int i = 2; i <= 50000; i++) {
        if(!dp[i]) dp[i] = 5;
        else continue;
        for(int j = 1; j * j < i; j++) {
            int tmp = dp[i - j * j] + dp[j * j];
            if(tmp < dp[i]) dp[i] = tmp;
        }
    }

    int n; cin >> n;
    cout << dp[n];

    return 0;
}