#include <iostream>
#define ll long long
using namespace std;

ll N, M;
ll tree[1000001];

ll bs(ll min, ll max) {
    if(min >= max) return max;
    ll mid = (min + max) / 2;
    ll tmp = 0;
    for(ll i = 0; i <= N; i++) {
        ll p = tree[i] - mid;
        if(p < 0) p = 0;
        tmp += p;
    }
    if(tmp < M) return bs(min, mid - 1);
    tmp = 0;
    for(ll i = 0; i <= N; i++) {
        ll p = tree[i] - mid - 1;
        if(p < 0) p = 0;
        tmp += p;
    }
    if(tmp < M) return mid;
    else return bs(mid + 1, max);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll max = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> tree[i];
        if(max < tree[i]) max = tree[i];
    }

    cout << bs(0, max);

    return 0;
}