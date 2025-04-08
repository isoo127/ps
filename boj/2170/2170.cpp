#include <bits/stdc++.h>
#define BIGGER(x, y) (x > y) ? x : y
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    vector<pair<int, int>> lines;
    int N; cin >> N;

    for(int i = 0; i < N; i++) {
        int st, end; cin >> st >> end;
        lines.push_back({st, end});
    }

    sort(lines.begin(), lines.end());
    
    int st = lines[0].first, end = lines[0].second, length = 0;
    for(int i = 1; i < N; i++) {
        if(end > lines[i].first) end = BIGGER(end, lines[i].second);
        else {
            length += (end - st);
            st = lines[i].first; end = lines[i].second;
        }
    }
    length += (end - st);
    cout << length;
    
    return 0;
}