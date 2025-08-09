#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    int T; cin >> T;

    vector<int> ans;
    for (int i = 0; i < T; i++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) {
                if (r1 != 0) ans.push_back(-1);
                else ans.push_back(1);
            }
            else ans.push_back(0);
            continue;
        }

        long long l2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        long long plus2 = (r1 + r2) * (r1 + r2);
        long long minus2 = (r1 - r2) * (r1 - r2);
        if (l2 == plus2) ans.push_back(1);
        else if (l2 < plus2) {
            if (l2 == minus2) ans.push_back(1);
            else if (l2 < minus2) ans.push_back(0);
            else ans.push_back(2);
        } else ans.push_back(0);
    }

    for (int n: ans) {
        cout << n << "\n";
    }

    return 0;
}