#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, v;

    cin >> a >> b >> v;

    int days = ceil((v - b) / (a - b));
    cout << days;

    return 0;
}