#include <iostream>
using namespace std;

int main() {
    int fixedCost, variable_cost, price;

    cin >> fixedCost >> variable_cost >> price;

    if (price <= variable_cost)
        cout << -1;
    else
        cout << fixedCost / (price - variable_cost) + 1;

    return 0;
}