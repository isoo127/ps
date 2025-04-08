#include <iostream>
#define ll long long
using namespace std;

ll rest[100];

int calculateRest(ll a, ll b, ll c) {
    if(b == 1) return a % c;
    ll x = a % c, i = 1, p = 0; 
    rest[p++] = x;

    while(i * 2 < b) {
        i *= 2;
        x = (x * x) % c;
        rest[p++] = x;
    }

    ll j = i;
    for(p -= 1; p >= 0; p--) {
        if(j + i <= b) {
            j += i;
            x = (x * rest[p]) % c;
        }
        i /= 2;
    }
    
    return x;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << calculateRest(a, b, c);

    return 0;
}