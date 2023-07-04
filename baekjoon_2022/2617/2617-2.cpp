#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> l[100];
vector<int> h[100];
int cnt_l[100];
int cnt_h[100];

int DFS(int n, bool compLighter) {
    int s = compLighter ? l[n].size() : h[n].size();
    if(s == 0) return 0;
    
    int cnt = 0;
    stack<int> st; st.push(n);
    while(!st.empty()) {
        int num = st.top();
        st.pop();
        if(compLighter) {
            if(cnt_l[num] != n) {
                cnt_l[num] = n; cnt++;
                for(int i = 0; i < l[num].size(); i++) st.push(l[num].at(i));
            }
        } else {
            if(cnt_h[num] != n) {
                cnt_h[num] = n; cnt++;
                for(int i = 0; i < h[num].size(); i++) st.push(h[num].at(i));
            }
        }
    }
    
    return cnt - 1;
}

int main() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> v;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < v.size(); i++) {
        l[v.at(i).first].push_back(v.at(i).second);
        h[v.at(i).second].push_back(v.at(i).first);
    }

    int cnt = 0; int comp = (N-1)/2;
    for(int i = 1; i <= N; i++) {
        if(DFS(i, true) > comp || DFS(i, false) > comp) 
            cnt++;
    }
    cout << cnt;

    return 0;
}