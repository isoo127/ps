#include <iostream>
#include <map>
using namespace std;

int ans[100];

int main() {
    int T; cin >> T;

    int n; map<string, int> m; string str;
    for(int i = 0; i < T; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> str >> str;
            auto it = m.find(str);
            if(it == m.end()) {
                m.insert({str, 1});
            } else {
                it->second += 1;
            }
        }
        n = 1;
        for(auto it = m.begin(); it != m.end(); it++) {
            n *= (it->second + 1);
        }
        ans[i] = n - 1;
        m.clear();
    }
    for(int i = 0; i < T; i++) cout << ans[i] << endl;

    return 0;
}