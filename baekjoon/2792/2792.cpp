#include <iostream>
#define ll long long
using namespace std;

ll N, M;
ll cl[300001];

ll bs(ll min, ll max) {
    if(min >= max) return max;
    ll mid = (min + max) / 2;
    ll tmp = 0;
    for(ll i = 1; i <= M; i++) {
        int p = cl[i] / mid;
        int f = (cl[i] % mid != 0);
        tmp += p + f;
    }
    if(tmp > N) return bs(mid + 1, max);
    tmp = 0;
    for(ll i = 1; i <= M; i++) {
        int p = cl[i] / (mid - 1);
        int f = (cl[i] % (mid - 1) != 0);
        tmp += p + f;
    }
    if(tmp > N) return mid;
    else return bs(min, mid - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll max = 0;
    for(ll i = 1; i <= M; i++) {
        cin >> cl[i];
        if(max < cl[i]) max = cl[i];
    }

    cout << bs(1, max);

    return 0;
}