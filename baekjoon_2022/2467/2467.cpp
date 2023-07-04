#include <iostream>
#define ll long long
#define MAX 2000000000
using namespace std;

int N;
ll val[100001];

struct pair1 {
    ll s;
    ll e;
    ll ev;
} typedef pair;

int eval(ll s, ll e) {
    ll tmp = s + e; 
    if(tmp < 0) tmp *= -1;
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> val[i];

    int s = 1, e = N;
    pair1 ans; ans.ev = MAX; ans.s = 1; ans.e = 1;
    while(s != e) {
        int t = val[s] + val[e];
        if(ans.ev > eval(val[s], val[e])) {
            ans.ev = eval(val[s], val[e]);
            ans.s = val[s]; ans.e = val[e];
        }
        if(t < 0) s++;
        else if(t > 0) e--;
        else break;
    }

    cout << ans.s << " " << ans.e;

    return 0;
}