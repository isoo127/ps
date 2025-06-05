#include <iostream>
#include <string>
#include <queue>

using namespace std;

string s[1000];

int main() {
    ios::sync_with_stdio(false);

    queue<string> A;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        A.push(str);
    }

    string a, b;
    int result = 0;
    int idx = 0;
    while (!A.empty()) {
        if (A.front() == s[idx]) {
            A.pop();
            idx++;
        } else {
            if (s[idx] == "x") {
                idx++; continue;
            }
            result++;
            for (int i = 0; i < N; i++) {
                if (s[i] == A.front()) {
                    s[i] = "x";
                }
            }
            A.pop();
        }
    }

    cout << result;
}