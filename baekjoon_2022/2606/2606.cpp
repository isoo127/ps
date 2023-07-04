#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int computer[101];
vector<int> link[101];

int main() {
    int com_num; cin >> com_num;
    int link_num; cin >> link_num;

    for(int i = 0; i < link_num; i++) {
        int a, b; cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }

    int count = -1;
    queue<int> visit;
    visit.push(1);
    computer[1] = 1;

    while(!visit.empty()) {
        int t = visit.front(); 
        count++;
        
        vector<int>::iterator it = link[t].begin();
        for(; it != link[t].end(); it++) {
            if(!computer[*it]) {
                visit.push(*it);
                computer[*it] = 1; 
            }
        }

        visit.pop();
    }

    cout << count;

    return 0;
}