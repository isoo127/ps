#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPrime(int x) {
    if(x < 2)
        return false;
    else {
        for(int i = 2; i <= sqrt(x); i++) {
            if(x % i == 0)
                return false;
        }
        return true;
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    string str = "";

    for(int i = M; i <= N; i++) {
        if(isPrime(i))
            str += to_string(i) + "\n";
    }

    cout << str;

    return 0;
}