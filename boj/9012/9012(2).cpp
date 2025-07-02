#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    int s;

    cin >> T;
    for (int i = 0; i < T; i++) {
        string str; cin >> str;
        
        s = 0;
        for (auto& c : str) {
            if (c == '(') s++;
            else if (c == ')') s--;
            if (s < 0) break;
        }

        if (s == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}