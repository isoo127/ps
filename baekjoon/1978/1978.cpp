#include <iostream>
#include <cmath>
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
    int num, x;
    cin >> num;

    int count = 0;
    for(int i = 0; i < num; i++) {
        cin >> x;
        if(isPrime(x))
            count++;
    }

    cout << count;

    return 0;
}