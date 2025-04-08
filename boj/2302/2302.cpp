#include <iostream>
using namespace std;

int vip[40];
int nums[41];

void cal() {
    nums[0] = 1;
    nums[1] = 1;
    for(int i = 2; i <= 40; i++) {
        nums[i] = nums[i - 1] + nums[i + 1];
    }
}

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) cin >> vip[i];
    cal();
    long long int ans = 1;
    int cnt = 0;
    for(int i = 1, j = 0; i <= N; i++) {
        if(i == vip[j]) {
            ans *= nums[cnt]; j++; cnt = -1;
        }
        cnt++;
    }
    ans *= nums[cnt];
    cout << ans;
    return 0;
}