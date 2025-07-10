#include <bits/stdc++.h>
using namespace std;

int cache[100];

int main() {
    vector<pair<int, int>> lines;
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        lines.push_back(make_pair(a, b));
    }

    sort(lines.begin(), lines.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    cache[0] = 1;
    for (int i = 1; i < N; i++) {
        int max = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (lines[j].second < lines[i].second) {
                max = cache[j] > max ? cache[j] : max;
            }
        }
        cache[i] = max + 1;
    }

    int max = -1;
    for (int i = 0; i < N; i++) {
        max = cache[i] > max ? cache[i] : max;
    }
    cout << N - max;

    return 0;
}