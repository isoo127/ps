#include <iostream>
#include <set>
#include <string>
using namespace std;

int N, M;
set<string> listen;
set<string> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    string tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        listen.insert(tmp);
    }
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        if(listen.find(tmp) != listen.end()) {
            ans.insert(tmp);
        }
    }

    cout << ans.size() << "\n";
    for(auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << "\n";
    }

    return 0;
}