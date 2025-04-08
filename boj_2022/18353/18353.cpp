#include <iostream>
using namespace std;

int nums[2001];
int ans[2001];

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> nums[i];
    }
    int cnt = N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j) {
            if (nums[j] > nums[i])
                ans[i] = max(ans[i], ans[j] + 1);
            cnt = min(cnt, N - ans[i] - 1);
        }
    if (cnt == N) cout << 0;
    else cout << cnt;
    return 0;
}