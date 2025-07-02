#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    stack<int> s;

    cin >> K;
    for (int i = 0; i < K; i++) {
        int tmp; cin >> tmp;
        if (tmp == 0) s.pop();
        else s.push(tmp);
    }

    int result = 0;
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    cout << result;

    return 0;
}