#include <iostream>
using namespace std;

bool hasSequence(int x) {
    if(x >= 1 && x <= 99)
        return true;
    int n1 = x % 10;
    x = x / 10;
    int n2 = x % 10;
    x = x / 10;
    int diff = n2 - n1;
    int x1, x2 = n2;
    while(x != 0) {
        x1 = x % 10;
        if(diff != x1 - x2) {
            return false;
        }
        x2 = x1;
        x = x / 10;
    }
    return true;
}

int main() {
    int num;
    cin >> num;

    int cnt = 0;
    for(int i = 1; i <= num; i++) {
        if(hasSequence(i))
            cnt++;
    }
    cout << cnt;

    return 0;
}