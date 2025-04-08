#include <iostream>
#define max(a,b)  (((a) > (b)) ? (a) : (b))
using namespace std;

int tree[1000];
int ans[1000];

int solve(int loc, int T, int W) {
    if(!W) return 0;
    int ret = 0, i = T;
    for(;; i++) {
        if(loc == tree[i]) ret++;
        else break;
    }
    int change = (loc == 1) ? 2 : 1;
    if(W) ret += max(solve(change, i - 1, W - 1), solve(loc, i - 1, W));

    return ret;
}

int main() {
    int T, W; cin >> T >> W;
    for(int i = 0; i < T; i++) {
        cin >> tree[i];
    }
    cout << solve(1, 0, W);

    return 0;
}