#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int N;
    int num[100];
    cin >> N;

    int x;
    for(int i = 0; i < N; i++) {
        cin >> num[i];
        if(i == 1) {
            x = abs(num[0] - num[1]);
        } else if(i > 1) {
            x = gcd(x, abs(num[i] - num[i - 1]));
        }
    }

    string result = "";
    int i;
    for(i = 2; i * i < x; i++) if(x % i == 0) result += to_string(i) + " ";
    if(i * i == x) result += to_string(i) + " ";
    for(i -= 1; i > 0; i--) if(x % i == 0) result += to_string(x / i) + " ";

    cout << result;

    return 0;
}