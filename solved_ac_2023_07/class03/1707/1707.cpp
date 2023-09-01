#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int K, V, E;
vector<int> edge[20001];
int node[20001];

void Bipartite(const int V, const int E) {
    for(int i = 0; i < E; i++) {
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    stack<int> s;
    for(int i = 1; i <= V; i++) {
        if(!node[i]) {
            s.push(i); node[i] = -1;
            while(!s.empty()) {
                int tmp = s.top(); s.pop();
                for(int j = 0; j < edge[tmp].size(); j++) {
                    if(!node[edge[tmp].at(j)]) {
                        s.push(edge[tmp].at(j));
                        node[edge[tmp].at(j)] = node[tmp] * -1;
                    } else {
                        if(node[edge[tmp].at(j)] != node[tmp] * -1) {
                            cout << "NO\n"; return;
                        }
                    }
                }
            }
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> K;

    for(int i = 0; i < K; i++) {
        cin >> V >> E;
        for(int j = 1; j <= V; j++) {
            edge[j].clear();
            node[j] = 0;
        }
        Bipartite(V, E);
    }

    return 0;
}