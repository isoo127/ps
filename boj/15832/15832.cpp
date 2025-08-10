#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        vector<int> vec;
        for (int i = 0; i < N; i++) vec.push_back(i + 1);
        int idx = 0;
        while (vec.size() != 1) {
            idx = (idx + M - 1) % vec.size();
            vec.erase(vec.begin() + idx);
        }
        cout << vec.front() << "\n";
    }

    return 0;
}