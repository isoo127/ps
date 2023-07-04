#include <iostream>
using namespace std;

int num[1000001];

int solve(int n) {
    if(n == 1) return 0;
    if(num[n]) return num[n];

    int ans[3]; ans[0] = 1000002; ans[1] = 1000002; ans[2] = 1000002;
    if(!(n % 2)) ans[0] = solve(n / 2) + 1;
    if(!(n % 3)) ans[1] = solve(n / 3) + 1;
    ans[2] = solve(n - 1) + 1;
    //cout << n << " : " << ans[0] << " " << ans[1] << " " << ans[2] << endl;

    if(ans[0] < ans[1]) {
        if(ans[0] < ans[2]) {
            num[n] = ans[0];
            return ans[0];
        } else {
            num[n] = ans[2];
            return ans[2];
        } 
    } else {
        if(ans[1] < ans[2]) {
            num[n] = ans[1];
            return ans[1];
        } else {
            num[n] = ans[2];
            return ans[2];
        }
    }
}

int main() {
    int N; cin >> N;

    cout << solve(N);

    return 0;
}