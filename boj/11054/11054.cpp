#include <iostream>
using namespace std;

int nums[1000];
int ans[2][1000];
int N;

int solve(int loc, int last, bool inc) {
    if(loc == N) return 0;
    if(inc && ans[0][loc]) return ans[0][loc];
    else if(!inc && ans[1][loc]) return ans[1][loc];

    int ret = 0, ret2 = 0, ret3;
    if(inc) {
        if(nums[loc] > last) ret = 1 + solve(loc + 1, nums[loc], inc);
        else ret2 = 1 + solve(loc + 1, nums[loc], !inc);
    } else {
        if(nums[loc] < last) ret = 1 + solve(loc + 1, nums[loc], inc);
    }
    ret3 = solve(loc + 1, last, inc);
    int tmp = (ret > ret2) ? ret : ret2;
    int a = (tmp > ret3) ? tmp : ret3;
    
    if(inc) ans[0][loc] = a;
    else ans[1][loc] = a;
    return a;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    cout << solve(0, 0, true);

    return 0;
}