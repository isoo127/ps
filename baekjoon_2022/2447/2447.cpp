#include <iostream>
#include <string>
using namespace std;

string gap(int n) {
    string s = "";
    for(int i = 0; i < n; i++) {
        s += " ";
    }
    return s;
}

void square(int k, string s[]) {
    if(k == 1) {
        s[0] = "*";
        return;
    }

    square(k / 3, s);

    for(int i = k / 3; i < k; i++) {
        if(i < k / 3 * 2) {
            s[i] = s[i % (k / 3)] + gap(k / 3) + s[i % (k / 3)];
        } else {
            s[i] = s[i % (k / 3)] + s[i % (k / 3)] + s[i % (k / 3)];
        }
    }
    for(int i = 0; i < k / 3; i++) {
        s[i] = s[i] + s[i] + s[i];
    }
}

int main() {
    int k;
    cin >> k;
    string s[2187] = { };
    square(k, s);

    for(int i = 0; i < k; i++) {
        cout << s[i] << endl;
    }

    return 0;
}