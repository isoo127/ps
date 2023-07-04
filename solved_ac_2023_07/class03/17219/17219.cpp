#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    map<string, string> m;

    string url, pwd;
    for(int i = 0; i < N; i++) {
        cin >> url >> pwd;
        m.insert({url, pwd});
    }
    vector<string> v;
    for(int i = 0; i < M; i++) {
        cin >> url;
        v.push_back(url);
    }
    for(int i = 0; i < M; i++) {
        cout << m.find(v.at(i))->second << "\n";
    }

    return 0;
}