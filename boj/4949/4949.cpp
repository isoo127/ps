#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    while (getline(cin, str) && str != ".") {
        stack<char> stk;
        for (char c: str) {
            if (c == '(' || c == '[') {
                stk.push(c);
            } else if (c == ')') {
                if (stk.empty()) { stk.push('e'); break; }
                else if (stk.top() == '(') stk.pop();
                else break;
            } else if (c == ']') {
                if (stk.empty()) { stk.push('e'); break; }
                else if (stk.top() == '[') stk.pop();
                else break;
            }
        }
        if (stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}