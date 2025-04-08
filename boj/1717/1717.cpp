#include <iostream>
#include <string>
using namespace std;

int n, m;
int u[1000001];

int findSet(int a) {
    if(u[a] == a) return a;
    return u[a] = findSet(u[a]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i <= n; i++) u[i] = i;
    for(int i = 0; i < m; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        int sa = findSet(a), sb = findSet(b);
        if(!x) { // 합집합
            if(a > b) u[sa] = sb;
            else u[sb] = sa;
        } else { // 같은 집합
            if(sa == sb) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}