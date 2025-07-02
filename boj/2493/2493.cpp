#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    stack<pair<int, int>> s;

    cin >> N; s.push(make_pair(0, INT32_MAX));
    for (int i = 1; i <= N; i++) {
        int tmp; cin >> tmp;

        if (s.top().second > tmp) {
            cout << s.top().first;
        } else {
            while(s.top().second <= tmp) {
                s.pop();
            }
            cout << s.top().first;
        }

        s.push(make_pair(i, tmp));
        cout << " ";
    }

    return 0;
}