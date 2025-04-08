#include <iostream>
#include <stack>
using namespace std;

int num[101];
int visit[101];

bool isReturn(int s) {
    int next = num[s];
    while(true) {
        if(next == s) return true;
        if(visit[next] != s) {
            visit[next] = s;
            next = num[next];
        } else break;
    }
    return false;
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    stack<int> ans;
    for(int i = N; i > 0; i--) {
        if(isReturn(i)) ans.push(i);
    }

    cout << ans.size() << endl;
    while(!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}