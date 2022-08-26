#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 10000 + 1;

bool isNotPrime[SIZE];

bool binary_search(int& s, int& e, int& m, const vector<int>& list, const int& x) {
    while(s <= e) {
            m = (s + e) / 2;
            if(list.at(m) > x)
                e = m - 1;
            else if(list.at(m) < x)
                s = m + 1;
            else
                return true;
    }
    return false;
}

int main() {
    vector<int> primes;
    for(int i = 2; i < SIZE; i++) {
        if(!isNotPrime[i]) {
            for(int j = i * 2; j <= SIZE; j += i) {
                isNotPrime[j] = true;
            }
            primes.push_back(i);
        }
    }

    int num, x;
    string result = "";
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> x;

        int s = 0, e = primes.size() - 1, m;
        bool isContain = binary_search(s, e, m, primes, x / 2);

        if(isContain) {
            result += to_string(primes.at(m)) + " " + to_string(primes.at(m)) + "\n";
        } else {
            while(true) {
                int p1 = primes.at(e);
                int p2 = x - p1;
                if(primes.end() != find(primes.begin(), primes.end(), p2)) {
                    result += to_string(p1) + " " + to_string(p2) + "\n";
                    break;
                }
                e--;
            }
        }
    }

    cout << result;

    return 0;
}