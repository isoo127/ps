#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> v; int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp; v.push_back(tmp);
    }
    int ans = 0, i = N;
    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); it++) {
        ans += (*it) * (i--);
    }
    cout << ans;

    return 0;
}