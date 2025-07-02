#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<pair<int, string>> user;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int age; cin >> age;
        string name; cin >> name;
        user.push_back(make_pair(age, name));
    }

    stable_sort(user.begin(), user.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first < b.first;
    });

    for (const auto& u : user) {
        cout << u.first << " " << u.second << "\n";
    }

    return 0;
}