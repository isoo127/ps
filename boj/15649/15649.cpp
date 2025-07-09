#include <bits/stdc++.h>
using namespace std;

int N, M;

void write(vector<int> a, vector<int> b) {
    if (N - b.size() == M) {
        for (int n : a)
            cout << n << ' ';
        cout << "\n";
        return;
    }

    for (int i = 0; i < b.size(); i++) {
        vector<int> a2 = a;
        vector<int> b2 = b;
        a2.push_back(b2[i]);
        b2.erase(b2.begin() + i);
        write(a2, b2);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N >> M;

    vector<int> a, b;
    for (int i = 1; i <= N; i++) {
        b.push_back(i);
    }
    write(a, b);

    return 0;
}