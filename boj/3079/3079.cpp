#include <iostream>
#define ll long long
using namespace std;

ll N, M;
ll table[100001];

ll bs(ll min, ll max) {
    //cout << min << ", " << max << endl;
    if(min >= max) return max;
    ll mid = (min + max) / 2;
    ll tmp = 0;
    for(ll i = 1; i <= N; i++) {
        tmp += mid / table[i];
    }
    if(tmp < M) return bs(mid + 1, max);
    tmp = 0;
    for(ll i = 1; i <= N; i++) {
        tmp += (mid - 1) / table[i];
    }
    if(tmp >= M) return bs(min, mid - 1);
    else return mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll max = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> table[i];
        if(max < table[i]) max = table[i];
    }

    int tmp = M / N + 1;
    cout << bs(1, max * tmp);

    return 0;
}